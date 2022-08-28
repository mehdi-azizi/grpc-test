#ifndef GRPCTESTSERVER_H
#define GRPCTESTSERVER_H

#include "sample.pb.h"
#include "sample.grpc.pb.h"

#include <string>
#include <iostream>
#include <qthread.h>
#include <grpcpp/grpcpp.h>
using AsyncService   = grpcTest::GrpcTestService::AsyncService;
using ServerQueuePtr = std::shared_ptr<grpc::ServerCompletionQueue>;
using GrpcServerPtr  = std::unique_ptr<grpc::Server>;
using ThreadPtr      = std::unique_ptr<QThread>;
namespace GrpcTest
{
class Worker;
using WorkerPtr = std::unique_ptr<Worker>;

class GrpcTestServer final
{
public:
  GrpcTestServer();

  ~GrpcTestServer();

  bool  start();

  bool  start(const std::string &, int);

  void  restart();

  void  stop();

  std::string  getListenAddress() const;

  void  changeListenAddress(const std::string &listenAddress);

private:
  bool            _running;
  std::string     _listenAddress;
  GrpcServerPtr   _server;
  AsyncService   *_service;
  ServerQueuePtr  _queue;
  WorkerPtr       _worker;
  ThreadPtr       _thread;
};
}
#endif // GRPCTESTSERVER_H
