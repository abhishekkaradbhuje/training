
#include <iostream>
#include <string>
#include "net.h"


using namespace std;
using namespace util;
int main() {
  string ipAddr = "127.0.0.1";
  int port = 8080;

  Server s(ipAddr, port);
  s.Start();
}
