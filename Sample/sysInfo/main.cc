#include "base/sys_info.h"
#include <iostream>
#pragma comment(lib,"base.lib")
using namespace std;
int main()
{
  std::cout << base::SysInfo::CPUArchitecture() << std::endl;
  cout << base::SysInfo::OperatingSystemName() << endl;
  cout << base::SysInfo::NumberOfProcessors() << endl;
  cout << base::SysInfo::OperatingSystemVersion() << endl;
  cout << base::SysInfo::AmountOfPhysicalMemory() << endl;
  cout << base::SysInfo::AmountOfPhysicalMemoryMB()/1024.0f << endl;
  cout << base::SysInfo::VMAllocationGranularity() << endl;
  return 0;
}