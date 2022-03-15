#ifndef CLIENT_H
#define CLIENT_H

#include "shared.h"
#include "bridge.h"


/* Client: Sends commands to server. Gets commands from server. 
Acts as interface to server (e.g. console, controller, screen, etc).
All getting/sending done via a Bridge. */
class CBaseClient 
{
  public:
    CBaseClient();
};

#endif