#ifndef GRPCTEXTCLIENT_H
#define GRPCTEXTCLIENT_H

#include "sample.pb.h"
#include "sample.grpc.pb.h"
#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include <string>

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;
class GrpcTextClient
{
public:
  GrpcTextClient();

  void  init(const std::string &ip, int port);

  std::string  sendData(const std::string msg);

private:
  std::shared_ptr<Channel>  _channel;
  CompletionQueue           _queue;
  Status                    _status;
  grpcTest::respond         _respond;
};

#endif // GRPCTEXTCLIENT_H
