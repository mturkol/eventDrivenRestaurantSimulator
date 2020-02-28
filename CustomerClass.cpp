/*
 * CustomerClass.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: Mert Turkol
 * Description: Implementation details for the customer interface
 */

#include <iostream>
#include "CustomerClass.h"
using namespace std;

//overloads the << operator for printing customer ID number
ostream& operator<<(ostream &os, const CustomerClass &customerObj)
{
  os << customerObj.getCustomerID();
  return (os);
}

//Gets and returns the total number of customers
int CustomerClass::getNumCustomers() const
{
  return numCustomerObjs;
}

//Returns the customer number
int CustomerClass::getCustomerID() const
{
  return cID;
}

//Returns the arrival time of the customer
int CustomerClass::getArrivalTime() const
{
  return arrivalTime;
}

//Returns the departure time of the customer
int CustomerClass::getDepartureTime() const
{
  return depTime;
}

//Sets the customer ID
void CustomerClass::setID(int inID)
{
  cID = inID;
}

//Sets the customer arrival time
void CustomerClass::setArrivalTime(int inArrvTime)
{
  arrivalTime = inArrvTime;
}

//Sets the departure time of the customer
void CustomerClass::setDepartureTime(int inDepTime)
{
  depTime = inDepTime;
}

//Using all the setter functions, sets the information of a customer
void CustomerClass::setCustomerInfo(int inID, int inArrvTime, int inDepTime)
{
  setID(inID);
  setArrivalTime(inArrvTime);
  setDepartureTime(inDepTime);
}
