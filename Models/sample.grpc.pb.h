// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: sample.proto
#ifndef GRPC_sample_2eproto__INCLUDED
#define GRPC_sample_2eproto__INCLUDED

#include "sample.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpcTest {

// The test service definition.
class GrpcTestService final {
 public:
  static constexpr char const* service_full_name() {
    return "grpcTest.GrpcTestService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Sends a data
    virtual ::grpc::Status getData(::grpc::ClientContext* context, const ::grpcTest::request& request, ::grpcTest::respond* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcTest::respond>> AsyncgetData(::grpc::ClientContext* context, const ::grpcTest::request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcTest::respond>>(AsyncgetDataRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcTest::respond>> PrepareAsyncgetData(::grpc::ClientContext* context, const ::grpcTest::request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::grpcTest::respond>>(PrepareAsyncgetDataRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      // Sends a data
      virtual void getData(::grpc::ClientContext* context, const ::grpcTest::request* request, ::grpcTest::respond* response, std::function<void(::grpc::Status)>) = 0;
      virtual void getData(::grpc::ClientContext* context, const ::grpcTest::request* request, ::grpcTest::respond* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::grpcTest::respond>* AsyncgetDataRaw(::grpc::ClientContext* context, const ::grpcTest::request& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::grpcTest::respond>* PrepareAsyncgetDataRaw(::grpc::ClientContext* context, const ::grpcTest::request& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status getData(::grpc::ClientContext* context, const ::grpcTest::request& request, ::grpcTest::respond* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcTest::respond>> AsyncgetData(::grpc::ClientContext* context, const ::grpcTest::request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcTest::respond>>(AsyncgetDataRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcTest::respond>> PrepareAsyncgetData(::grpc::ClientContext* context, const ::grpcTest::request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::grpcTest::respond>>(PrepareAsyncgetDataRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void getData(::grpc::ClientContext* context, const ::grpcTest::request* request, ::grpcTest::respond* response, std::function<void(::grpc::Status)>) override;
      void getData(::grpc::ClientContext* context, const ::grpcTest::request* request, ::grpcTest::respond* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::grpcTest::respond>* AsyncgetDataRaw(::grpc::ClientContext* context, const ::grpcTest::request& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::grpcTest::respond>* PrepareAsyncgetDataRaw(::grpc::ClientContext* context, const ::grpcTest::request& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_getData_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Sends a data
    virtual ::grpc::Status getData(::grpc::ServerContext* context, const ::grpcTest::request* request, ::grpcTest::respond* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_getData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_getData() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_getData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getData(::grpc::ServerContext* /*context*/, const ::grpcTest::request* /*request*/, ::grpcTest::respond* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestgetData(::grpc::ServerContext* context, ::grpcTest::request* request, ::grpc::ServerAsyncResponseWriter< ::grpcTest::respond>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_getData<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_getData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_getData() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpcTest::request, ::grpcTest::respond>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpcTest::request* request, ::grpcTest::respond* response) { return this->getData(context, request, response); }));}
    void SetMessageAllocatorFor_getData(
        ::grpc::MessageAllocator< ::grpcTest::request, ::grpcTest::respond>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::grpcTest::request, ::grpcTest::respond>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_getData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getData(::grpc::ServerContext* /*context*/, const ::grpcTest::request* /*request*/, ::grpcTest::respond* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* getData(
      ::grpc::CallbackServerContext* /*context*/, const ::grpcTest::request* /*request*/, ::grpcTest::respond* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_getData<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_getData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_getData() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_getData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getData(::grpc::ServerContext* /*context*/, const ::grpcTest::request* /*request*/, ::grpcTest::respond* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_getData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_getData() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_getData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getData(::grpc::ServerContext* /*context*/, const ::grpcTest::request* /*request*/, ::grpcTest::respond* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestgetData(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_getData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_getData() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->getData(context, request, response); }));
    }
    ~WithRawCallbackMethod_getData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getData(::grpc::ServerContext* /*context*/, const ::grpcTest::request* /*request*/, ::grpcTest::respond* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* getData(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_getData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_getData() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::grpcTest::request, ::grpcTest::respond>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::grpcTest::request, ::grpcTest::respond>* streamer) {
                       return this->StreamedgetData(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_getData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status getData(::grpc::ServerContext* /*context*/, const ::grpcTest::request* /*request*/, ::grpcTest::respond* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedgetData(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::grpcTest::request,::grpcTest::respond>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_getData<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_getData<Service > StreamedService;
};

}  // namespace grpcTest


#endif  // GRPC_sample_2eproto__INCLUDED
