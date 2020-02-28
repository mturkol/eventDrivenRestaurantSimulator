/*
 * EventClass.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: Mert Turkol
 * Description: Source file contains the implementations of Event interface
 */
#include <iostream>
#include "EventClass.h"
#include "CustomerClass.h"
using namespace std;

//overloads the << operator for printing event time
ostream& operator<<(ostream &os, const EventClass &eventObj)
{
  os << eventObj.getEventTime();
  return (os);
}

//Returns the time a specific event instance is supposed to happen
int EventClass::getEventTime() const
{
  return eventTime;
}

//Returns the type of an event instance
int EventClass::getEventType() const
{
  return eventType;
}

//Returns the pointer pointing to the customer object associated with
//the event
CustomerClass* EventClass::getCustomer() const
{
  return eventCustomer;
}

//Sets the pointer to customer the event is supposed to act on
void EventClass::setCustomer(CustomerClass *customerToPoint)
{
  eventCustomer = customerToPoint;
}
