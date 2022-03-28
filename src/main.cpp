#include <iostream>
#include <vector>
#include <map>


const int iNUM_SLOTS = 16;
const int iNUM_PRIORITY_LEVELS = 4;

std::vector<char> vPriorityLevel;
std::map<char, int> mPriorityLevelSize;
//std::map<int, int> mPriorityLevelMaxPerPacket;


int main()
{
  int iNumSlotsLeft = iNUM_SLOTS;
  
  for (int i = 1; i < iNUM_PRIORITY_LEVELS + 1; i++)
  {
    vPriorityLevel.push_back(char(i));
    
    iNumSlotsLeft = iNumSlotsLeft / 2;
    
    mPriorityLevelSize[char(i)] = iNumSlotsLeft;
      
    //mPriorityLevelMaxPerPacket[i] = iNumSlotsLeft;
  }
  
  for (int i : vPriorityLevel)
  {
    std::cout << "level: " << i << "; size: " << mPriorityLevelSize[i] << "\n";
  }

  return 0;
}