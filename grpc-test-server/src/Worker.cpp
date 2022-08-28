#include "Worker.h"
#include <grpcpp/completion_queue.h>
#include <Handler.h>
namespace GrpcTest
{
Worker::Worker(AsyncService         *service,
               const ServerQueuePtr &queue,
               QObject              *parent):
  QObject(parent),
  _running(false),
  _service(service),
  _queue(queue)
{
  Q_ASSERT(nullptr != service);
  connect(this, &Worker::signalToRun, this, &Worker::run);
}

void  Worker::run()
{
  _running = true;

  new Handler(_service, _queue);

  while (_running && !QThread::currentThread()->isInterruptionRequested())
  {
    void *tag;  // uniquely identifies a request.
    bool  ok;

    if (_queue->Next(&tag, &ok))
    {
      if (ok)
      {
        auto  tg = static_cast<Handler *>(tag);

        if (nullptr != tag)
        {
          auto  status = tg->process();

          if (GrpcTest::HS_DELETED == status)
          {
            delete tg;
          }
        }
        else
        {
          Q_ASSERT(1 == 0);
        }
      }
    }

// QThread::sleep(1);
  }
}

void  Worker::stop()
{
  _running = false;
}

bool  Worker::isRunning() const
{
  return _running;
}
}
