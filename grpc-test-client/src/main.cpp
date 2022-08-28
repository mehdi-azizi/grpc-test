#include <GrpcTextClient.h>
#include <QCoreApplication>
#include <string>
#include <iostream>

int  main(int argc, char *argv[])
{
  GrpcTextClient  client;
  std::cout << "Starting client ..." << std::endl;

  client.init("127.0.0.1", 2424);

  bool  running = true;

  while (running)
  {
    std::cout << "=================" << std::endl;
    std::string  msg = "";
    std::cout << "write something :";
    std::cin >> msg;

    if (msg == "quit")
    {
      break;
    }

    std::cout << client.sendData(msg) << std::endl;
  }

  return 1;
}
