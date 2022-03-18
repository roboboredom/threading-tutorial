# threading-tutorial
multithreading project for robotics class  
author: Willem Dawson Gray (willemdgray@outlook.com)  

## Project design:
```c++
/* ascii chars: ═ ║ ╔ ╗ ╚ ╝ ╠ ╣ ╦ ╩ ╬

ENGINE STRUCTURE:
  [main]
    ║
    v
  [enginemanager] <═════════════════════(commands)═══╗
    ║                                                ║
    ╠═(create/destroy/store multiple)═> [clients]    ║
    ║                                      ^         ║
    ║                                      ║         ║
    ║                                  (commands)    ║
    ║                                      ║         ║
    ║                                      v         ║
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
## Hungarian notation reference:
```c++
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <thread>
#include <mutex>

/* Prioritize searchability, e.g.
  "appleBig"
  "appleSmall"

Instead of:
  "bigApple"
  "smallApple"                    

Make use of grouping! E.g. this:
  class CBaseClient {};
  class CClientKeyboard : CBaseClient {};
  class CClientRender : CBaseClient {};

Becomes this:
  class CBaseClient {};
  namespace Clients 
  {
    class Keyboard : CBaseClient {};
    class Render : CBaseClient {};
  }                                       */

/* Prefixes */
int iInt;
float fFloat;
double dDouble;
bool bBool;
char cChar;
std::string sString;
std::thread tThread;
std::mutex mMutex;
std::vector<int> vVector;
std::map<char, int> mMap;

namespace nNamespace {};
enum eEnum {};
// functions have no prefix

/* For a pointer, put "p_" before all prefixes above this comment */
int* p_iInt;

/* For a static, put "s_" before all prefixes above this comment */
static int s_iInt;

class CClass 
{
public:
  CClass(); // constructor & destructor have no prefix
  ~CClass();
  
  /* For all other class members, put "m_" 
     before all prefixes above this comment */
  static int m_s_iInt;
  int        m_iInt;
  int*       m_p_iInt = &iInt;
  
private:
  void m_foo();
};

/* Put "o" for class objects, after all prefixes above this comment */
CClass* p_oClassObject = new CClass();
```