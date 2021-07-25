//
//  observables.h
//  Created by Johannes Dietschreit on 11.06.15.
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

#ifndef ____observables__
#define ____observables__

// global variables
extern double pi;
extern int ARG_blength;        // sets bricklength

typedef struct {
    double ee2;
    double maxee;
    double rgyr;
    double pt;
    double dsasa;
    double *pair_corr;
    double S;


    double *err_ee2;
    double *err_rgyr;
    double *err_pt;
    double *err_dsasa;
    double err_S;


}OBSERVABLE;


// predeclaration of functions
void recast (double (**double_poly_ptr), int (**int_poly_ptr), unsigned int numberofbeads , double *recast_ptr);

double double_distance2 (double (*atom1_ptr), double (*atom2_ptr));

int int_distance2 (int (*atom1_ptr), int (*atom2_ptr));

double radius_of_gyration (double (**poly_ptr), unsigned int numberofbeads);

double torsion_angle(double (**atoms_ptr), int start_position);

double get_nT(double (**atoms_ptr), unsigned int numtorsions);

double recalc_attempts(unsigned long *attempts_successes, unsigned int *n_frag_brick, int n_bricks, int typeofrun);






#endif /* defined(____observables__) */
