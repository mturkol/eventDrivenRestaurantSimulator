/*
 * StackClass.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Mert Turkol
 * Description: Interface for a Last-In-First-Out stack. Uses doubly linked
 * nodes.
 */

#ifndef STACKCLASS_TEMPLATE_H_
#define STACKCLASS_TEMPLATE_H_

#include <iostream>
#include "ListNodeClass.h"
using namespace std;

template <class T>
class StackClass
{
  private:
    ListNodeClass<T> *stackFront; //1st item in the list
    ListNodeClass<T> *stackEnd; //Last item in the list

  public:
    //Determines whether the stack is empty.
    //Returns true if the stack is empty, otherwise returns false.
    bool checkEmptyStack() const;

    //Adds stackElementToInsert to the front of the stack.
    void push(const T &stackValToInsert);

    //Remove the first element of the stack.
    bool pop(T &frontValToRemove);

    //Prints the contents of the stack from front to end to the screen.
    //For debugging purposes
    void printStackForward() const;

    //Default constructor. Initializes the front and end pointers to NULL
    //to have a stack in empty state.
    StackClass():stackFront(NULL), stackEnd(NULL)
    {
    }

    //Copy constructor
    //StackClass(const StackClass<T>& otherStack):

    //Destructor for the stack. Destroys all the elements within the sorted
    //doubly linked list properly and frees allocated memory if there exists
    //such elements in it.
    ~StackClass()
    {
      ListNodeClass<T> *temp = stackFront;
      T stackValToRemove;
      bool statusRemoveStackFront;

      while(temp != NULL)
      {
        statusRemoveStackFront = pop(stackValToRemove);
        temp = temp -> getNext();
      }
    }
};

#include "StackClass.inl"
#endif /* STACKCLASS_TEMPLATE_H_ */
