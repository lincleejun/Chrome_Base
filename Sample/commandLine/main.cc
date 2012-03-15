#include <iostream>
#include <string>
#include "base/command_line.h"
#pragma comment(lib,"base.lib")
int main(int argc,char* argv[])
{
  CommandLine::Init(argc,argv);
  CommandLine *pCommandLine = CommandLine::ForCurrentProcess();

  if (pCommandLine->HasSwitch("test"))
  {
    std::cout << "command hasSwitch test" << std::endl;
  }
  else
    std::cout << "command does not hasSwitch test" << std::endl;
  CommandLine::StringVector sv = pCommandLine->GetArgs();
  for (CommandLine::StringVector::iterator it = sv.begin(); it!=sv.end(); ++it)
  {
    std::wcout << *it  << std::endl;
  }
  pCommandLine->Reset();
}