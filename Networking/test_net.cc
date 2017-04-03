
#include <iostream>
#include <string>
#include <thread>
#include "net.h"


using namespace std;
using namespace util;
int main() {
  string ipAddr = "127.0.0.1";
  int port = 8080;
/*
  thread st(&Server::Start, Server(ipAddr, port));
  st.join();
  thread ct(&Client::Send, Client(ipAddr, port), "Hello World!");
  ct.join();
  string message;
  thread ct1(&Client::Recv, message);
  ct1.join();
  
  Server s(ipAddr, port);
  s.Start();

  Client c(ipAddr, port);
  c.Send("Hello World!");

  string message;
  c.Recv(message);
  cout << "Message: " << message << endl;
  */
  
  Server s(ipAddr, port);
  s.runThread();
}
