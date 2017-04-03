
#include <iostream>
#include <string>
#include "net.h"


using namespace std;
using namespace util;
int main(int argc, char *argv[]) {
  string ipAddr = "127.0.0.1";
  int port = 8080;

  if (argc < 2) {
    cout << "usage :" << argv[1] << "<Message>" << endl;
    return -1;
  }
  
  string message;
  message = argv[1];

  Client c(ipAddr, port);
  c.Send(message);
  c.Recv();
}
