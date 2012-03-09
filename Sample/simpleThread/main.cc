#include "base/threading/simple_thread.h"
#include <iostream>
using namespace std;
#pragma comment(lib,"base.lib")
class MyDelegate : public base::DelegateSimpleThread::Delegate
{
public:
  void Run()
  {
    cout << "In MyDelegate Thread Run" << endl;
    base::PlatformThread::Sleep(1000);
  }
};


int main()
{
  MyDelegate myDelegate;
  base::DelegateSimpleThread thread(&myDelegate,"test Thread");
  thread.Start();
  thread.Join();
  return 0;
}