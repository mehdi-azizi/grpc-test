#include "Handler.h"
#include <qobject.h>
#include <qdebug.h>
#include <QString>
namespace GrpcTest
{
Handler::Handler(AsyncService         *service,
                 const ServerQueuePtr &queue):
  _status(GrpcTest::HS_CREATE),
  _service(service),
  _queue(queue),

  _responder(AsyncResponder(&_context))
{
  process();
}

Handler::~Handler()
{
  int  i = 0;

  i++;
}

HandlerStatus  Handler::process()
{
  switch (_status)
  {
  case GrpcTest::HS_CREATE:
  {
    _service->RequestgetData(&_context, &_requestPkg,
                             &_responder, _queue.get(), _queue.get(), this);
    _status = GrpcTest::HS_CALL;
  }
  break;
  case GrpcTest::HS_CALL:
  {
    doLogic();
    new Handler(_service, _queue);
    _responder.Finish(_respondPkg, Status::OK, this);
    _status = GrpcTest::HS_FINISH;
  }
  break;
  case GrpcTest::HS_FINISH:
    _status = GrpcTest::HS_DELETED;
    break;
  case GrpcTest::HS_DELETED:
    Q_ASSERT(1 == 0);
    break;
  }

  return _status;
}

void  Handler::doLogic()
{
  qDebug() << QString("client said :%1").
    arg(QString::fromStdString(_requestPkg.name()));
  std::string  prefix("You said :");

  _respondPkg.set_message(prefix + _requestPkg.name());
}
}
