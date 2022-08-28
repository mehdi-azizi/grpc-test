#include "GrpcTestServer.h"
#include "Worker.h"
#include <grpcpp/completion_queue.h>
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
namespace GrpcTest
{
GrpcTestServer::GrpcTestServer():
  _running(false),
  _listenAddress(""),
  _service(nullptr)
{
}

GrpcTestServer::~GrpcTestServer()
{
  stop();
}

bool  GrpcTestServer::start(const std::string &ip, int port)
{
  _listenAddress = ip + ":" + std::to_string(port);

  return start();
}

bool  GrpcTestServer::start()
{
  if (_running)
  {
    std::cout << "Server is already running. addr:" << _listenAddress << std::endl;

    return false;
  }

  _running = true;
  std::cout << "Starting to listen on " << _listenAddress << std::endl;

  {
    ServerBuilder  builder;
    int           *selected = nullptr;

    builder.AddListeningPort(_listenAddress, grpc::InsecureServerCredentials(), selected);
    _service = new AsyncService();

    builder.RegisterService(_service);
    _queue = builder.AddCompletionQueue();

    _server = builder.BuildAndStart();

    if ((nullptr != _server))
    {
      std::cout << "Starting Worker ..." << std::endl;
      _thread = ThreadPtr(new QThread());
      _thread->start();
      _worker = WorkerPtr(new Worker(_service, _queue));
      _worker->moveToThread(_thread.get());
      emit _worker->signalToRun();
// _worker->run();

      return true;
    }
    else
    {
      std::cout << "Failed to start the server!!!  " << std::endl;
      std::cout << "for more information run \"export GRPC_VERBOSITY=DEBUG\" before running this app." << std::endl;
    }
  }

  _running = false;

  return false;
}

void  GrpcTestServer::restart()
{
  if (_running)
  {
    stop();
  }

  start();
}

void  GrpcTestServer::stop()
{
  if (_running)
  {
    _worker->stop();
    _server->Shutdown();
    _queue->Shutdown(); // Always *after* the associated server's Shutdown()!
    void *ignored_tag;
    bool  ignored_ok;

    while (_queue->Next(&ignored_tag, &ignored_ok))
    {
    }

    if (nullptr != _thread.get())
    {
      _thread->quit();
      _thread->wait(1000);
      _thread.reset(nullptr);
    }

    if (nullptr != _service)
    {
      delete _service;
      _service = nullptr;
    }

    _running = false;
  }
}

std::string  GrpcTestServer::getListenAddress() const
{
  return _listenAddress;
}

void  GrpcTestServer::changeListenAddress(const std::string &listenAddress)
{
  _listenAddress = listenAddress;

  if (_running)
  {
    restart();
  }
}
}
