#include "GrpcTextClient.h"
using namespace   grpcTest;

GrpcTextClient::GrpcTextClient()
{
}

void  GrpcTextClient::init(const std::string &ip, int port)
{
  const auto &addr = ip + ":" + std::to_string(port);

  _channel = grpc::CreateChannel(addr, grpc::InsecureChannelCredentials());
  std::cout << "Starting client initilizing ..." << std::endl;
}

std::string  GrpcTextClient::sendData()
{
  auto     stub = GrpcTestService::NewStub(_channel);
  request  _request;

  _request.set_name("test");
  auto  rpc = stub->PrepareAsyncgetData(&_context, _request, &_queue);

  rpc->StartCall();
  rpc->Finish(&_respond, &_status, (void *)1);

  void *got_tag;
  bool  ok = false;
  // Block until the next result is available in the completion queue "cq".
  // The return value of Next should always be checked. This return value
  // tells us whether there is any kind of event or the cq_ is shutting down.
  GPR_ASSERT(_queue.Next(&got_tag, &ok));

  // Verify that the result from "cq" corresponds, by its tag, our previous
  // request.
  GPR_ASSERT(got_tag == (void *)1);
  // ... and that the request was completed successfully. Note that "ok"
  // corresponds solely to the request for updates introduced by Finish().
  GPR_ASSERT(ok);
  std::cout << "Sending data..." << std::endl;

  // Act upon the status of the actual RPC.
  if (_status.ok())
  {
    return ">>>>>>>>>>>>>>>>>>>>" + _respond.message();
  }
  else
  {
    return "RPC failed";
  }
}
