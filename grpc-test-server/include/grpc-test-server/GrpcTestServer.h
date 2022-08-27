#ifndef GRPCTESTSERVER_H
#define GRPCTESTSERVER_H

#include <string>
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "sample.pb.h"
#include "sample.grpc.pb.h"

class GrpcTestServer final
{
public:
  GrpcTestServer();

  ~GrpcTestServer();

  void  start(const std::string &, int);

  void  stop();

private:
  std::unique_ptr<grpc::Server>                       _server;
  std::unique_ptr<grpc::ServerCompletionQueue>        _queue;
  grpcTest::GrpcTestService::AsyncService            *_service;
  grpc::ServerContext                                 _context;
  grpcTest::request                                   _requestPkg;
  grpcTest::respond                                   _respondPkg;
  grpc::ServerAsyncResponseWriter<grpcTest::respond>  _responder;

  void  readData();
};

#endif // GRPCTESTSERVER_H
