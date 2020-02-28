/*
 * ListNodeClass.inl
 *
 *  Created on: Mar 20, 2014
 *      Author: Mert TURKOL
 * Description: Implementation details for the member functions of a doubly
 * linked list node interface
 */

//Sets the "next" pointer of a node.
#include "ListNodeClass.h"
using namespace std;

template <class T>
void ListNodeClass<T>::setNextPointer(ListNodeClass *newNextPtr)
{
  nextNode = newNextPtr;
}

//Returns the value stored within this node.
template <class T>
T ListNodeClass<T>::getValue() const
{
  return nodeVal; //return the value hold within a specific node
}

//Returns the address of the node that follows this node.
template <class T>
ListNodeClass<T>* ListNodeClass<T>::getNext() const
{
  return nextNode;
}

//Returns the address of the node that comes before this node.
template <class T>
ListNodeClass<T>* ListNodeClass<T>::getPrev() const
{
  return prevNode;
}

//Sets the object's previous node pointer to the value passed in.
template <class T>
void ListNodeClass<T>::setPreviousPointer(ListNodeClass *newPrevPtr)
{
  prevNode = newPrevPtr;
}
//Uses the pointers contained within this node to change the previous
//and next nodes
template <class T>
void ListNodeClass<T>::setBeforeAndAfterPointers()
{
  //setPreviousPointer(this->getPrev());
  //setNextPointer(this->getNext())
  prevNode->setNextPointer(this);
  nextNode->setPreviousPointer(this);
}
