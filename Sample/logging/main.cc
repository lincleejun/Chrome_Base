#include <iostream>
#include "base/logging.h"
#pragma comment(lib,"base.lib")

int main()
{
  LOG(INFO) << "Found";
  LOG(WARNING) <<"warning";
  LOG(ERROR) << "error";
  LOG(ERROR_REPORT) << "Error report";
  LOG(FATAL) << "fatal";
//  LOG(NUM_SEVERITIES) <<"num severities";
  return 0;
}