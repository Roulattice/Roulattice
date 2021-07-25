# Roulattice
Creation and Evaluation of Linear Polymer Chains on the Tetrahedral Lattice

Roulattice is a command line operated program that creates polymer conformations on the fly and analyzes them. The program can generate chains ensembles of different types: non-self-avoiding and self-avoiding walks, where there exist different hierarchies of self-avoidance. A detailed description of the walks can be found in Dietschreit, J. et al., Marocmol. Theory Simul., 2014, 23, 452-463.

The library's code has been modernized by Richard Barnes (@r-barnes).


# Getting Started

Get the source code of Roulattice from the GitHub repository:

```bash
git clone https://github.com/r-barnes/Roulattice
```

Or by downloading the ZIP-file of the whole repository. Unpack (if neccessary) the files at any chosen location of the computer. Change into the directory and compille the programm:

```bash
cd Roulattice
```

The program is divided into many files which are compiled to the main program using CMake. To build the program type:

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
make
```

# Using Roulattice

A publication history is displayed when using "-info". The license under which the programm is published will be displayed when using "-license". A complete list of options is shown when using the either "-h", "--help", or when the input was incorrect. Generally Roulattice is used as follows:

```bash
./roulattice -tetra_saw1 50 -num 1000 -torsion
```

Where '-tetra_saw1' specifies the walk used by the programm, '50' the number of atoms of the polymer chain, '-num' the ensemble size of generted confomations, and '1000' is the ensemble size. Further flags might be neccessary dependeing on the chosen type of run. There are also options regarding the observables which can be computed with the programm as well as options regarding the nature of the polymer. See the full option list as explained above.
