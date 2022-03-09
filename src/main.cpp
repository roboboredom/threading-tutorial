//#include "engine/shared.h"
#include "engine/client.h"
#include "engine/server.h"

int main()
{
  std::cout << "main start\n";
  
  std::thread* p_tServerThread = new std::thread(FServerThreadCallback);
  std::thread* p_tClientThread = new std::thread(FClientThreadCallback);
  
  p_tServerThread->join();
  p_tClientThread->join();
    
  delete p_tServerThread;
  delete p_tClientThread;
  
  return 0;
}