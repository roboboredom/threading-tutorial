#ifndef LINKED_LIST_TOOLS_H
#define LINKED_LIST_TOOLS_H

/* INCLUDE */
#include <stdexcept>
#include <iostream>

/* CODE */
/* CNode.
    @PARAMS
      T = type of the object pointed to by us, i.e. the object proxied by this node.

    @DESC
      Holds a pointer to a single T object.
      Holds left and right pointers to "adjacent" nodes with a matching template instantiation.
*/
template<typename T> class CNode {
public:
  CNode<T>* p_oNodeRight;
  CNode<T>* p_oNodeLeft;
  T* p_oT;
};


/* CLinkedList 
  @PARAMS
    T = any instantiation of CNode; the type of the links in the list.

  @DESC
    - A linked list doesn't actually store nodes in it, rather, it holds
      pointers to the "head" and "tail" nodes, so the rest can be accessed from them.
    - Nodes in the list can only be accessed sequentially.
    - Nodes aren't deleted from the list, they are unlinked from it.
    - Nodes aren't added to the list, they are linked into it.
*/
template<template<typename T> class CNode> class CLinkedList {
// https://stackoverflow.com/questions/6484484/template-template-parameters
// make it accept ONLY CNode(s) of any instantiation!!!!!
public:
  CNode<T>* p_oNodeHead;
  Cnode<T>* p_oNodeTail;
};


#endif