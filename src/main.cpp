#include <iostream>
#include <string>
#include <map>
/*
#include <algorithm> // std::generate_n()
#include <stdlib.h> // std::rand()
// Generates std::string of random chars, of size_t length.
std::string random_string(size_t length)
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ std::rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
} 
*/

/* curiously recurring template pattern
class Component {};

template <typename T>
class ComponentTemplate : public Component {}

class Apple : public ComponentTemplate<Apple> {}
*/

class CTypeGroup
{
public:
  CTypeGroup() 
  { 
    m_iIDCounter = 0; 
  }

  static const std::map<int, std::string>& m_getTypes() 
  { 
    return m_mTypes; 
  }

  static bool m_isType(int iID) 
  { 
    return m_mTypes.count(iID) != 0;
  }

protected:
  static int m_iIDCounter;
  static std::map<int, std::string> m_mTypes;

  static int m_newType(std::string sName)
  {
    m_mTypes[m_iIDCounter++] = sName;
    return m_iIDCounter;
  }
};


class CColors final: public CTypeGroup //final = non-derivable
{
  /* constants matching runtime values, just easy use in code, like enum */
  const int m_iRED = m_newType("RED");
  const int m_iBLUE = m_newType("BLUE");
  const int m_iGREEN = m_newType("GREEN");
  const int m_iPINK = m_newType("PINK");
}



int main()
{
  COLORS oColors;
  std::cout << oColors.RED << "\n";
  std::cout << oColors.BLUE << "\n";
  std::cout << oColors.GREEN << "\n";
  std::cout << oColors.PINK << "\n";
  std::cout << oColors.m_isType(0) << "\n";
  std::cout << oColors.m_isType(1) << "\n";
  std::cout << oColors.m_isType(4) << "\n";
  std::cout << oColors.m_isType(5) << "\n";
  
  return 0;
}