# Event Driven Restaurant Service Simulator

> [simRes](doc/eventDrivenRestaurantSim_EndTime_60_output.pdf) - an event-driven simulator 
> written in C++, by Mert Türkol.

This repository provides the source-code of an event-driven restaurant service 
simulator. The program considers randomized customer arrival and service 
times from probability distributions. 

The project is written in C++ by Mert Türkol, for coursework in EECS402: 
Computer Programming For Scientists and Engineers, offered at the University of Michigan.

## Table of Contents

<!-- vim-markdown-toc GFM -->

* [Installation](#installation)
    * [Compilation](#compilation)
* [Usage](#usage)
* [Sample Output](#sampleoutput)

<!-- vim-markdown-toc -->

## Installation

### Compilation

The only requirement is the `g++` compiler. `Makefile` utilizes `g++` to compile `simRes`. 
To automatically compile all the source-code, at the command shell simply type:

```
$ make
```

An executable named `simRes.exe` will be produced under the same directory.

## Usage

After the source-code gets compiled, `simRes` can be called from the command line: 

```
$ ./simRes.exe
```

An interactive menu will greet the user and ask for input (via keyboard) 
the following simulation parameters:
  * Duration of the simulation
  * The seed of the random number generator
  * The minimum and maximum ranges of the uniformly distributed random customer arrival times
  * The mean and standard deviation of the normally distributed random service times

## Sample Output

After successful execution of the program, the following statistics of the simulation are computed and reported:
  * Total customers simulated
  * Percentage of time the server was busy
  * Percentage of the customers that the server completed serving
  * Average service time
  * Percentage of the customers waited in the line
  * Average waiting time
  * Number of customers the longest line was composed of during the simulation
  
A sample output of 60 time-units of simulation can be accessed using the link below:   
  * [Sample simulation output and memory error check](doc/eventDrivenRestaurantSim_EndTime_60_output.pdf)  