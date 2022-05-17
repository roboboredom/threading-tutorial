/* INCLUDE */
#include <iostream>

/* CODE */
/* CNode */
template<typename T, typename S>
class CNode
{
public:
    /* CONSTRUCTOR */
    CNode(
        CNode<T, S>* p_oNodeNext = nullptr, 
        CNode<T, S>* p_oNodePrev = nullptr, 
        int iValue = 0
    )
    {
        m_p_oNodeNext = p_oNodeNext;
        m_p_oNodePrev = p_oNodePrev;
        m_iValue = iValue;
    }
    
    /* MEMBERS */
    CNode<T, S>* m_p_oNodeNext;
    CNode<T, S>* m_p_oNodePrev; 
    int m_iValue;
};

/* CLinkedList */
template<typename T> // prevent un-specialized template instantiation
class CLinkedList;

template<typename T, typename S>
class CLinkedList< CNode<T, S> >
{
public:
    /* CONSTRUCTOR */
    CLinkedList(
        CNode<T, S>* p_oNodeHead = nullptr,
        CNode<T, S>* p_oNodeTail = nullptr,
        int iValue = 0
    ) 
    {
        m_p_oNodeHead = p_oNodeHead;
        m_p_oNodeTail = p_oNodeTail;
        m_iValue = iValue;
    }
    
    /* MEMBERS */
    CNode<T, S>* m_p_oNodeHead;
    CNode<T, S>* m_p_oNodeTail;
    int m_iValue;
    
    void m_getSpecialization() 
    {
        std::cout << "Specialization: template<typename T, typename S> class CLinkedList< <CNode<T, S> >" << "\n\n";
    }
};


/* MAIN */
int main()
{
    //typedef CNode<int>         CNodeI; // ERR: wrong number of template arguments (1, should be 2)
    typedef CNode<int, int>    CNodeII;
    typedef CNode<double, int> CNodeDI;
    
    //typedef CNode<CNodeII>          CNode_CNodeII; // ERR: wrong number of template arguments (1, should be 2)
    typedef CNode<CNodeII, CNodeII> CNode_CNodeII_CNodeII;
    typedef CNode<CNodeDI, CNodeII> CNode_CNodeDI_CNodeII;
    
    
    typedef CLinkedList<int>         CLinkedListI; 
    typedef CLinkedList<double>      CLinkedListD;
    //typedef CLinkedList<int, int>    CLinkedListII; // ERR: wrong number of template arguments (2, should be 1)
    //typedef CLinkedList<double, int> CLinkedListDI; // ERR: wrong number of template arguments (2, should be 1)
    
    typedef CLinkedList<CNodeII>          CLinkedList_CNodeII;
    typedef CLinkedList<CNodeDI>          CLinkedList_CNodeDI;
    //typedef CLinkedList<CNodeII, CNodeII> CLinkedList_CNodeII_CNodeII; // ERR: wrong number of template arguments (2, should be 1)
    //typedef CLinkedList<CNodeDI, CNodeII> CLinkedList_CNodeDI_CNodeII; // ERR: wrong number of template arguments (2, should be 1)
    
    
    // using objects of template instantiations defined above, test some random shit
    CLinkedListI        oLinkedListI;        std::cout << "oLinkedListI\n";        oLinkedListI.m_getSpecialization();
    CLinkedListD        oLinkedListD;        std::cout << "oLinkedListD\n";        oLinkedListD.m_getSpecialization();
    
    CLinkedList_CNodeII oLinkedList_CNodeII; std::cout << "oLinkedList_CNodeII\n"; oLinkedList_CNodeII.m_getSpecialization();
    CLinkedList_CNodeDI oLinkedList_CNodeDI; std::cout << "oLinkedList_CNodeDI\n"; oLinkedList_CNodeDI.m_getSpecialization();
    
    
    return 0;
}
