/*
 * SimHandleClass.h
 *
 *  Created on: Mar 27, 2014
 *      Author: Mert Turkol
 * Description: Introduces the the interface that handles the simulation run
 */

#ifndef SIMHANDLECLASS_H_
#define SIMHANDLECLASS_H_

#include "SortedListClass.h"
#include "EventClass.h"
#include "QueueClass.h"
#include "ServerClass.h"
#include "CustomerClass.h"
#include "randomNumGenFuncs.h"
using namespace std;

class SimHandleClass
{
  private:
    int uniMin; //Min point range of Uniform Distro for assigning
                //customer arrival times
    int uniMax; //Max point range of Uniform Distro for assigning
                //customer arrival times
    float normalMean; //Mean of Normal Distro for assigning service time
    float normalStdDev; //Standard deviation of the Normal Distro for
                        //assigning for service time
    int simClock; //simulation clock
    int simEndTime; //simulation end time
    CustomerClass **customerArray; //points to an array of pointers
                                   // that point to customers created
    int totalCustomers; //#customers simulated
    int customersServed; //#customers served
    int customersWaited; //#customers that waited in line
    int serverBusyTime; //amount of time the server was busy
    float totalWaitingTime; //total time that all the customers waited in line
    int longestLine; //the length of the longest line during simulation
    int currentLineLength; //length of the line at a specific event time

  public:
    //Value ctor that initializes the simulation controller object with
    //specified run parameters. Also initializes the required variables to hold
    //statistical information.
    SimHandleClass(int inUniMin, int inUniMax, float inNormalMean,
                   float inNormalStdDev, int inClock, int inEndTime)
    {
      uniMin = inUniMin;
      uniMax = inUniMax;
      normalMean = inNormalMean;
      normalStdDev = inNormalStdDev;
      simClock = inClock;
      simEndTime = inEndTime;
      int maxPossibleCustomers = simEndTime / uniMin;
      customerArray = new CustomerClass*[maxPossibleCustomers];
      totalCustomers = 0;
      customersServed = 0;
      customersWaited = 0;
      serverBusyTime = 0;
      totalWaitingTime = 0;
      longestLine = 0;
      currentLineLength  = 0;
    }

    ~SimHandleClass()
    {
      for (int i = 0; i < (simEndTime/uniMin); i++)
      {
        delete customerArray[i]; //intended for the innermost 1D arrays
        //of pointers that point to objects of ColorClass
      }
      delete [] customerArray;
    }

    //Increments the total waiting time of the queue. Used for updating the total
    //wait time of the customers that were still waiting in the queue when the
    //simulation ends
    void increaseTotalWaitingTime(int inWaitTime);

    //Function that computes statistics about the simulation and prints them
    void printStatistics();

    //Advances the simulation clock according to happening time of the event to
    //be handled
    void advanceClock(const EventClass &eventToHandle);

    //Handles an arrival event
    void handleArrival(const EventClass &arrivalEvent,
                        SortedListClass<EventClass> &eventList,
                        ServerClass &server,
                        QueueClass<CustomerClass> &customerQueue);

    //Handles a departure event
    void handleDeparture(const EventClass &departureEvent,
                        SortedListClass<EventClass> &eventList,
                        ServerClass &server,
                        QueueClass<CustomerClass> &customerQueue);

    //Gets the first event on the event list and returns it to be passed
    //to event handling member functions. Shrinks the event list by one item
    //by removing the event it gets.
    EventClass getEventAndShrinkList(SortedListClass<EventClass> &eventList);

    //Gets the simulation clock and returns that
    int getSimClock() const;

    //Sets the simulation clock to a specific time
    void setSimClock(int timeToJump);
};

#endif /* SIMHANDLECLASS_H_ */
