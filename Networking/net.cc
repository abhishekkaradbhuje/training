
#include <stdio.h>

#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <errno.h>

#include "net.h"

using namespace std;

namespace util {

int Server::Start() {
  int rc = 0;

  sd_ = socket(AF_INET, SOCK_STREAM, 0);
  if (sd_ < 0) {
    rc = -errno;
    cout << rc << ": Server socket failed" << endl;
    return rc;
  }
    
  struct sockaddr_in addr;
    
  bzero(&addr, sizeof(addr));

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ipAddr_.c_str());
  addr.sin_port = htons(port_);
    
  rc = bind(sd_, (struct sockaddr *) &addr, sizeof(addr));
  if (rc < 0) {
    rc = -errno;
    cout << "Error in binding" << endl;
    return rc;
  }

  while (true) {
    rc = HandleRequest();
    if (rc < 0)
      break;
  }
  
  return rc;
}
    
int Server::HandleRequest() {
  struct sockaddr_in addr;
  
  int rc = 0;
  rc = listen(sd_, 5);
  if (rc < 0) {
    rc = -errno;
    cout << rc << ": error in listening" << endl;
    return rc;
  }
 
  int fd_ = accept(sd_, NULL, NULL);
  if (fd_ < 0) {
    rc = -errno;
    cout << rc << ": error in accept" << endl;
    return rc;
  }

  char buffer[1024];
  bzero(buffer, 1024);
  int n = read(fd_, buffer, 1024);
  if (n < 0) {
    rc = -errno;
    cout << rc << ": read() failed" << endl;
    return rc;
  }
  cout << "Message : " << buffer << endl; 
  
  n = write(fd_, "I got your messgae", 22);
  if (n < 0) {
    rc = -errno;
    cout << rc << ": write() failed" << endl;
    return rc;
  }
  close(fd_);
};

Client::Client(string ipAddr, int port) : Node(ipAddr, port) {
  
  int rc;
  sd_ = socket(AF_INET, SOCK_STREAM, 0);
  if (sd_ < 0 ) {
    rc = -errno;
    cout << rc << ": error in client socket" << endl;
  }
  
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port_);
  addr.sin_addr.s_addr = inet_addr(ipAddr_.c_str());

  rc = connect(sd_, (struct sockaddr *) &addr, sizeof(addr));
  if (rc < 0) {
    rc = -errno;
    cout << rc << ": error in connection" << endl;
  }
}

int Client::Send(string message) {
  int rc = send(sd_, message.c_str(), message.length(), 0);
  if (rc < 0) {
      cout << rc << ": error in sending message" << endl;
  }
}

int Client::Recv() {
  char buffer[1024];

  int rc = recv(sd_, buffer, sizeof(buffer),0);
  if (rc < 0) {
    rc = -errno;
    cout << rc << ": error in recieving" << endl;
  }
  cout << "Message : " << buffer << endl;
}

} // namespace util
