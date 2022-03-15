#ifndef BRIDGE_H
#define BRIDGE_H

#include "shared.h"

/* Forward declare classes, so CBaseBridge can
access their members n stuff but cant contain 
objects of these just pointers to objects */
//class CBaseClient;
//class CBaseServer;

/* Bridge: Bridges command sending/getting between Server and Clients. */
class CBaseBridge 
{
  public:
    CBaseBridge();
};

#endif