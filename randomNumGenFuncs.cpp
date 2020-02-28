/*
 * randomNumGenFunc.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: Mert Turkol
 * Description: Implementation of global random # generation functions
 */

#include "randomNumGenFuncs.h"
#include <cstdlib>
using namespace std;

//sets the seed for random # draws
void setSeed(int seedVal)
{
  srand(seedVal);
}

//draws a random # within a uniform distribution with specified min-max range
int getUniform(int min, int max)
{
  int uniRand;
  uniRand = rand() % ((max + 1) - min) + min;
  return (uniRand);
}

//draws a random # within a normal distribution with specified mean and stdDev
int getNormal(float mean, float stdDev)
{
  const int NUM_UNIFORM = 12;
  const int MAX = 1000;
  const float ORIGINAL_MEAN = NUM_UNIFORM * 0.5;
  float sum;
  int i;
  float standardNormal;
  float newNormal;
  int uni;

  sum = 0;
  for (i = 0; i < NUM_UNIFORM; i++)
  {
    uni = rand() % (MAX + 1);
    sum += uni;
  }

  sum = sum / MAX;
  standardNormal = sum - ORIGINAL_MEAN;
  newNormal = mean + stdDev * standardNormal;

  if (newNormal < 0)
  {
    newNormal *= -1;
  }
  return ((int)newNormal);
}
