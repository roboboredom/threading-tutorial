/* INCLUDE */
#include <stdexcept>
#include <typeinfo>
#include <iostream>
#include <vector>
#include <string>

/* CODE */
template< typename T > class CNode 
{
public:
  // adjacent nodes 
  CNode< T >* p_oNodeRight;
  CNode< T >* p_oNodeLeft;

  // proxy to T object 
  T* p_oT; 

  CNode( T* p_oT )
  {
    this->p_oT = p_oT;
    this->p_oNodeRight = nullptr;
    this->p_oNodeLeft = nullptr;
  }
};


// template< template<typename> class CNode > 
// class CLinkedList 
// {
// public:
//   CNode<T>* p_oNodeHead;
//   CNode<T>* p_oNodeTail;
// };


class CItem
{
public:
  CItem( int iValue )
  {
    this->iValue = iValue;
    this->sString = std::to_string(iValue) += "loboguara";
  }
  int iValue;
  std::string sString;
};


/* MAIN */
int main()
{
  std::vector< CNode< CItem >* > vNodes;
  for ( int i = 0; i < 3; i++ ) 
  {
    vNodes.push_back( new CNode< CItem >( new CItem( i ) ) );
  }

  for ( auto p_oNode : vNodes ) 
  {
    std::cout << "p_oNode->p_oT->iValue = "     << p_oNode->p_oT->iValue << ";\n";
    std::cout << "typeid( *p_oNode ).name() = " << typeid( *p_oNode ).name() << ";\n";
    std::cout << "sizeof( *p_oNode ) = "        << sizeof( *p_oNode ) << " bytes;\n\n";
    
    std::cout << "\ttypeid( p_oNode->*p_oT ).name() = " << typeid( *(p_oNode->p_oT) ).name() << ";\n";
    std::cout << "\tsizeof( p_oNode->*p_oT ) = "        << sizeof( *(p_oNode->p_oT) ) << " bytes;\n\n";
    std::cout << "=========================================================\n";
  }
  
  return 0;
}