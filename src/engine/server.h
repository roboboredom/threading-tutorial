#ifndef SERVER_H
#define SERVER_H

#include "shared.h"
#include "bridge.h"


/* Server: Gets commands of clients. Sends commands to clients. 
All getting/sending done via a Bridge. */
class CBaseServer 
{
  public:
    CBaseServer();
};

#endif