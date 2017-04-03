#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <iostream>
#include <thread>
#include <fstream>
#include <queue>

using namespace std;

queue<char> Q;
bool readComplete = false;

int Read( string inFilePath ) {
  
  cout << "Reader started :" << endl;
  sleep(1);
  
  ifstream in;
  in.open( inFilePath );

  if (!in)
    cout << "Error in opening File.." << endl;
  while (!in.eof()) {
    char temp;
    in >> temp;
    Q.push( temp );
  }

  in.close();
  readComplete = true;
  cout << "Reader is completed" << endl;
}

int Write( string outFilePath ) {

  cout << "Writer is started :" << endl;
  sleep(1);

  ofstream out;
  out.open( outFilePath );
  if (!out)
    cout << "Error in opening File.." << endl;

  while ( readComplete != true || !Q.empty()) {
    while ( Q.empty() ) sleep(1);
     out << Q.front();
     Q.pop();
  }
  
  out.close();
  cout << "Writer is completed.." << endl;
}

int main (int argc, char *argv[]) {

  if (argc < 3) {
    cout << "usage : " << argv[0] << "<inFile>" << " <outFile>" << endl;
    exit(1);
  }
  
  string inFile = argv[1];
  string outFile = argv[2];
  
  thread w(Write, outFile);
  thread r(Read, inFile);

  r.join();
  w.join();
}
