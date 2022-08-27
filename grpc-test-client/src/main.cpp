#include <GrpcTextClient.h>
#include <QCoreApplication>

int  main(int argc, char *argv[])
{
  QCoreApplication  a(argc, argv);
  GrpcTextClient    client;
  std::cout << "Starting client ..." << std::endl;

  client.init("127.0.0.1", 2424);
  std::cout << client.sendData() << std::endl;

  return a.exec();
}
