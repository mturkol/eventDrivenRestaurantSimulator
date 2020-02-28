/*
 * QueueClass.inl
 *
 *  Created on: Mar 24, 2014
 *      Author: Mert TURKOL
 * Description: Implementations of a templated First-In-First-Out Queue that
 *              uses LinkNodeClass with node values, previous and next pointers
 */

#include <iostream>
#include "QueueClass.h"
#include "ListNodeClass.h"
using namespace std;

//Determines whether the queue is empty.
//Returns true if the queue is empty, otherwise returns false.
template <class T>
bool QueueClass<T>::checkEmptyQueue() const
{
  bool isQueueEmpty = false; //bool var. to return

  if(queueFront == NULL) //when the queue is empty
  {
    isQueueEmpty = true;
  }

  return isQueueEmpty; //report back the queue empty status
}

//Adds queueElement to the end of the queue.
template <class T>
void QueueClass<T>::enqueue(const T &queueValToInsert)
{
  ListNodeClass<T> *newQueueItem;

  if (queueFront == NULL) //means queue is empty
  {
    newQueueItem = new ListNodeClass<T>(NULL, queueValToInsert, NULL);
    queueFront = newQueueItem;
    queueEnd = newQueueItem;
  }
  else
  { //when newQueueItem should be the last
    newQueueItem = new ListNodeClass<T>(queueEnd, queueValToInsert, NULL);
    //next pointer of what queueEnd was pointing to now points to newQueueItem
    queueEnd->setNextPointer(newQueueItem);
    //queueEnd now points to our newQueueItem which is the last item
    queueEnd = newQueueItem;
  }
}

//Remove the first element of the queue.
template <class T>
bool QueueClass<T>::dequeue(T &frontValToRemove)
{
  bool statusDequeue = true;
  ListNodeClass<T> *temp;

  if (queueFront == NULL)
  {
    cout << "Queue is empty, can't remove from the queue!" << endl;
    statusDequeue = false;
  }
  else
  {
    temp = queueFront;
    queueFront = temp->getNext();
    frontValToRemove = temp->getValue();
    //Free the memory we dynamically allocated with dequeue function
    delete temp;

    //the purpose of following check is to prevent the use of previous pointer
    //setter function when queueFront is pointing to NULL after the queue is
    //cleared using the dtor which actually calls dequeue to accomplish its job
    //Prevents seg-fault error while emptying the queue
    if (queueFront != NULL)
    { //when there are no elements in the queue to remove from
      //the previous pointer of the what front is pointing to now becomes NULL
      queueFront->setPreviousPointer(NULL);
    } //end of seg-fault prevention case when temp->getNext() points to NULL
  } //end of if-queue-is-NOT-empty case

  return (statusDequeue);
}

//Prints the contents of the queue from front to end to the screen.
//For debugging purposes.
template <class T>
void QueueClass<T>::printQueueForward() const
{
  ListNodeClass<T> *temp = queueFront;
  cout << "Forward Queue Contents Follow:" << endl;

  while (temp != NULL) //loop until end of the queue is reached
  {
    cout << "  " << temp->getValue() << endl; //print current item
    temp = temp->getNext(); //jump to the next item in the queue
  }
  cout << "End Of Queue Contents" << endl;
  //}
}

//Provides the value stored in the front node. If the the queue is empty,
//then frontVal remains unchanged and false is returned. Otherwise,
//the function returns true, and the reference parameter frontVal will contain
//a copy of the value at queue's front location.
template <class T>
bool QueueClass<T>::getFront(T &frontVal)
{
  bool frontItemFound = !checkEmptyQueue();

  if(frontItemFound) //when the queue is not empty
  {
    frontVal = queueFront -> getValue();//access the first item value
  }
  else
  {
    cout << "Nothing at the front of the queue exists. "
         << "The queue is empty!" << endl;
  }

  return(frontItemFound); //report the value of first item in the queue queue
}
//Function to initialize the queue to an empty state.
//template <class T>
//void QueueClass<T>::initializeQueue()
//{
//
//}

//Returns the last element of the queue. If the queue is empty, program
//terminates otherwise, the last element of the queue is returned.
/*template <class T>
T QueueClass<T>::getEnd() const
{
  int lastVal; //the last item value in the queue queue to be returned
  //in the queue to decide which one is going to be the last using an index

  if (!checkEmptyQueue()) //when the queue is not empty
  {
  //access the last item value
    queueList->getElemAtIndex((queueList->getNumElems())-1, lastVal);
  }
  else
  {
    cout << "Nothing at the end of the queue exists. "
         << "The queue is empty!" << endl;
  }

  return (lastVal); //report the value of last item in the queue
}*/
