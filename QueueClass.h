/*
 * QueueClass.h
 *
 *  Created on: Mar 24, 2014
 *      Author: Mert TURKOL
 * Description: Interface for a First-In-First-Out Queue. Uses doubly linked
 * nodes.
 */

#ifndef QUEUECLASS_TEMPLATE_H_
#define QUEUECLASS_TEMPLATE_H_

#include <iostream>
#include "ListNodeClass.h"
using namespace std;

template <class T>
class QueueClass
{
  private:
    ListNodeClass<T> *queueFront; //1st item in the list
    ListNodeClass<T> *queueEnd; //Last item in the list

  public:
    //Determines whether the queue is empty.
    //Returns true if the queue is empty, otherwise returns false.
    bool checkEmptyQueue() const;

    //Adds queueElementToInsert to the end of the queue.
    void enqueue(const T &queueValToInsert);


    //Remove the first element of the queue.
    bool dequeue(T &frontValToRemove);

    //Provides the value stored in the front node. If the the queue is empty,
    //then frontVal remains unchanged and false is returned. Otherwise,
    //the function returns true, and the reference parameter frontVal will contain
    //a copy of the value at queue's front location.
    bool getFront(T &frontVal);

    //Prints the contents of the queue from front to end to the screen.
    //For debugging purposes
    void printQueueForward() const;

    //Default constructor. Initializes the front and end pointers to NULL
    //to have a queue in empty state.
    QueueClass():queueFront(NULL), queueEnd(NULL)
    {
    }

    //Copy constructor
    //QueueClass(const QueueClass<T>& otherQueue):

    //Destructor for the queue. Destroys all the elements within the sorted
    //doubly linked list properly and frees allocated memory if there exists
    //such elements in it.
    ~QueueClass()
    {
      ListNodeClass<T> *temp = queueFront;
      T queueValToRemove;
      bool statusQueueRemoveFront;

      while(temp != NULL)
      {
        statusQueueRemoveFront = dequeue(queueValToRemove);
        temp = temp -> getNext();
      }
    }

    //Function to initialize the queue to an empty state.
    //void initializeQueue();

    //Returns the last element of the queue. If the queue is empty, program
    //issues a warning, otherwise; the last element of the queue is returned.
    //T getEnd() const;
};

#include "QueueClass.inl"
#endif /* QUEUECLASS_TEMPLATE_H_ */
