#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

using namespace std;
namespace util {

class Node {
 public: 
  Node(string ipAddr, int port) { ipAddr_ = ipAddr; port_ = port; }

 protected:
  string ipAddr_;
  int sd_;
  int fd_;
  int port_;
};

/**
 * Socket Server
 */
class Server : public Node {
 public:
  /**
   * @param ipAddr IP Address to which to bind to
   */

  Server(string ipAddr, int port) : Node(ipAddr, port) { }
  int Start();

 private:
  int HandleRequest();
};

/**
 *
 */
class Client : public Node {
 public:
  /**
   * @param ipAddr Server IP Address
   **/
  Client(string ipAddr, int port);
  int Send(string message);
  int Recv();

  private:
    int sd_;
};

}// namespace util
