/*
 * StackClass.inl
 *
 *  Created on: Mar 25, 2014
 *      Author: Mert Turkol
 * Description: Implementations of a templated Last-In-First-Out Stack that
 *              uses LinkNodeClass with node values, previous and next pointers
 */

#include <iostream>
#include "StackClass.h"
#include "ListNodeClass.h"
using namespace std;

//Determines whether the stack is empty.
//Returns true if the stack is empty, otherwise returns false.
template <class T>
bool StackClass<T>::checkEmptyStack() const
{
  bool isStackEmpty = false; //bool var. to return

  if(stackFront == NULL) //when the stack is empty
  {
    isStackEmpty = true;
  }

  return isStackEmpty; //report back the stack empty status
}

template <class T>
void StackClass<T>::push(const T &stackValToInsert)
{
  ListNodeClass<T> *newStackItem;

  if (stackFront == NULL) //means stack is empty
  {
    newStackItem = new ListNodeClass<T>(NULL, stackValToInsert, NULL);
    stackFront = newStackItem;
    stackEnd = newStackItem;
  }
  else //when newStackItem should be the 1st (on top of the tray)
  {
    newStackItem = new ListNodeClass<T>(NULL, stackValToInsert, stackFront);
    //stackFront points to the old item and it's previous is set to new node
    stackFront->setPreviousPointer(newStackItem);
    //stackFront should now point to newStackItem
    stackFront = newStackItem;
  }
}

//Remove the first element of the stack.
template <class T>
bool StackClass<T>::pop(T &frontValToRemove)
{
  bool statusRemoveStackFront = true;
  ListNodeClass<T> *temp;

  if (stackFront == NULL)
  {
    cout << "Stack is empty, can't remove from the stack!" << endl;
    statusRemoveStackFront = false;
  }
  else
  {
    temp = stackFront;
    stackFront = temp->getNext();
    frontValToRemove = temp->getValue();
    //Free the memory we dynamically allocated in push function
    delete temp;

    //the purpose of following check is to prevent the use of previous pointer
    //setter function when stackFront is pointing to NULL after the stack is
    //cleared using the dtor which actually calls pop() to accomplish its job
    //Prevents seg-fault error while emptying the stack
    if (stackFront != NULL)
    { //when there are no elements in the stack to remove from
      //the previous pointer of the what front is pointing to now becomes NULL
      stackFront->setPreviousPointer(NULL);
    } //end of seg-fault prevention case when temp->getNext() points to NULL
  } //end of if-queue-is-NOT-empty case

  return (statusRemoveStackFront);
}

//Prints the contents of the stack from front to end to the screen.
//For debugging purposes
template <class T>
void StackClass<T>::printStackForward() const
{
  ListNodeClass<T> *temp = stackFront;

  cout << "Forward Stack Contents Follow:" << endl;
  while (temp != NULL) //loop until end of the stack is reached
  {
    cout << "  " << temp->getValue() << endl; //print current item
    temp = temp->getNext(); //jump to the next item in the stack
  }
  cout << "End Of Stack Contents" << endl;
}
