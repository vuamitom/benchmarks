// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: idl/grpc_service.proto
#ifndef GRPC_idl_2fgrpc_5fservice_2eproto__INCLUDED
#define GRPC_idl_2fgrpc_5fservice_2eproto__INCLUDED

#include "grpc/grpc_service.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
} // namespace grpc

class GrpcServiceBenchmark GRPC_FINAL {
public:
  class StubInterface {
  public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status get_answer(::grpc::ClientContext *context,
                                      const ::AnswerRequest &request,
                                      ::AnswerReply *response) = 0;
    std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::AnswerReply>>
    Asyncget_answer(::grpc::ClientContext *context,
                    const ::AnswerRequest &request,
                    ::grpc::CompletionQueue *cq) {
      return std::unique_ptr<
          ::grpc::ClientAsyncResponseReaderInterface<::AnswerReply>>(
          Asyncget_answerRaw(context, request, cq));
    }

  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface<::AnswerReply> *
    Asyncget_answerRaw(::grpc::ClientContext *context,
                       const ::AnswerRequest &request,
                       ::grpc::CompletionQueue *cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
  public:
    Stub(const std::shared_ptr<::grpc::ChannelInterface> &channel);
    ::grpc::Status get_answer(::grpc::ClientContext *context,
                              const ::AnswerRequest &request,
                              ::AnswerReply *response) GRPC_OVERRIDE;
    std::unique_ptr<::grpc::ClientAsyncResponseReader<::AnswerReply>>
    Asyncget_answer(::grpc::ClientContext *context,
                    const ::AnswerRequest &request,
                    ::grpc::CompletionQueue *cq) {
      return std::unique_ptr<::grpc::ClientAsyncResponseReader<::AnswerReply>>(
          Asyncget_answerRaw(context, request, cq));
    }

  private:
    std::shared_ptr<::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader<::AnswerReply> *
    Asyncget_answerRaw(::grpc::ClientContext *context,
                       const ::AnswerRequest &request,
                       ::grpc::CompletionQueue *cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_get_answer_;
  };
  static std::unique_ptr<Stub>
  NewStub(const std::shared_ptr<::grpc::ChannelInterface> &channel,
          const ::grpc::StubOptions &options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
  public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status get_answer(::grpc::ServerContext *context,
                                      const ::AnswerRequest *request,
                                      ::AnswerReply *response);
  };
  template <class BaseClass>
  class WithAsyncMethod_get_answer : public BaseClass {
  private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}

  public:
    WithAsyncMethod_get_answer() { ::grpc::Service::MarkMethodAsync(0); }
    ~WithAsyncMethod_get_answer() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status
    get_answer(::grpc::ServerContext *context, const ::AnswerRequest *request,
               ::AnswerReply *response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestget_answer(
        ::grpc::ServerContext *context, ::AnswerRequest *request,
        ::grpc::ServerAsyncResponseWriter<::AnswerReply> *response,
        ::grpc::CompletionQueue *new_call_cq,
        ::grpc::ServerCompletionQueue *notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response,
                                         new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_get_answer<Service> AsyncService;
  template <class BaseClass>
  class WithGenericMethod_get_answer : public BaseClass {
  private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}

  public:
    WithGenericMethod_get_answer() { ::grpc::Service::MarkMethodGeneric(0); }
    ~WithGenericMethod_get_answer() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status
    get_answer(::grpc::ServerContext *context, const ::AnswerRequest *request,
               ::AnswerReply *response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

#endif // GRPC_idl_2fgrpc_5fservice_2eproto__INCLUDED
