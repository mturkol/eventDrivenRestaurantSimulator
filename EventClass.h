/*
 * EventClass.h
 *
 *  Created on: Mar 26, 2014
 *      Author: Mert Turkol
 * Description: Header file for the events interface
 */

#ifndef EVENTCLASS_H_
#define EVENTCLASS_H_

#include <iostream>
#include "CustomerClass.h"
#include "constants.h"
using namespace std;

class EventClass
{
  private:
    int eventType; //Determines whether the type of the event is
              //CUSTOMER_ARRIVAL (1), or CUSTOMER_DEPARTURE (0)
    CustomerClass *eventCustomer; //points to a specific customer that an
                                  //event object is going to be initiated w/
    int eventTime; //Determines when the event is going to take place

  public:

    //default ctor
    EventClass():eventType(CUSTOMER_DEPARTURE),eventCustomer(NULL),eventTime(0)
    {
    }

    //value ctor that initializes an event
    EventClass(int inEventTime, int inEventType)
    {
      eventTime = inEventTime; //created event object happens @ inEventTime

      if (inEventType == CUSTOMER_ARRIVAL)
      {//when a new customer arrival event is created
        eventType = inEventType;
        //created event object represents customer arrival

        //dynamically allocate memory for the new customer object
        //inEventTime will be passed to CustomerClass object's value ctor
        //in order to assign it to that customer's arrivalTime
        //private static member numCustObjs defined within CustomerClass
        //will automatically update itself and assign the customer ID of the
        //new customer object
        eventCustomer = new CustomerClass(inEventTime);
      }
      else
      {
        eventType = CUSTOMER_DEPARTURE;
        eventCustomer = NULL;
      } //end of event initialization definitions
    }//end of value ctor. If the event is customer departure, then the customer
     //to point to will be decided after a peek into the front value of the
     //queue from outside the object creation process.

    //Returns the time a specific event instance is supposed to happen
    int getEventTime() const;

    //Returns the type of an event instance
    int getEventType() const;

    //Returns the pointer pointing to the customer object associated with
    //the event
    CustomerClass* getCustomer() const;

    //Sets the pointer to customer the event is supposed to act on
    void setCustomer(CustomerClass *customerToPoint);

    //overloads the logic comparison operator >. Intended for proper comparison
    //of eventTimes within the sorted doubly linked eventList
    bool operator>(const EventClass &rhsEvent) const
    {
      return ((eventTime) > rhsEvent.eventTime);
    }

    //overloads the logic comparison operator <. Intended for proper comparison
    //of eventTimes within the sorted doubly linked eventList
    bool operator<(const EventClass &rhsEvent) const
    {
      return ((eventTime) < rhsEvent.eventTime);
    }

    //overloads the logic comparison operator ==. Intended for proper comparison
    //of eventTimes within the sorted doubly linked eventList
    bool operator==(const EventClass &rhsEvent) const
    {
      return ((eventTime) == rhsEvent.eventTime);
    }

    //overloads the logic comparison operator !=. Intended for proper comparison
    //of eventTimes within the sorted doubly linked eventList
    bool operator!=(const EventClass &rhsEvent) const
    {
      return ((eventTime) != rhsEvent.eventTime);
    }

    //overloads the logic comparison operator >=. Intended for proper comparison
    //of eventTimes within the sorted doubly linked eventList
    bool operator>=(const EventClass &rhsEvent) const
    {
      return ((eventTime) >= rhsEvent.eventTime);
    }

    //overloads the logic comparison operator <=. Intended for proper comparison
    //of eventTimes within the sorted doubly linked eventList
    bool operator<=(const EventClass &rhsEvent) const
    {
      return ((eventTime) <= rhsEvent.eventTime);
    }
};

//overloads the << operator for printing event time
ostream& operator<<(ostream &os, const EventClass &eventObj);

#endif /* EVENTCLASS_H_ */
