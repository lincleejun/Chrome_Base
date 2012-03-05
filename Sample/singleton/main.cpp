#include <Windows.h>
#include <iostream>
#if 0 
#include "base/memory/singleton.h"
#include "base/at_exit.h"
#pragma comment(lib,"base.lib")
class FooClass {
public:
  static FooClass* GetInstance(); 
  void Bar() {
    int i = 1;
    i++;
   // std::cout << i << std::endl;
  }
private:
  FooClass() {
    int i = 1;
    i++;
  }
  friend struct DefaultSingletonTraits<FooClass>;

  DISALLOW_COPY_AND_ASSIGN(FooClass);
};


FooClass* FooClass::GetInstance() {
  return Singleton<FooClass>::get();
}
#endif
int main()
{
#if 0
  base::AtExitManager exit_manager;

  FooClass::GetInstance()->Bar();
#endif
  int a= 3;
  return 0;
}