#include "client.h"


int iClientThreadFps = 30;
int iClientThreadMsPerLoop = 1000 / iClientThreadFps;

void FClientThreadCallback()
{
  std::cout << "FClientThreadCallback start\n";
  
  int iClientLoop = 5;
  
  while (true)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(iClientThreadMsPerLoop)); //fps
    
    std::cout << "\033[2J\033[1;1H"; //clear screen

    //visualize fps
    std::cout << "render loop: " << iClientLoop++ <<"\n";
    for (int i = 0; i < iClientLoop; i++) { std::cout << "|"; }
    std::cout << "\n";
    if (iClientLoop > iClientThreadFps) { iClientLoop = 0; }
    
    if(mServerClientShareGuard.try_lock())
    {  
      std::cout << "iValueA: " << iValueA << "\n"; //example data
      std::cout << "iValueB: " << iValueB << "\n";
      
      mServerClientShareGuard.unlock();
    }
  }
}