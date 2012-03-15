#include "base/message_loop.h"
#include "base/task.h"
#include "base/at_exit.h"
#include "base/bind.h"
#include "base/memory/scoped_ptr.h"
#include <iostream>
class MyTask : public Task,public base::RefCounted<MyTask>
{
public:
  virtual void Run()
  {
    std::cout << "Ok  MyTask Running!" << std::endl;
  }
  ~MyTask()
  {

  }
private:
  friend class base::RefCounted<MyTask>;
};
class MyTask2 : public Task
{
public:
  virtual void Run()
  {
    std::cout << "Ok  MyTask2 Running!" << std::endl;
  }
  ~MyTask2()
  {

  }

};
class Foo : public base::RefCounted<Foo>
{
public:
  Foo() : test_count_(0) {}

  void Test0() {
    ++test_count_;
  }
  void Test1(int n) 
  {
    std::cout << "Value is : " << n << std::endl;
  }
private:
  ~Foo() {}
  int test_count_;
  const std::string result_;
private:
  friend class base::RefCounted<Foo>;
};
#pragma comment(lib,"base.lib")
int main()
{
  base::AtExitManager exit;
  MessageLoop msgLoop(MessageLoop::TYPE_DEFAULT);
  MyTask2 *pMyTask2 = new MyTask2;
  msgLoop.PostTask(FROM_HERE,pMyTask2);
  scoped_refptr<MyTask> myTask(new MyTask);
  msgLoop.PostTask(FROM_HERE,base::Bind(&MyTask::Run,base::Unretained(myTask.get())));
  scoped_refptr<Foo> foo(new Foo());
  MessageLoop::current()->PostTask(FROM_HERE, 
    base::Bind(&Foo::Test0, foo.get()));
  MessageLoop::QuitTask quitTask;
   MessageLoop::current()->PostTask(FROM_HERE,
      base::Bind(&MessageLoop::Quit, base::Unretained(MessageLoop::current())));
  msgLoop.Run();
  return 0;
}