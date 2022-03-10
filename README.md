## threading-tutorial
multithreading project for robotics class  
author: Willem Dawson Gray (willemdgray@outlook.com)  

### styleguide:
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
CClass oObject;

/* prefix prefixes, in order of precedence */ 
// p_ = pointer
int* p_iVar;

// v_ = vector
std::vector<int> v_iVar;

/* order of precedence example */
// pointer TO vector OF int(s)
std::vector<int>* p_v_iVar = &v_iVar;
```