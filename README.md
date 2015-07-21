# Roulattice
Creation and Evaluation of Linear Polymer Chains on the Tetrahedral Lattice

Roulattice is a command line operated program that creates polymer conformations on the fly and analyzes them. The program can generate chains ensembles of different types: non-self-avoiding and self-avoiding walks, where there exist different hierarchies of self-avoidance. A detailed description of the walks can be found in Dietschreit, J. et al., Marocmol. Theory Simul., 2014, 23, 452-463.
A publication history is displayed when using "-info". The license under which the programm is published will be displayed when using "-license". A complete list of options is shown when using the either "-h", "--help", or when the input was incorrect. 

The program is divided into many files which are compiled to the main program using the present MAKEFILE. Type "make Roulattice" to get an executable named 'Roulattice'. Be sure to have the standard GCC-Compiler and all standard libraries installed. Any non-standard library is included in the folder 'INCLUDE'. The MAKEFILE contains two lines with flags for the compiler depending on the system you wish to compile it on. Before you compile the programm make sure to comment the line with a hash, which does not suit your operating system (the flag "-lm" is needed if running on linux, whereas is has to be removed on MacOS X).
