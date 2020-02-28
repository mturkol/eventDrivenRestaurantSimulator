//============================================================================
// Name        : proj3.cpp
// Author      : Mert Turkol
// Date        : 03/20/2014
// Version     : 1.0
// Copyright   : GNU General Public License
// Description : Implementation of a server simulation in a fast food
// restaurant. Customers come into the restaurant on a pseudo-random basis,
// where each customer enters the restaurant some amount of time after the
// previous customer. The amount of time between customers is drawn from a
// uniform distribution, which has specified min and max values.
// Restaurant has only a single server. If the server is not currently waiting
// on a customer, a new customer can immediately get served. Otherwise,
// the customer will have to wait in a first-in-first-out queue and wait their
// turn. The amount of time it takes for the server to wait on the customer
// is drawn from a normal distribution with a specified mean and Std.
//============================================================================

#include <iostream>
#include "ListNodeClass.h"
#include "SortedListClass.h"
#include "EventClass.h"
#include "QueueClass.h"
#include "ServerClass.h"
#include "CustomerClass.h"
#include "randomNumGenFuncs.h"
#include "SimHandleClass.h"
#include "EventClass.h"
#include "StackClass.h"
#include "constants.h"
#include "getInput.h"
using namespace std;

int CustomerClass::numCustomerObjs = 0; //for static member variable of
//CustomerClass objects that increments # of customers each time one is created

int main()
{
  int simEndTime; //decides how long the simulation is going to run
  int seedVal; //random number generator seed
  int uniDistroMin; //min. of uniform distro range
  int uniDistroMax; //max. of uniform distro range
  float normalDistroMean; //mean of normal distribution for server service time
  float normalDistroStdDev;//Std of normal distribution for server service time

  getInput(simEndTime, seedVal, uniDistroMin,
           uniDistroMax, normalDistroMean,
           normalDistroStdDev); //gets simulation parameters as user input

  setSeed(seedVal); //set the simulation seed with the specified input value
  int clock = 0; //simulation beginning time

  //create an empty event list (EL)
  SortedListClass<EventClass> eventList;
  //Decide when the first customer will arrive and create that event
  int firstArrivalTime(getUniform(uniDistroMin, uniDistroMax));
  EventClass firstArrival(firstArrivalTime, CUSTOMER_ARRIVAL);
  //Add the first customer arrival event to EL
  eventList.insertValue(firstArrival);
  //create an empty customer queue
  QueueClass<CustomerClass> customerQueue;
  //create one server with free status
  ServerClass server;

  //create and initialize an object of SimHandleClass
  //to control the simulation
  SimHandleClass mySim(uniDistroMin, uniDistroMax,
                      normalDistroMean, normalDistroStdDev, clock, simEndTime);

  EventClass currentEvent; //event object that will be taken from the EL
  bool newEventExists; //to see if there's a new event to be grabbed in EL

  while (mySim.getSimClock() < simEndTime) //loop until simulation end time.
  {

    newEventExists = eventList.getElemAtIndex(0, currentEvent);
    if((newEventExists && currentEvent.getEventTime() < simEndTime))
    {
      //get the first event from the event list and then shrink the list
      currentEvent = mySim.getEventAndShrinkList(eventList);
      //advance the simulation clock the time of the event to be handled
      mySim.advanceClock(currentEvent);
      //take action depending on whether it is an arrival or departure event
      if ((currentEvent.getEventType()) == CUSTOMER_ARRIVAL)
      //when the current event to be handled is arrival
      {
        mySim.handleArrival(currentEvent,
                            eventList,
                            server,
                            customerQueue);
      }
      else //when the current event to be handled is departure
      {
      mySim.handleDeparture(currentEvent,
                            eventList,
                            server,
                            customerQueue);
      }
    }
    else //when there's an event that might happen after the simulation endtime
    {
      mySim.setSimClock(simEndTime); //immediately set the clock to endtime
    }
  }
  //Compute and print the statistics of the simulation
  if (!customerQueue.checkEmptyQueue())
  {//when there're remaining customers in the customer queue
    CustomerClass customerToDequeue; //temp variable to be used in getting
                                     //stats of the remaning customers

    while(!customerQueue.checkEmptyQueue())//loop until all remaining customer
                                           //stats are obtained.
    {

      customerQueue.dequeue(customerToDequeue); //remove the customer from line
      mySim.increaseTotalWaitingTime(
                                    mySim.getSimClock()
                                    - customerToDequeue.getArrivalTime()
                                    ); //update total waiting time in queue
    }
  }

  mySim.printStatistics(); //print the statistics of the simulation
  //free dynamically alloc. memory for the first customer
  delete firstArrival.getCustomer();

  return 0;
}
