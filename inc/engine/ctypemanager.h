#ifndef CTYPEMANAGER_H
#define CTYPEMANAGER_H

/* INCLUDE */
#include <stdexcept>
#include <string>
#include <vector>

/* CODE */
/*

1. List init:
  list  = []

2. Add items to list:
  new(a); new(b); etc...

  item_names = [a][b][c][d][e][f][g]
                0  1  2  3  4  5  6

3. Get some reference objects:
  item_reference_instances = [
    Apple  = {},
    Orange = {},
    Grape  = {},
    Kiwi   = {}
  ]
*/
class CTypeManager
{
public:
  CTypeManager();

  void createType(std::string sName);

  int getTypeID(std::string sName);
  int getTypeName(int iID);

  int getNumberOfTypes(); // instead of getAllTypeIDs()
  const std::vector<std::string>& getAllTypeNames();

private:
  int m_iTypeIDCounter;
  std::vector<std::string> m_vTypeNames;
};