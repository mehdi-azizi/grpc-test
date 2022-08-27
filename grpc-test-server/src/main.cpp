#include "GrpcTestServer.h"
#include <QCoreApplication>

int  main(int argc, char *argv[])
{
  QCoreApplication  a(argc, argv);
  std::cout << "Starting server ..." << std::endl;
  GrpcTestServer  x;

  x.start("127.0.0.1", 2424);

  return a.exec();
}
