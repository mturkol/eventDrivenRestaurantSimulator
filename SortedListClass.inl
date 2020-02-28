/*
 * SortedListClass.inl
 *
 *  Created on: Mar 20, 2014
 *      Author: Mert Turkol
 * Description: Implementations of a templated sorted doubly linked list
 * interface.
 */

#include <iostream>
#include "SortedListClass.h"
#include "ListNodeClass.h"
using namespace std;

//Clears the list to an empty state without resulting in any memory leaks.
template <class T>
void SortedListClass<T>::clear()
{
  //ListNodeClass<T> *temp = head;
  T theValToRemove;
  bool statusDeleteFront = false;

  int numElements = getNumElems();//learn #elements to be deleted
  for (int iDelete = 0; iDelete < numElements; iDelete++)
  {
    statusDeleteFront = removeFront(theValToRemove);
  }
  head = NULL;
  tail = NULL;
}

//Prints the contents of the list from head to tail to the screen.
template <class T>
void SortedListClass<T>::printForward() const
{
  ListNodeClass<T> *temp = head; //forward direction search starts from head
  cout << "Forward List Contents Follow:" << endl;

  while (temp != NULL) //loop until end of the list is reached
  {
    cout << "  " << temp->getValue() << endl; //print current item
    temp = temp->getNext(); //jump to the next item in the list
  }

  cout << "End Of List Contents" << endl;
}

//Prints the contents of the list from tail to head to the screen.
template <class T>
void SortedListClass<T>::printBackward() const
{
  ListNodeClass<T> *temp = tail; //backward direction should start from tail
  cout << "Backward List Contents Follow:" << endl;

  while (temp != NULL) //loop until the end of the list is reached
  {
    cout << "  " << temp->getValue() << endl; //print the current item
    temp = temp->getPrev(); //jump to the previous item in the list
  }

  cout << "End Of List Contents" << endl;
}

//Removes the front item from the list and returns the value that was contained
//in it via the reference parameter.
template <class T>
bool SortedListClass<T>::removeFront(T &theVal)
{
  bool status = true;
  ListNodeClass<T> *temp;

  if (head == NULL)
  {
    cout << "List is empty, can't delete from list!" << endl;
    status = false;
  }
  else
  {
    temp = head;
    head = temp->getNext();
    theVal = temp->getValue();
    //Free the memory we dynamically allocated in insert function
    delete temp;

    //the purpose of following check is to prevent the use of previous pointer
    //setter function when head is pointing to NULL after the list is cleared
    //using the clear() function which actually calls removeFront
    //to accomplish its job. Prevents seg-fault error while emptying the stack
    if (head != NULL) //when there are no elements in the list to delete
    {
      //the previous pointer of the new item at front points to NULL
      head->setPreviousPointer(NULL);
    } //end of seg-fault prevention case when temp->getNext() points to NULL
  } //end of if-queue-is-NOT-empty case

  return (status);
}

//Returns the number of nodes contained in the list.
template <class T>
int SortedListClass<T>::getNumElems() const
{
  ListNodeClass<T> *temp = head; //forward direction search starts from head
  int countElements = 0;

  while (temp != NULL) //loop until end of the list is reached
  {
    countElements++; //increase the # counted elements by 1
    temp = temp->getNext(); //jump to the next item in the list
  }

  return countElements; //return the total # elements in the list
}

//Provides the value stored in the node at index provided in the
//"index" parameter.
template <class T>
bool SortedListClass<T>::getElemAtIndex(const int index, T &outVal)
{
  bool itemFound = false;
  int numItems = getNumElems();
  ListNodeClass<T> *temp = head;

  if((temp!= NULL) && (index >= 0) && (index <= (numItems - 1)))
  {
    for (int countElements = 0; countElements < index; countElements++)
    {
      temp = temp->getNext();
      //Allows the user to insert a value into the li
    }
    outVal = temp->getValue();
    itemFound = true;
  }

  return (itemFound);
}

//Allows the user to insert a value into the list.
template <class T>
void SortedListClass<T>::insertValue(
const T &valToInsert) //The value to insert into the list
{
  ListNodeClass<T> *temp = head;
  ListNodeClass<T> *newNode;

  if (head == NULL) //means list is emp
    //Allows the user to insert a value into the lity
  {
    newNode = new ListNodeClass<T>(NULL, valToInsert, NULL);
    head = newNode;
    tail = newNode;
  }
  else if((valToInsert < (head->getValue()))) //when newNode should be the 1st
  {
    newNode = new ListNodeClass<T>(NULL, valToInsert, head);
    //head still points to the old item and it's previous is set to new node
    head->setPreviousPointer(newNode);
    //head should now point to newNode
    head = newNode;
  }
  else if(((valToInsert) >= tail->getValue()))
  { //when newNode should be the last
    newNode = new ListNodeClass<T>(tail, valToInsert, NULL);
    //set next pointer of what tail was pointing to now point to our newNode
    tail->setNextPointer(newNode);
    //tail now points to our newNode which is the last item on the list
    tail = newNode;
  }
  else if((valToInsert >= head->getValue())&&(valToInsert < tail->getValue()))
    //value in the middle OR value equals existing ones in the list
    //except the last item
  {
    while (temp != NULL)
    {
      if (!((valToInsert >= temp->getValue())
          && (valToInsert < (temp->getNext())->getValue())))
      {
        temp = temp->getNext(); //assign temp to next node and keep searching
      }
      else //valToInsert is less than temp
      { //time to insert the newNode between two values
        newNode = new ListNodeClass<T>(temp, valToInsert, temp->getNext());
        //temp should point to newNode to arrange its prev and next connections
        //temp = newNode;
        //set the next and previous pointers of newNode temp is now pointing to
        newNode->setBeforeAndAfterPointers();
        //temp points to NULL so that middle value insertion search can end
        temp = NULL;
      }
    } //end of insert-in-the-middle search
  } //end of if-newNode's value-to-be-in-the-middle case
} //end of insertValue implementation
