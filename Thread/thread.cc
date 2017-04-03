#include <iostream>
#include <thread>
 
using namespace std;

void thread_id (int num) {
  thread::id th_id = this_thread::get_id();
  cout << "Thread ID of "<< num << "is :" << th_id<<endl;
}
int main() {
  for(int i=0;i<10;i++) {
    thread t1(thread_id, 1);
    thread t2(thread_id, 2);
    thread t3(thread_id, 3);
    thread t4(thread_id, 4);
    thread t5(thread_id, 5);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
  }
}
