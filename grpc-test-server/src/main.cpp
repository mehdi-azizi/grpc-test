#include "GrpcTestServer.h"
#include <QCoreApplication>

int  main(int argc, char *argv[])
{
  QCoreApplication  a(argc, argv);
  std::cout << "Starting server ..." << std::endl;
  GrpcTest::GrpcTestServer  x;

  if (x.start("0.0.0.0", 2424))
  {
    return a.exec();
  }

  return 1;
}
