/*
 * SimHandleClass.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: Mert Turkol
 * Description: Contains the implementations of simulation run handling
 * interface
 */

#include <iostream>
#include "SimHandleClass.h"
#include "SortedListClass.h"
#include "EventClass.h"
#include "QueueClass.h"
#include "ServerClass.h"
#include "CustomerClass.h"
#include "randomNumGenFuncs.h"
using namespace std;

//Increments the total waiting time of the queue. Used for updating the total
//wait time of the customers that were still waiting in the queue when the
//simulation ends
void SimHandleClass::increaseTotalWaitingTime(int inWaitTime)
{
  totalWaitingTime += inWaitTime;
}

//Computes the statistics of the simulation and prints them
void SimHandleClass::printStatistics()
{
  //Print the statistics
  cout << endl;
  cout << "Now printing statistics... " << endl;
  //Print total # customers simulated
  cout << "Total # customers simulated: "
         << totalCustomers << endl;
  //Print how much time the server was busy attending customers
  cout << "Percentage of time server was busy: %"
       << static_cast<float>(serverBusyTime) /
          static_cast<float>(simEndTime) * 100 << endl;
  //print percentage of customers that got served
  cout << "Percentage of customers that the server completed serving: %"
       << static_cast<float>(customersServed) /
          static_cast<float>(totalCustomers) * 100  << endl;
  //print the average service time of the server
  cout << "Average service time: "
       << static_cast<float>(serverBusyTime) /
          static_cast<float>(totalCustomers) << " time units." << endl;
  //print percentage of customers waited
  cout << "Percentage of customers waited in the line: %"
       << static_cast<float>(customersWaited) /
          static_cast<float>(totalCustomers) * 100 << endl;
  //print the average waiting time of customers in the queue
  cout << "Average waiting time: "
       << static_cast<float>(totalWaitingTime) /
          static_cast<float>(customersWaited) << " time units." << endl;
  //print the longest line throughout the simulation
  cout << "The longest line during the simulation had "
       << longestLine << " number of customers." << endl;


}
//Gets the simulation clock and returns that
int SimHandleClass::getSimClock() const
{
  return simClock;
}

//Sets the simulation clock to a specific time
void SimHandleClass::setSimClock(int timeToJump)
{
  simClock = timeToJump;
}

//Advances the simulation clock according to happening time of the event to
//be handled
void SimHandleClass::advanceClock(const EventClass &eventToHandle)
{
  simClock = eventToHandle.getEventTime();
}

//Gets the first event on the event list and returns it to be passed
//to event handling member functions. Shrinks the event list by one item
//by removing the event it gets.
EventClass SimHandleClass::getEventAndShrinkList(
                           SortedListClass<EventClass> &eventList)
{
  //creating a temporary event object to get the first event information
  //from the event list and assign that to it
  EventClass firstEvent;

  //get the first element of event list
  bool firstEventReached = eventList.getElemAtIndex(0, firstEvent);

  if (firstEventReached) //there should be an event on the event list
  //This if case can be useful for debugging/simulation tracking purposes
  {
  //remove the first event from the event list
    eventList.removeFront(firstEvent);
  }

  return firstEvent;
}

//Handles an arrival event
void SimHandleClass::handleArrival(const EventClass &arrivalEvent,
                    SortedListClass<EventClass> &eventList,
                    ServerClass &server,
                    QueueClass<CustomerClass> &customerQueue)
{
  //inform the simulation runner
  cout << "Customer " << ((arrivalEvent.getCustomer())->getCustomerID())
       << " has arrived at the restaurant at time unit "
       << simClock << endl;
  totalCustomers++;
  //update the new uniform distro min and max ranges to schedule new arrival
  int newUniMin = uniMin + arrivalEvent.getEventTime();
  int newUniMax = uniMax + arrivalEvent.getEventTime();
  //schedule the next arrival event
  int nextArrivalTime = getUniform(newUniMin, newUniMax);

  //create a new arrival event with the scheduled arrival time
  EventClass nextArrivalEvent(nextArrivalTime, CUSTOMER_ARRIVAL);
  //put the created customer to the customerArray
  customerArray[nextArrivalEvent.getCustomer()->getNumCustomers()] =
                nextArrivalEvent.getCustomer();

  //add the new arrival event to the event list
  eventList.insertValue(nextArrivalEvent);

  //check if the server is busy
  bool serverStatusFree = server.isFree();

  //The arrival event is going to be dealt with the associated arrived customer
  CustomerClass* arrivedCustomer = arrivalEvent.getCustomer();

  if(!serverStatusFree)//when the server is busy with another customer and
                      //the arriving customer is to be put into the queue
  {
    //inform the simulation runner
    cout << "Server is currently busy. Customer "
         << arrivedCustomer->getCustomerID()
         << " started to wait in queue."
         << endl;  //inform the simulation runner

    //customer get in the line
    customerQueue.enqueue(*arrivedCustomer);
    //increase the #customers waited in queue
    customersWaited++;
    //update the current simulation time customer line length
    currentLineLength++;
    //update the longest line if necessary
    if(currentLineLength >= longestLine)
    {
      longestLine = currentLineLength;
    }
  }
  else //when the server is free and ready to serve the arriving customer
  {
    //inform the simulation runner
    cout << "Server is free and started to serve Customer "
         << arrivedCustomer->getCustomerID()
         << " at time unit "<< simClock << endl;

    server.setBusy(); //set the server busy
    //schedule a departure event for the customer that is ready to be served
    int newServiceTime = getNormal(normalMean, normalStdDev);
    //set the server's service time to the scheduled service
    server.setServiceTime(newServiceTime);
    //compute the departure time of the customer that's going to be served
    //using the scheduled service time
    int departureTime = simClock + newServiceTime;
    //set the departure time of the arrived customer
    arrivedCustomer->setDepartureTime(departureTime);
    //create a new departure event with the scheduled departure time
    EventClass immediateDepartureEvent(departureTime, CUSTOMER_DEPARTURE);
    immediateDepartureEvent.setCustomer(arrivedCustomer);
    //add the new arrival event to the event list
    eventList.insertValue(immediateDepartureEvent);
  }
}

//Handles a departure event
void SimHandleClass::handleDeparture(const EventClass &departureEvent,
                    SortedListClass<EventClass> &eventList,
                    ServerClass &server,
                    QueueClass<CustomerClass> &customerQueue)
{
  //inform the simulation runner
  cout << "Customer " << (departureEvent.getCustomer())->getCustomerID()
       << " is done being served by the Server at time Unit "
       << simClock << ". "
       << "Customer "<< (departureEvent.getCustomer())->getCustomerID()
       <<" is leaving the restaurant." << endl;
  //update the server busy time
  serverBusyTime += server.getServiceTime();
  //update #customers served
  customersServed++;

  bool freeQueueStatus = customerQueue.checkEmptyQueue();

  if (freeQueueStatus)//when there isnt't anyone in the customer queue
  {
    //Make the Server idle.
    server.setFree();
    //Change Server's service Time to 0
    server.setServiceTime(0);
    //Inform the simulation runner
    cout << "Queue is empty. Server is now free //update the current simulation time line lengthand waiting for"
         << " the next customer to arrive."
         << endl;
  }
  else //when there is at least one person waiting in the customer queue
  {
    //creates a holder of information for the fist waiting customer in queue
    CustomerClass waitingCustomer;

    //take the 1st waiting customer off from the queue
    customerQueue.dequeue(waitingCustomer);
    //update the current simulation time customer line length
    currentLineLength--;

    //add the waiting time of the customer that will be served to the total
    //waiting time
    totalWaitingTime += simClock - waitingCustomer.getArrivalTime();

    //Get a service time for the waiting customer that is going to be served
    int newServiceTime = getNormal(normalMean, normalStdDev);

    //set the server's service time to the scheduled service
    server.setServiceTime(newServiceTime);
    //compute the departure time of the customer that's going to be served
    //using the scheduled service time
    int newDepartureTime = simClock + newServiceTime;

    CustomerClass* customerToBeServed = departureEvent.getCustomer();

    customerToBeServed->setID(waitingCustomer.getCustomerID());
    customerToBeServed->setArrivalTime(waitingCustomer.getArrivalTime());
    //set the departure time of the customer to be dealt with
    customerToBeServed->setDepartureTime(newDepartureTime);
    //create a new departure event with the scheduled departure time
    EventClass newDepartureEvent(newDepartureTime, CUSTOMER_DEPARTURE);
    //set the customer the departure should be related to
    newDepartureEvent.setCustomer(customerToBeServed);
    //add the new arrival event to the event list
    eventList.insertValue(newDepartureEvent);
    //Inform the simulation runner
    cout << "Customer "
         << customerToBeServed->getCustomerID()
         << " goes to the server and starts getting served "
         << "at time unit " << simClock << endl;
  }
}
