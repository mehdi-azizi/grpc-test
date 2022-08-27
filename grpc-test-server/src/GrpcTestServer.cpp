#include "GrpcTestServer.h"
#include <grpcpp/completion_queue.h>
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

GrpcTestServer::GrpcTestServer():
  _responder(&_context)
{
}

GrpcTestServer::~GrpcTestServer()
{
  stop();
}

void  GrpcTestServer::readData()
{
  _service->RequestgetData(&_context, &_requestPkg,
                           &_responder, _queue.get(), _queue.get(), nullptr);
  void *tag;  // uniquely identifies a request.
  bool  ok;
  _queue->Next(&tag, &ok);
  std::string  prefix("Hello ");
  _respondPkg.set_message(prefix + _requestPkg.name());

  _responder.Finish(_respondPkg, Status::OK, this);
}

void  GrpcTestServer::start(const std::string &ip, int port)
{
  const auto &addr = ip + ":" + std::to_string(port);
  std::cout << addr << std::endl;
  {
    ServerBuilder  builder;
    int           *selected = nullptr;

    builder.AddListeningPort(addr, grpc::InsecureServerCredentials(), selected);
    _service = new grpcTest::GrpcTestService::AsyncService();

    builder.RegisterService(_service);
    _queue = builder.AddCompletionQueue();

    _server = builder.BuildAndStart();

    if ((nullptr != _server) && (nullptr != selected))
    {
      std::cout << "Server listening on " << addr << std::endl;
    }

    /// it should move to thread
    readData();

    std::cout << "Server listening on " << addr << std::endl;
  }
}

void  GrpcTestServer::stop()
{
  _server->Shutdown();
  _queue->Shutdown();   // Always *after* the associated server's Shutdown()!
  void *ignored_tag;
  bool  ignored_ok;

  while (_queue->Next(&ignored_tag, &ignored_ok))
  {
  }
}
