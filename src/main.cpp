/* INCLUDE */
#include "../inc/engine/cgoditem.h"
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

/* CODE */
int main()
{
  try
  {
    throw std::invalid_argument("amogus");
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what() << std::endl;
    return -1; 
  }
  
  return 0;
}