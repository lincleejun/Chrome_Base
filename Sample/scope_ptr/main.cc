#include <iostream>
#include "base/memory/scoped_ptr.h"
#include "base/memory/ref_counted.h"

#pragma comment(lib,"base.lib")
class Foo : public base::RefCounted<Foo>
{
public:
  void myFoo()
  {
    std::cout << "myFoo Function" << std::endl;
  }
  void myBar()
  {
    myFoo();
  }
private:
  friend class base::RefCounted<Foo>;
  ~Foo(){}
};

class ThreadSafeFoo : public base::RefCountedThreadSafe<ThreadSafeFoo>
{
public:
  void Foo()
  {
    std::cout << "Thread Safe Version of Ref" << std::endl;
  }
private:
  friend class base::RefCountedThreadSafe<ThreadSafeFoo>;
  ~ThreadSafeFoo(){}
  void DeleteInternal(ThreadSafeFoo* tsf)
  {
    delete tsf;
  }
};

int main()
{
  scoped_refptr<Foo> spFoo(new Foo());
  spFoo->myBar();
  std::cout << spFoo->HasOneRef() << std::endl;
  scoped_refptr<ThreadSafeFoo> ts(new ThreadSafeFoo());
  ts->Foo();
  std::cout << ts->HasOneRef() << std::endl;
  return 0;
}