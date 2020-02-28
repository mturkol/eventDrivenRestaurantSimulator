/*
 * ServerClass.h
 *
 *  Created on: Mar 25, 2014
 *      Author: Mert Turkol
 * Description: Header file for the server interface
 */

#ifndef SERVERCLASS_H_
#define SERVERCLASS_H_

#include "CustomerClass.h"
using namespace std;

class ServerClass
{
  private:
    bool statusFree; //Server state is considered "free" if true, otherwise
    int serviceTime; //time required to serve the current customer

  public:
    ServerClass()
    {
      statusFree = true;
      //currentCustomer = NULL;
      serviceTime = 0;
    }

    //Determines free/busy status of the server. Returns true if the server is
    //free, otherwise returns false to indicate that the server is occupied
    bool isFree();

    //Sets the server to busy mode
    void setBusy();

    //Sets the server to free mode
    void setFree();

    //Sets the service time of the server for the current customer
    void setServiceTime(int inTime);

    //Gets the service time of the latest customer the server is dealing w/
    int getServiceTime() const;

    //Gets the current customer the server is dealing with
    CustomerClass* getCurrentCustomer() const;
};

#endif /* SERVERCLASS_H_ */
