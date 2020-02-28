# Event Driven Restaurant Service Simulator

> [simRes](doc/eventDrivenRestaurantSim_EndTime_60_output.pdf) - an event-driven simulator 
> written in C++, by Mert Türkol.

## Table of Contents

<!-- vim-markdown-toc GFM -->

* [Description](#description)
* [Installation](#installation)
    * [Compilation](#compilation)
* [Usage](#usage)
* [Output](#output)

<!-- vim-markdown-toc -->

## Description

This repository provides the source-code of an event-driven restaurant service 
simulator. 

The program considers randomized customer arrival and service 
times from probability distributions. Sorted Doubly Linked List and Queue 
templated classes were personally developed for the event list and the customer 
line respectively. Statistical accumulations such as the longest line, average 
service and waiting times, as well as the percentages of server busy time, 
customers served and customers waited in line are computed and reported. 

The project is written in C++ by Mert Türkol, for coursework in EECS402: 
Computer Programming For Scientists and Engineers, offered at the University of 
Michigan.

## Installation

### Compilation

Only requirement is the `g++` compiler. `Makefile` utilizes `g++` to compile 
`simRes`. To compile all the source-code, at the command shell simply type:

```
$ make
```

An executable named `simRes.exe` will be produced under the same directory.

## Usage

After the source-code gets compiled, `simRes` can be called from the command line: 

```
$ ./simRes.exe
```

An interactive menu will greet the user and ask for input (via keyboard) the 
following simulation parameters:
  * Duration of simulation
  * The seed of the random number generator
  * The minimum and maximum ranges of the uniformly distributed random customer arrival times
  * The mean and standard deviation of the normally distributed random service times

## Output

After a simulation completes, the following statistics are computed and reported 
along with the simulation history:
  * Total customers simulated
  * Percentage of time the server was busy
  * Percentage of customers the server completed serving
  * Average service time
  * Percentage of customers waited in the line
  * Average waiting time
  * Number of customers the longest line was composed of during the simulation
  
Sample output of a simulation that was 60 time-units long can be accessed using the link below:   
  * [Sample simulation output and report for memory error check](doc/eventDrivenRestaurantSim_EndTime_60_output.pdf)  