#include "server.h"


int iServerThreadMsPerLoop = 1000 / 30;

void FServerThreadCallback()
{
  std::cout << "FServerThreadCallback start\n";
  
  while (true)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(iServerThreadMsPerLoop));

    /*if(mServerClientShareGuard.try_lock())
    {
      iValueA++; //example data
      iValueB--;
      
      mServerClientShareGuard.unlock();
    }*/
  }
}