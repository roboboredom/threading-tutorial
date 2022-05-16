/* INCLUDE */
#include <iostream>

/* CODE */
/* CSomeRandomClass */
template<typename T, typename S>
class CSomeRandomClass
{
public:
    /* CONSTRUCTOR */
    CSomeRandomClass(T* p_oT = nullptr, S* p_oS = nullptr, int iValue = 0)
    {
        m_p_oT = p_oT;
        m_p_oS = p_oS;
        m_iValue = iValue;
    }
    
    /* MEMBERS */
    T* m_p_oT; 
    S* m_p_oS;
    int m_iValue;
};

/* CMyTemplateClass */
template<typename T>
class CMyTemplateClass
{
public:
    /* CONSTRUCTOR */
    CMyTemplateClass(T* p_oT = nullptr) 
    { 
        m_p_oT = p_oT;
    };
    
    /* MEMBERS */
    T* m_p_oT;
        
    void m_doSomething(T* p_oT) 
    {
        std::cout << "Not specialized (typename T)" << "\n";
    }
};

template<typename T, typename S>
class CMyTemplateClass<CSomeRandomClass<T, S>>
{
public:
    /* CONSTRUCTOR */
    CMyTemplateClass(CSomeRandomClass<T, S>* p_oSRC = nullptr) 
    {
        m_p_oSRC = p_oSRC;
    };
    
    /* MEMBERS */
    CSomeRandomClass<T, S>* m_p_oSRC;
    
    void m_doSomething(CSomeRandomClass<T,S>* p_oSRC) 
    {
       std::cout << "Specialized (typename T, typename S)" << "\n";
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
/* INCLUDE */
#include <iostream>

/* CODE */
/* CSomeRandomClass */
template<typename T, typename S>
class CSomeRandomClass
{
public:
    /* CONSTRUCTOR */
    CSomeRandomClass(T* p_oT = nullptr, S* p_oS = nullptr, int iValue = 0)
    {
        m_p_oT = p_oT;
        m_p_oS = p_oS;
        m_iValue = iValue;
    }
    
    /* MEMBERS */
    T* m_p_oT; 
    S* m_p_oS;
    int m_iValue;
};

/* CMyTemplateClass */
template<typename T>
class CMyTemplateClass
{
public:
    /* CONSTRUCTOR */
    CMyTemplateClass(T* p_oT = nullptr) 
    { 
        m_p_oT = p_oT;
    };
    
    /* MEMBERS */
    T* m_p_oT;
        
    void m_doSomething(T* p_oT) 
    {
        std::cout << "Not specialized (typename T)" << "\n";
    }
};

template<typename T, typename S>
class CMyTemplateClass<CSomeRandomClass<T, S>>
{
public:
    /* CONSTRUCTOR */
    CMyTemplateClass(CSomeRandomClass<T, S>* p_oSRC = nullptr) 
    {
        m_p_oSRC = p_oSRC;
    };
    
    /* MEMBERS */
    CSomeRandomClass<T, S>* m_p_oSRC;
    
    void m_doSomething(CSomeRandomClass<T,S>* p_oSRC) 
    {
       std::cout << "Specialized (typename T, typename S)" << "\n";
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
