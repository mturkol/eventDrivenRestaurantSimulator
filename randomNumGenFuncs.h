/*
 * randomNumGenFuncs.h
 *
 *  Created on: Mar 26, 2014
 *      Author: Mert TURKOL
 * Description: Contains definitions of random # generation and drawing code.
 *              The code can set the seed of a random # generator, can draw a
 *              random # from a Uniform Distro. with specified min and max,
 *              and can draw a random # from a a Normal Distro. with specified
 *              mean and stdDev.
 */

#ifndef RANDOMNUMGENFUNCS_H_
#define RANDOMNUMGENFUNCS_H_

#include <cstdlib>
using namespace std;

//sets the seed for random # draws
void setSeed(int seedVal);
//draws a random # within a uniform distribution with specified min-max range
int getUniform(int min, int max);
//draws a random # within a normal distribution with specified mean and stdDev
int getNormal(float mean, float stdDev);

#endif /* RANDOMNUMGENFUNCS_H_ */
