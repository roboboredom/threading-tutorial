#ifndef CLIENT_H
#define CLIENT_H

#include "shared.h"


class CClientBase {

}

extern int iClientThreadFps;
extern int iClientThreadMsPerLoop;

void FClientThreadCallback();

#endif