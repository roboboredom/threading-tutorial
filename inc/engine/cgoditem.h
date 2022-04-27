#ifndef CGODITEM_H
#define CGODITEM_H

/* INCLUDE */
#include <stdexcept>
#include <string>
#include <vector>

/* CODE */
// Items cannot ever have multiple parents!
// All items must have a parent; but they do not need children.

/* CAN BE GIVEN A PARENT. */
CParentableItem {}; // forward declare for CChildItem bc CParentableItem is defined after

class CChildItem
{
public:
  CChildItem(std::string sName, int iID, CParentableItem* pParent);

  std::string m_sName;
  int         m_iID;

  CParentableItem* m_pParent;
};

/* CAN BE GIVEN A PARENT. CAN BE GIVEN CHILDREN. */
class CParentableItem : public CChildItem
{
public:
  /* this slices objects derived from the CChildItem base class,
     but this is fine since we just want the stuff in/dervied from CChildItem anyway. */
  std::vector<CChildItem*> m_vChildren;
};


/* CAN BE GIVEN CHILDREN. */
class CGodItem
{
public:
  CMasterItem();

  std::vector<CChildItem*> m_vChildren;

  int m_iIDCounter;
};