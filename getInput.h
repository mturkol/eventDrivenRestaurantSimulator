/*
 * getInput.h
 *
 *  Created on: Mar 28, 2014
 *      Author: Mert Turkol
 * Description: Gets simulation run parameters as input. Header file
 */


#ifndef GETINPUT_H_
#define GETINPUT_H_

#include <iostream>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

bool getInput(int &simEndTime, int &seedVal, int &uniDistroMin,
              int &uniDistroMax, float &normalDistroMean,
              float &normalDistroStdDev)
{
  //checks if valid simulation Endtime was entered.
  bool validSimEndTime = false;
  //checks if valid random # generator seed value was enterd
  bool validSeed =false;
  //checks if valid uniform distro parameters are entered.
  bool validUni = false;
  //checks if valid normal distro parameters are entered
  bool validNormal = false;

  cout << "Welcome to the event-driven, single server restaurant simulation!"
       << endl;

  cout << "You will need to enter simulation parameters such as:" << endl;
  cout << "Simulation end time, random # generator seed" << endl;
  cout << "The uniform distribution minimum and maximum ranges to decide "
       << "random customer arrival times" << endl;
  cout << "The normal distribution mean and standard deviation to decide "
       << "random server service times." << endl;
  cout << endl;

  while(!validSimEndTime)
  {
    cout << "Please input simulation time: ";
    cin >> simEndTime;

    if (cin.fail() || simEndTime < 1)
    {
      cin.clear(); //take the input stream out of fail state
      cin.ignore(200, '\n'); //allow new data to be consumed in the future
      cout << "Error! "
           << "Please enter integer greater than 1 for valid simulation time!"
           << endl;
    }
    else
    {
      validSimEndTime = true;
    }
  }
  cout<<endl;
  while(!validSeed)
  {
    cout << "Please input random number generator seed: ";
    cin >> seedVal;

    if (cin.fail())
    {
      cin.clear(); //take the input stream out of fail state
      cin.ignore(200, '\n'); //allow new data to be consumed in the future
      cout << "Error! Please enter integer for valid seed value"
           << endl;
    }
    else
    {
      validSeed = true;
    }
  }
  cout<<endl;

  while(!validUni)
  {
    cout << "Please input minimum and maximum values for uniform "
         << "distribution respectively: ";
    cin >> uniDistroMin >> uniDistroMax;
    if (cin.fail() || uniDistroMin < 0 || uniDistroMax <= 0
       || uniDistroMax <= uniDistroMin)
    {
      cin.clear(); //take the input stream out of fail state
      cin.ignore(200, '\n'); //allow new data to be consumed in the future
      cout << "Error! Please enter valid integer values for uniform "
           << "distribution minimum and maximum while the maximum has to be "
           << "greater than the minimum value"
           << endl;
    }
    else
    {
      validUni = true;
    }
  }
  cout<<endl;

  while(!validNormal)
  {
    cout << "Please input a mean and standard deviation for normal "
         << "distribution respectively: ";
    cin >> normalDistroMean >> normalDistroStdDev;
    if (cin.fail() || normalDistroMean < 0 || normalDistroStdDev < 0
        || normalDistroStdDev > normalDistroMean)
    {
      cin.clear(); //take the input stream out of fail state
      cin.ignore(200, '\n'); //allow new data to be consumed in the future
      cout << "Error! Please enter valid float values for normal "
           << "distribution mean and standard deviation which both have to be "
           << " greater than 0 while the standard deviation being "
           <<"less than mean"<< endl;
    }
    else
    {
      validNormal = true;
    }
  }
  cout<<endl;
  cout << "Simulation parameters are as follows:" << endl;

  cout << "Simulation End Time: " << simEndTime << endl;
  cout << "Seed value: " << seedVal << endl;
  cout << "Uniform Distribution Min Value: " << uniDistroMin << endl;
  cout << "Uniform Distribution Max Value: " << uniDistroMax << endl;
  cout << "Normal Distribution Mean Value: " <<  normalDistroMean << endl;
  cout << "Normal Distribution Std Value: " <<  normalDistroStdDev << endl;
  cout << endl;

  char runKey;
  bool pressedKey = false;

  while (!pressedKey)
  {
    cout << "Please press the (r) key to start the simulation." << endl;
    cin >> runKey;

    if (cin.fail() || runKey != 'r')
    {
      cin.clear(); //take the input stream out of fail state
      cin.ignore(200, '\n'); //allow new data to be consumed in the future
    }
    else
    {
      pressedKey = true;
    }

  }

  bool validInput = (validSimEndTime && validSeed && validUni && validNormal);

  return validInput;
}

#endif /* GETINPUT_H_ */
