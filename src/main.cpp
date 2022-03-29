#include <vector>
#include <string>
#include <iostream>
#include <algorithm> // std::generate_n()
#include <stdlib.h> // std::rand()

/* COMMAND SYSTEM */
class CBaseCommand
{
public:
  int m_iTransmitterId;

  CBaseCommand(int iTransmitterId = 0) 
  {
    m_iTransmitterId = iTransmitterId;
  }
};

class CRequest : public CBaseCommand
{
public:
  std::string m_sCommand;

  CRequest(int iTransmitterId, std::string sCommand) 
  : CBaseCommand(iTransmitterId)
  {
    m_sCommand = sCommand;
  }
};


/* testing */
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

int main()
{
  std::vector <CRequest*> vRequests;
  for (int i = 0; i < 10; i++)
  {
    vRequests.push_back( new CRequest(i, random_string(10)));
  }

  for (CRequest* p_oRequest : vRequests)
  {
    std::cout << "{ id: " << p_oRequest->m_iTransmitterId << ", command: " << p_oRequest->m_sCommand << " }\n";
  }

  
  return 0;
}