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
template<typename T>
class CLinkedList
{
public:
    /* CONSTRUCTOR */
    CLinkedList(
        T* p_oT = nullptr, 
        int iValue = 0
    ) 
    { 
        m_p_oT = p_oT;
        m_iValue = iValue;
    };
    
    /* MEMBERS */
    T* m_p_oT;
    int m_iValue;
        
    void m_getSpecialization() 
    {
        std::cout << "Specialization: template<typename T> class CLinkedList" << "\n";
    }
};

template<typename T, typename S>
class CLinkedList< CNode<T, S> >
{
public:
    /* CONSTRUCTOR */
    CLinkedList(
        CNode<T, S>* p_oNodeHead = nullptr,
        CNode<T, S>* p_oNodeTail = nullptr
        int iValue = 0
    ) 
    {
        m_p_oNodeHead = p_oNodeHead;
        m_p_oNodeTail = p_oNodeTail;
        m_iValue = iValue
    };
    
    /* MEMBERS */
    CNode<T, S>* m_p_oNodeHead;
    CNode<T, S>* m_p_oNodeTail;
    int m_iValue;
    
    void m_getSpecialization() 
    {
        std::cout << "Specialization: template<typename T, typename S> class CLinkedList< <CNode<T, S> >" << "\n";
    }
};


/* MAIN */
int main()
{
    //typedef CSomeRandomClass<int>         CSrc_I;   CSrc_I  oSrc_I; // ERR: wrong number of template arguments (1, should be 2)
    typedef CSomeRandomClass<int, int>    CSrc_II;       CSrc_II     oSrc_II;
    typedef CSomeRandomClass<double, int> CSrc_DI;       CSrc_DI     oSrc_DI;

    typedef CMyTemplateClass<int>         CMtc_I;        CMtc_I      oMtc_I;
    typedef CMyTemplateClass<double>      CMtc_D;        CMtc_D      oMtc_D;
    //typedef CMyTemplateClass<double, int> CMtc_DI;  CMtc_DI oMtc_DI; // ERR: wrong number of template arguments (2, should be 1)

    typedef CMyTemplateClass<CSrc_II>     CMtc_Src_II;   CMtc_Src_II oMtc_Src_II;
    typedef CMyTemplateClass<CSrc_DI>     CMtc_Src_DI;   CMtc_Src_DI oMtc_Src_DI;
    //typedef CMyTemplateClass<CSrc_II, int>     CMtc_Src_II_I;   CMtc_Src_II_I oMtc_Src_II_I; // ERR: wrong number of template arguments (2, should be 1)
    
    int iInt = 1; double iDouble = 1.5;
    
    oMtc_I.m_doSomething( &iInt );
    //oMtc_I.m_doSomething( &iDouble ); // ERR: cannot convert 'double*' to 'int*'
    
    //oMtc_D.m_doSomething( &iInt ); // ERR: cannot convert 'int*' to 'double*'    
    oMtc_D.m_doSomething( &iDouble );
    
    
    return 0;
}
