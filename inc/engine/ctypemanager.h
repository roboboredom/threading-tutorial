#ifndef CTYPEMANAGER_H
#define CTYPEMANAGER_H

/* INCLUDE */
#include <stdexcept>
#include <string>
#include <vector>

/* CODE */
class CTypeManager
{
public:
  void createType(std::string sName);

  int getTypeID(std::string sName);
  int getTypeName(int iID);

  int getNumberOfTypes(); // instead of getAllTypeIDs()
  const std::vector<std::string>& getAllTypeNames();

private:
  int m_iTypeIDCounter;
};