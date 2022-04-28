/* INCLUDE */
#include "../../inc/engine/ctypemanager.h"

/* CODE */
CVariable::CVariable(std::string sName, int iID)
{ 
  m_sName = sName;
  m_iID = iID;
}
std::string CVariable::getName()
{
  return m_sName;
}
int CVariable::getID()
{
  return m_iID;
}


CVariableManager::CVariableManager()
{
  m_iIDCounter = 0;
}