/* INCLUDE */
//#include "../inc/engine/ctypemanager.h"
#include <string>
#include <iostream>
#include <stdexcept>

/* CODE */
int main()
{
  try
  {
    std::cout << "sussy baka\n";
    throw std::runtime_error("amogus");
    std::cout << "mogus\n";
  }
  catch (std::runtime_error& e)
  {
    std::cout << "\n====[ process exited ]====\n" 
              << e.what()
              << "\n====------------------====\n";
    std::exit(1); // 1 = error
  }
  
  return 0; // 0 = no error
}