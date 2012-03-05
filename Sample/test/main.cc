#include "base/memory/singleton.h"
#include <iostream>

#pragma comment(lib,"base.lib")

class FooClass {
public:
  static FooClass* GetInstance(); 
  void Bar() {
    int i = 1;
    i++;
     std::cout << i << std::endl;
  }
private:
  FooClass() {
    int i = 1;
    i++;
  }
  friend struct DefaultSingletonTraits<FooClass>;

  DISALLOW_COPY_AND_ASSIGN(FooClass);
};

FooClass* FooClass::GetInstance()
{
  return Singleton<FooClass>::get();
}
int main()
{
  base::AtExitManager exit_manager;

  FooClass::GetInstance()->Bar();
  std::cout << "hello test " << std::endl;
}