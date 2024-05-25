## SNC_ArduinoIDE
# Sleptsov Net Machine in Arduino IDE


How to use:
-----------

1) Specify SN in sn.h
   
2) Open sketch in Arduino IDE
   
3) Compile and upload to microcontroller
   
4) Run in serial monitor mode
   
5) Check the final marking (and trace)


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


Remarks:
--------

No pin mapping into input/output places of SN provided within this tiny prototype

Conventional matrices and vectors specify SN, no memory/performance optimization provided within this tiny prototype


References:
-----------

1. Zaitsev D.A. Sleptsov Nets Run Fast, IEEE Transactions on Systems, Man, and Cybernetics: Systems, 2016, Vol. 46, No. 5, 682 - 693. http://dx.doi.org/10.1109/TSMC.2015.2444414
   
2. Dmitry A. Zaitsev, Strong Sleptsov nets are Turing complete, Information Sciences, Vol. 621, 2023, 172-182. https://doi.org/10.1016/j.ins.2022.11.098

3. Bernard Berthomieu, Dmitry A. Zaitsev, Sleptsov Nets are Turing-complete, Theoretical Computer Science, Volume 986, 2024, 114346. https://doi.org/10.1016/j.tcs.2023.114346

4. Dmitry A. Zaitsev, Tatiana R. Shmeleva, Qing Zhang, and Hongfei Zhao, Virtual Machine and Integrated Developer Environment for Sleptsov Net Computing Parallel Processing Letters, Vol. 33, No. 03, 2350006 (2023). https://doi.org/10.1142/S0129626423500068

5. TIme petri Net Analyzer, Release 3.8.0, May 05, 2024 (Runs Sleptsov nets). https://projects.laas.fr/tina/download.php

