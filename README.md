# Roulattice
Creation and Evaluation of Linear Polymer Chains on the Tetrahedral Lattice

Roulattice is a command line operated program that creates polymer conformations on the fly and analyzes them. The program can generate chains ensembles of different types: non-self-avoiding and self-avoiding walks, where there exist different hierarchies of self-avoidance. A detailed description of the walks can be found in Dietschreit, J. et al., Marocmol. Theory Simul., 2014, 23, 452-463.


# Getting Started

Get the source code of Roulattice from the GitHub repository:

$ git clone --recursive https://github.com/propairs/propairs
  
Or by downloading the ZIP-file of the whole repository. Unpack (if neccessary) the files at any chosen location of the computer. Change into the directory and compille the programm:

  $ cd Roulattice

The program is divided into many files which are compiled to the main program using the present MAKEFILE. Type "make Roulattice" to get an executable named 'Roulattice'. 

  $ make Roulattice

Be sure to have the standard GCC-Compiler and all standard libraries installed. Any non-standard library is included in the folder 'include'. The MAKEFILE contains two lines with flags for the compiler depending on the system you wish to compile it on. Before you compile the programm make sure to comment the line with a hash, which does not suit your operating system (the flag "-lm" is needed if running on linux, whereas is has to be removed on MacOS X).  

# Using Roulattice

A publication history is displayed when using "-info". The license under which the programm is published will be displayed when using "-license". A complete list of options is shown when using the either "-h", "--help", or when the input was incorrect. Generally Roulattice is used as follows:

$ ./Roulattice -tetra_saw1 50 -num 1000 

Where '-tetra_saw1' specifies the walk used by the programm, '50' the number of atoms of the polymer chain, '-num' the ensemble size of generted confomations, and '1000' is the ensemble size. Further flags might be neccessary dependeing on the chosen type of run. There are also options regarding the observables which can be computed with the programm as well as options regarding the nature of the polymer. See the full option list as explained above.

# Ubuntu

On Ubuntu 14.04 you can install Git like this:

$ sudo apt-get install git



