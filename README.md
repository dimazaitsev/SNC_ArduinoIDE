## SNC_ArduinoIDE
# Sleptsov Net Machine in Arduino IDE

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


Compatibility:
--------------

SN is specified as 2 numbers, 3 matrices, 1 vector:

#define m - number of places

#define n - number of transitions

int b[m][n] - matrix of imcoming arcs of transitions

int d[m][n] - matrix of outgoing arcs of transitions

int r[n][n] - matrix of priority arcs

int mu[m] - vector of initial marking


Additional parameters:
----------------------

int y[n] - vector of fireability multiplicity

int dbg - debug level, 0..2


Content:
--------

sna - Arduino sketch sna.ino and example nets sn-add.h and sn-mul.h

ndr - example nets in Tina format to open and run in Tina


Remarks:
--------

Conventional matrices and vectors specify SN, no memory/performance optimization provided within this tiny prototype


References:
-----------

1. Zaitsev D.A. Sleptsov Nets Run Fast, IEEE Transactions on Systems, Man, and Cybernetics: Systems, 2016, Vol. 46, No. 5, 682 - 693. http://dx.doi.org/10.1109/TSMC.2015.2444414
   
2. Dmitry A. Zaitsev, Strong Sleptsov nets are Turing complete, Information Sciences, Vol. 621, 2023, 172-182. https://doi.org/10.1016/j.ins.2022.11.098

3. Bernard Berthomieu, Dmitry A. Zaitsev, Sleptsov Nets are Turing-complete, Theoretical Computer Science, Volume 986, 2024, 114346. https://doi.org/10.1016/j.tcs.2023.114346

4. Dmitry A. Zaitsev, Tatiana R. Shmeleva, Qing Zhang, and Hongfei Zhao, Virtual Machine and Integrated Developer Environment for Sleptsov Net Computing Parallel Processing Letters, Vol. 33, No. 03, 2350006 (2023). https://doi.org/10.1142/S0129626423500068

5. TIme petri Net Analyzer, Release 3.8.0, May 05, 2024 (Runs Sleptsov nets). https://projects.laas.fr/tina/download.php

