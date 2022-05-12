/* INCLUDE */
#include <stdexcept>
#include <typeinfo>
#include <iostream>
#include <vector>
#include <string>

/* CODE */
template< typename T > 
class CNode 
{
public:
  // adjacent nodes 
  CNode< T >* p_oNodeRight;
  CNode< T >* p_oNodeLeft;

  // proxy to T object 
  T* p_oT; 

  CNode( T* p_oT = nullptr )
  {
    this->p_oT = p_oT;
    this->p_oNodeRight = nullptr;
    this->p_oNodeLeft = nullptr;
  }
};




/* DEBUG */
class CItem
{
public:
  CItem( int iInteger, std::string sString )
  {
    this->iInteger = iInteger;
    this->sString = sString;
  }
  int iInteger;
  std::string sString;
};

namespace NDebug
{
  /* returns a string containing some data on a var */
  template< typename T >
  void printVarInfo( T oT, std::string sVariableName )
  {
    // construct string with iIndentLevel number of '\t'
    std::cout << "[VAR INFO] " << sVariableName << "\n{\n\t"
              << "typeid() = " << typeid( oT ).name() << ";\n\t"
              << "sizeof() = " << sizeof( oT )        << "\n}\n";
  }
};

namespace NTypeDefs
{
  typedef CNode< CItem > CItemNode;
};

/* MAIN */
int main()
{
  NTypeDefs::CItemNode p_oNodeA = new NTypeDefs::CItemNode(); 
  NDebug::printVarInfo( p_oNodeA , "p_oNodeA" );
  NDebug::printVarInfo( *p_oNodeA, "*p_oNodeA" );
  
  std::vector< NTypeDefs::CItemNode* > vNodePtrs;
  while ( true )
  {
    // get input arg
    std::cout << "\nEnter the string value to set in CItem obj: "; 
    std::string sInput = ""; std::cin >> sInput;

    // create vars using input arg
    vNodePtrs.push_back( new NTypeDefs::CItemNode( new CItem( sInput ) ) );

    // spew info on created vars
    NTypeDefs::CItemNode* p_oNode = vNodePtrs.back(); // get ptr to created vars
    NDebug::printVarInfo( p_oNode, "p_oNode" );   // ptr info
    NDebug::printVarInfo( *p_oNode, "*p_oNode" ); // ptr target info
    std::cout << "\n";
  }
  
  return 0;
}