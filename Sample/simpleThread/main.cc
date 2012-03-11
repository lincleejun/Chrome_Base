#include "base/threading/simple_thread.h"
#include <iostream>
using namespace std;
#pragma comment(lib,"base.lib")
class MyDelegate : public base::DelegateSimpleThread::Delegate
{
public:
  void SetVal(int n)
  {
    m_val = n;
  }
  void Run()
  {
    cout << "In MyDelegate Thread Run : " << m_val << endl;
    base::PlatformThread::Sleep(1000);
  }
private:
  int m_val;
};


int main()
{
#if 0
  MyDelegate myDelegate;
  base::DelegateSimpleThread thread(&myDelegate,"test Thread");
  thread.Start();
  thread.Join();
#else
  base::DelegateSimpleThreadPool threadPool("ahaha",5);
  MyDelegate myDelegate[10];
  threadPool.Start();
  for (int i=0; i<10; ++i)
  {
    myDelegate[i].SetVal(i+1);
    threadPool.AddWork(&myDelegate[i]);
  }
  threadPool.JoinAll();

#endif
  return 0;
}