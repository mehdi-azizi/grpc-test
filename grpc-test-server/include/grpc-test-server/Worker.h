#ifndef WORKER_H
#define WORKER_H

#include "sample.pb.h"
#include "sample.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <QObject>
#include <QThread>

using namespace grpc;
using grpc::Status;
using AsyncService   = grpcTest::GrpcTestService::AsyncService;
using ServerQueuePtr = std::shared_ptr<grpc::ServerCompletionQueue>;
using AsyncResponder = grpc::ServerAsyncResponseWriter<grpcTest::respond>;
namespace GrpcTest
{
class Worker final: public QObject
{
  Q_OBJECT

public:
  Worker(AsyncService         *service,
         const ServerQueuePtr &queue,
         QObject              *parent = nullptr);

  bool  isRunning() const;

public slots:
  void  run();

  void  stop();

signals:
  void  signalToRun();

private:
  bool            _running;
  AsyncService   *_service;
  ServerQueuePtr  _queue;
};
}
#endif // WORKER_H
