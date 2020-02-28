/*
 * ServerClass.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: Mert Turkol
 * Description: Source file that defines server interface implementations
 */

#include <iostream>
#include "ServerClass.h"
using namespace std;

//Returns the free/busy status of the server. Returns true if the server is
//free, otherwise returns false to indicate that the server is occupied
bool ServerClass::isFree()
{
  return statusFree;
}

//Sets the server to busy mode
void ServerClass::setBusy()
{
  statusFree = false;
}

//Sets the server to free mode
void ServerClass::setFree()
{
  statusFree =  true;
}

//Sets the server's service time for the latest customer to be served
void ServerClass::setServiceTime(int inTime)
{
  serviceTime = inTime;
}

//Gets the service time of the latest customer the server is dealing w/
int ServerClass::getServiceTime() const
{
  return serviceTime;
}
