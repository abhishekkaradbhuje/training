#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <thread>
#include <iostream>
#include <fstream>

using namespace std;
string data = "";
bool dataReady = false;

void Producer(string inFilePath) {
  cout << "Producer: started" << endl;
  sleep(1);

  // TODO: Read from inFilePath to data
  
  ifstream in;
  in.open( inFilePath );
  if ( !in ) {
   cout << "Error in opening File.." << endl;
   exit(1);
  }
  while ( !in.eof() ) {
    char temp;
    in >> temp;
    data = data + temp;
  }
  in.close();
  cout << "Producer is completed" << endl;
  dataReady = true;
}

void Consumer(string outFilePath) {
  cout << "Consumer: started" << endl;
  while (!dataReady) sleep(1);

  // TODO: write from data to outFilePath
  
  ofstream out;
  out.open( outFilePath );
  if (!out)
    cout << "Error in opening File.." << endl;
  out << data;
  out.close();
  cout << "consumer is completed" << endl;
}

int main (int argc, char *argv[]) {
  if (argc < 3) {
    cout << "usage: " << argv[0] << " <inFile> <outFile>" << endl;
    exit(1);
  }
  string inFile = argv[1];
  string outFile = argv[2];

  thread p(Producer, inFile);
  thread c(Consumer, outFile);

  p.join();
  c.join();
}
