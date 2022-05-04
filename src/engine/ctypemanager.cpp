/* INCLUDE */
#include "../../inc/engine/ctypemanager.h"

/* CODE */
CTypeManager::CTypeManager()
{
  m_iTypeIDCounter = 0;
}

void CTypeManager::createType(std::string sName)
{
  // m_vTypeNames.push_back(ctype); 
}

int CTypeManager::getTypeID(std::string sName)
{
  
}

int CTypeManager::getTypeName(int iID)
{
  
}

int CTypeManager::getNumberOfTypes()
{
  m_iTypeIDCounter;
}

const std::vector<std::string>& CTypeManager::getAllTypeNames();
{
  return m_vTypeNames;
}