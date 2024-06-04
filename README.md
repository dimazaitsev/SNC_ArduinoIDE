## SNC_ArduinoIDE
# Sleptsov Net Machine in Arduino IDE


Motivation:
-----------

Using formal methods of embedded system design allows us to implement formal verification of a control system alone and integrated with the plant model that yields reliable embedded systems. Application graphical languages of embedded system design was a success for years with ladder diagrams. 

An Sleptsov net (SN) is a Turing-complete graphical language able to specify any given concurrent algorith. There is a widerange of formal techniques to verify an SN, both specific and inherited from Petri nets, which an SN generalizes. 


External links:
---------------

1) Tina to draw, edit, debug, and verify SN programs https://projects.laas.fr/tina/maxsteps.php
   
2) NDRtoSN converts Tina NDR format to SN formats https://github.com/dimazaitsev/NDRtoSN

3) For hierarchical design, use compiler-linker of SN https://github.com/HfZhao1998/Compiler-and-Linker-of-Sleptsov-net-Program


How to use:
-----------

1) Specify SN in sn.h

2) Specify pin map in pin.h
   
3) Open sketch sna.ino in Arduino IDE
   
4) Compile and upload to microcontroller
   
5) Test microcontroller work
   
6) Debug controlling debug info printed on serial interface

Without a pin map file, it is possible just to run an SN on a microcontroller reading results (and trace) on serial interface. 


Vending Machine (VM) example:
-----------------------------

We use 1 type of coins. VM sells 2 types of chocolate bars - milk and dark. Besides slots for coins, VM has: 2 buttons - chocolate and return; window to collect chocolate bars; window to collect returned coins. Milk cocolate costs 2 coins. Dark chocolate costs 3 coins. VM does not keep more than 3 coins, just returning next one. VM returns coins one by one, one coin at one pressing the return button. VM can be supplied with additional display to indicate its state - the number of coins. 


Finite Automaton (FA) machine:
------------------------------

For folk who are familiar with FA. There is an FA VM example and FA machine for a microcontroller. Compared to FA, SN can control unlimited number of concurrent processes.


Content:
--------

Arduino/sna - Arduino sketch for generic SN machine with sn-vm example .h files

Arduino/faa - Arduino sketch for generic FA machine with sn-vm example inside it

fa-vm - FA VM example description

sn-vm - SN VM example description

sn-ex - exra examples of SNs


SN specification - h file:
--------------------------

SN is specified as 2 numbers, 3 matrices, 1 vector:

#define m - number of places

#define n - number of transitions

static int b[m][n] - matrix of imcoming arcs of transitions

static int d[m][n] - matrix of outgoing arcs of transitions

static int r[n][n] - matrix of priority arcs

static int mu[m] - vector of initial marking


Additional parameters:
----------------------

static int y[n] - vector of fireability multiplicity

static int dbg - debug level, 0..2


Remarks:
--------

Conventional matrices and vectors specify SN, no memory/performance optimization provided within this tiny prototype. Controller specific implementation and using optimized data structures and algorithms can comsiderably increase performance and reduce data size. 



References:
-----------

1. Zaitsev D.A. Sleptsov Nets Run Fast, IEEE Transactions on Systems, Man, and Cybernetics: Systems, 2016, Vol. 46, No. 5, 682 - 693. http://dx.doi.org/10.1109/TSMC.2015.2444414
   
2. Dmitry A. Zaitsev, Strong Sleptsov nets are Turing complete, Information Sciences, Vol. 621, 2023, 172-182. https://doi.org/10.1016/j.ins.2022.11.098

3. Bernard Berthomieu, Dmitry A. Zaitsev, Sleptsov Nets are Turing-complete, Theoretical Computer Science, Volume 986, 2024, 114346. https://doi.org/10.1016/j.tcs.2023.114346

4. Dmitry A. Zaitsev, Tatiana R. Shmeleva, Qing Zhang, and Hongfei Zhao, Virtual Machine and Integrated Developer Environment for Sleptsov Net Computing Parallel Processing Letters, Vol. 33, No. 03, 2350006 (2023). https://doi.org/10.1142/S0129626423500068

5. TIme petri Net Analyzer, Release 3.8.0, May 05, 2024 (Runs Sleptsov nets). https://projects.laas.fr/tina/download.php

6. Dmitry A. Zaitsev, Introduction to Embedded Systems, teaching module, 2024. https://dimazaitsev.github.io/ar/ies.zip


