#include <iostream>
#include <vector>
#include <map>
// plane = packet
// seat  = packet slot
// type  = packet priority level

const int iNUM_SLOTS = 16;
const int iNUM_PRIORITY_LEVELS = 4;

std::vector<int> vPriorityLevel;
std::map<int, int> mPriorityLevelSize;
std::map<int, int> mPriorityLevelMaxPerPacket;


int main()
{
  int iNumSlotsLeft = iNUM_SLOTS;
  
  for (int i = 1; i < iNUM_PRIORITY_LEVELS + 1; i++)
  {
    vPriorityLevel.push_back(i);
    
    iNumSlotsLeft = iNumSlotsLeft / 2;
    
    mPriorityLevelSize[i] = iNumSlotsLeft;
      
    mPriorityLevelMaxPerPacket[i] = iNumSlotsLeft;
  }
  
  for (int i : vPriorityLevel)
  {
    std::cout << "level: " << i << "; size: " << mPriorityLevelSize[i] << "; max per packet: " << mPriorityLevelMaxPerPacket[i] << ";\n";
  }

  return 0;
}

[][][][] [2][2][2][2] [1][1][1][1] [1][1][1][1]