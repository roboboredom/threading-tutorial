# threading-tutorial
multithreading project for robotics class  
author: Willem Dawson Gray (willemdgray@outlook.com)  

## project design:
```c++
/* ascii things: ═ ║ ╔ ╗ ╚ ╝ ╠ ╣ ╦ ╩ ╬

ENGINE STRUCTURE:
  [main]
    ║
    v
  [enginemanager] <═════════════════════(commands)═══╗
    ║                                               ║
    ╠═(create/destroy/store multiple)═> [clients]   ║
    ║                                      ^        ║
    ║                                      ║        ║
    ║                                  (commands)   ║
    ║                                      ║        ║
    ║                                      v        ║
    ╠═(create/destroy/store)═══════════> [bridge] <══╝
    ║                                      ^
    ║                                      ║
    ║                                  (commands)
    ║                                      ║
    ║                                      v
    ╚═(create/destroy/store)═══════════> [server]


OFFLINE / ONLINE DIFFERENCE:
  OFFLINE:
    [server] <----> [bridge] <----> [client]
  
    Data sent over bridge is not serialized and 
    is transferred directly.

  ONLINE:
    [server] <----> [bridge] <----> [client]

    Data sent over bridge is serialized for transport 
    and then deserialized at destination.


INCLUDE STRUCTURE:
  base bridge
  {
    (derived) project bridge
    {
      base client
      {
        (derived) project clients
        {
          base engine manager {}
        }
      }

      base server
      {
        (derived) project server
        {
          base engine manager {}
        }
      }
    }
  }
  
  base engine manager
  {
    (derived) project engine manager
    {
      main
    }
  }


FOLDER STRUCTURE:
  build:
    // compiler output
  include:
    // same as "src" but for headers
  src:
    engine:
      base bridge
      base client
      base server
      base engine manager

    project:
      clients:
        (derived) project clients

      (derived) project server
      (derived) project bridge (e.g. custom commands)
      (derived) engine manager      

    main.cpp
*/
```
## var naming guide:
```c++
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>

/* for const just capitalize the name */
int iINT_VALUE;

/* name prefixes */
int iInt;
float fFloat;
double dDouble;
bool = bBool;

char = cChar;
std::string sString;

std::thread tThread;
std::mutex mMutex;

void FFunction();

namespace nNamespace {}
enum eEnum { one, two };

class CClass {}
CClass oClass; // ???

/* prefix prefixes, in order of precedence */ 
// p_ = pointer
int* p_iVar;

// v_ = vector
std::vector<int> v_iVar;

/* order of precedence example */
// pointer TO vector OF int(s)
std::vector<int>* p_v_iVar = &v_iVar;
```