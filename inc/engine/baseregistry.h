#ifndef BASEREGISTRY_H
#define BASEREGISTRY_H

/* INCLUDE */
#include <stdexcept>
#include <string>
#include <map>

/* CODE */

/* Variable, name & id are read-only after init */
class CVariable
{
public:
  CVariable(std::string sName);
  std::string getName();
  int getID();

private:
  std::string m_sName;
  int m_iID;
};

/* VariableManager, manages all variables and their scopes. */
class CVariableManager
{
public:
  CVariableManager();

private:
  int m_iIDCounter;
};

#endif