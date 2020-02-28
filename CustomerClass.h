/*
 * CustomerClass.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Mert Turkol
 * Description: Header file for the customer interface
 */

#ifndef CUSTOMERCLASS_H_
#define CUSTOMERCLASS_H_

using namespace std;

class CustomerClass
{
  private:
    int cID; //customer identification number within the queue
    int arrivalTime; //time that the customer arrived
    int depTime; //time that the customer departures
    static int numCustomerObjs;
  public:
    //Default ctor for CustomerClass objects with no parameters.
    //Needed for QueueClass destructor as a temporary object that makes use of
    //dequeue op. within it to destroy the objects contained in its nodes.
    CustomerClass():cID(0), arrivalTime(0),depTime(0)
    {
    }

    //Value constructor to initialize the instance variables
    //according to the parameters.
    CustomerClass(int inArrvTime)
    {
      numCustomerObjs++; //increase the counter for #customers created
      cID = numCustomerObjs; //customer ID is set to the new #customer
      arrivalTime = inArrvTime; //arrival time of the customer is set
                                //to the related arrival event time
    }

    //Returns the total #customers created
    int getNumCustomers() const;

    //Returns the customer ID number
    int getCustomerID() const;

    //Returns the arrival time of the customer
    int getArrivalTime() const;

    //Returns the departure time of the customer
    int getDepartureTime() const;

    //Sets the customer ID
    void setID(int inID);

    //Sets the customer arrival time
    void setArrivalTime(int inArrvTime);

    //Sets the departure time of the customer
    void setDepartureTime(int inDepTime);

    //Using all the setter functions, sets the information of a customer
    void setCustomerInfo(int inID, int inArrvTime, int inDepTime);
};

//overloads the << operator for printing customer ID number
ostream& operator<<(ostream &os, const CustomerClass &customerObj);

#endif /* CUSTOMERCLASS_H_ */
