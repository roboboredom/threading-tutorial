#include <vector>
#include <string>
#include <iostream>
#include <algorithm> // std::generate_n()
#include <stdlib.h> // std::rand()

/* COMMAND SYSTEM */
class CBaseCommandManager

class CBaseCommand
{
public:
  int m_iTransmitterID;

  CBaseCommand(int iTransmitterID) 
  {
    m_iTransmitterID = iTransmitterID;
  }
};

class CRequest : public CBaseCommand
{
public:
  std::string m_sCommand;

  CRequest(int iTransmitterID, std::string sCommand) 
  : CBaseCommand(iTransmitterID)
  {
    m_sCommand = sCommand;
  }
};


/* CLIENT & SERVER SYSTEM */
CBaseClient
{
public:
  CBaseClient()
  {
  }

protected:
};

CBaseServer
{
public:
  CBaseServer()
  {
  }

protected:
};


/* MANAGER SYSTEM */
CBaseManager()
{
public:
  CBaseManager()
  {
  }

protected:
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

  
  return 0;
}