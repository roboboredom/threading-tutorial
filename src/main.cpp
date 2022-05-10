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

  CNode( T* p_oT = nullptr )
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
  CItem( int iInteger, std::string sString )
  {
    this->iInteger = iInteger;
    this->sString = sString;
  }
  int iInteger;
  std::string sString;
};


/* MAIN */
int main()
{
  std::vector< CNode< CItem >* > vNodes;
  int iI = 0;
  
  while ( true )
  {
    std::cout << "Enter the string value to set in CItem obj: "; std::string sInput =""; std::cin >> sInput;
    vNodes.push_back( new CNode< CItem >( new CItem( iI++, sInput ) ) );

    CNode<CItem>* p_oNode = vNodes.back(); // last element in vector
    // spew some data on the created CNode
    std::cout << "typeid( *p_oNode ).name() = " << typeid( *p_oNode ).name() << ";\n";
    std::cout << "sizeof( *p_oNode )        = " << sizeof( *p_oNode ) << " bytes;\n\n";

    // *( a->b->c ) = dereferences c
    std::cout << "\ttypeid( *( p_oNode->p_oT ) ).name() = " << typeid( *( p_oNode->p_oT ) ).name() << ";\n";
    std::cout << "\tsizeof( *( p_oNode->p_oT ) )        = " << sizeof( *( p_oNode->p_oT ) ) << " bytes;\n\n";
    
    std::cout << "\t\tp_oNode->p_oT->iInteger                       = " << p_oNode->p_oT->iInteger << ";\n";
    std::cout << "\t\ttypeid( *( p_oNode->p_oT->iInteger ) ).name() = " << typeid( p_oNode->p_oT->iInteger ).name() << ";\n";
    std::cout << "\t\tsizeof( *( p_oNode->p_oT->iInteger ) )        = " << sizeof( p_oNode->p_oT->iInteger ) << " bytes;\n\n";

    std::cout << "\t\tp_oNode->p_oT->sString                       = " << p_oNode->p_oT->sString << ";\n";
    std::cout << "\t\ttypeid( *( p_oNode->p_oT->sString ) ).name() = " << typeid( p_oNode->p_oT->sString ).name() << ";\n";
    std::cout << "\t\tsizeof( *( p_oNode->p_oT->sString ) )        = " << sizeof( p_oNode->p_oT->sString ) << " bytes;\n\n";

    std::cout << "=========================================================\n";
  }
  
  return 0;
}