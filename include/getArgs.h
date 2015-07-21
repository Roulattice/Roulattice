//
//  getArgs.h
//  Created by Johannes Dietschreit on 29.05.15.
//
//  Roulattice, Creation and Evaluation of Linear Polymer Chains on the Tetrahedral Lattice
//  Copyright (C) 2015  Johannes Dietschreit
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//

#ifndef ____getArgs__
#define ____getArgs__

// pre-declarations
void usage_error(void);
void getArgs(FILE *output_ptr, int argc, char **argv);
void print_set_options(FILE *output_ptr, int typeofrun, int flength, int fflength, int blength, int numberofbeads, unsigned long long numberofframes, long seed, double bond, int torsion, int intramolecular, double intra_eps1[2], double intra_eps2[2]);


// initializing the global variables, which will be set in this routine
int ARG_typeofrun;      // sets method
int ARG_strictness;     // degree of self-avoidance
int ARG_blength;        // sets bricklength
int ARG_flength;        // sets fragment length

long ARG_randomseed;

unsigned int ARG_numberofbeads;     // number of atoms in chain
unsigned long ARG_numberofframes;    // number  of chains that will be generated successfully

//optional variables
double ARG_bondlength;  // bond length
int ARG_torsion;        // switch for torsional analysis
int ARG_pair_correlation;
int ARG_intra_potential; // switch for intra molecular potential
double ARG_intra_parameter1[2];
double ARG_intra_parameter2[2];


char* dcdFileName; // name of the dcd file which is to be loaded instead of a generation run


#endif /* defined(____getArgs__) */
