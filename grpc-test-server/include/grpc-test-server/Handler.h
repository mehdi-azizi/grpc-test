#ifndef HANDLER_H
#define HANDLER_H
#include "sample.pb.h"
#include "sample.grpc.pb.h"

#include <grpcpp/grpcpp.h>

using namespace grpc;
using grpc::Status;
using AsyncService     = grpcTest::GrpcTestService::AsyncService;
using ServerQueuePtr   = std::shared_ptr<grpc::ServerCompletionQueue>;
using AsyncResponder   = grpc::ServerAsyncResponseWriter<grpcTest::respond>;
using ServerContextPtr = std::shared_ptr<ServerContext>;
namespace GrpcTest
{
enum HandlerStatus
{
  HS_CREATE,
  HS_CALL,
  HS_FINISH,
  HS_DELETED
};

class Handler final
{
public:
  Handler(AsyncService         *service,
          const ServerQueuePtr &queue);

  ~Handler();

  HandlerStatus  process();

  void  doLogic();

private:
  HandlerStatus      _status;
  AsyncService      *_service;
  ServerQueuePtr     _queue;
  ServerContext      _context;
  grpcTest::request  _requestPkg;
  grpcTest::respond  _respondPkg;
  AsyncResponder     _responder;
};
}
#endif // HANDLER_H
