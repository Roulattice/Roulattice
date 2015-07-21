//
//  tetra_saw2.c
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

#include <stdbool.h>
#include "random_knuth.h"
#include "checks.h"
#include "tetra_saw2.h"

void tetra_saw2 (int (**poly_ptr), const int (move_ptr)[2][4][3], const int (saw_ptr)[4][3], unsigned int numberofbeads, unsigned long *tries) {
    
    static int odd, randn, lastmove;
    
    new_try:
    
    // count new try
    tries[0] += 1;
    
    // random number generation
    do {
        randn = (int) 4.0*rand_knuth(&ARG_randomseed);
    } while (randn > 3);
    
    poly_ptr[1][0] = poly_ptr[0][0] + move_ptr[1][randn][0];
    poly_ptr[1][1] = poly_ptr[0][1] + move_ptr[1][randn][1];
    poly_ptr[1][2] = poly_ptr[0][2] + move_ptr[1][randn][2];
    
    lastmove = randn;
    
    for (int bead=2; bead<(numberofbeads); bead++){
        
        odd=bead%2;
        
        // random number generation
        do {
            randn = (int) 3.0*rand_knuth(&ARG_randomseed);
        } while (randn > 2);
        
        poly_ptr[bead][0] = poly_ptr[bead-1][0] + move_ptr[odd][saw_ptr[lastmove][randn]][0];
        poly_ptr[bead][1] = poly_ptr[bead-1][1] + move_ptr[odd][saw_ptr[lastmove][randn]][1];
        poly_ptr[bead][2] = poly_ptr[bead-1][2] + move_ptr[odd][saw_ptr[lastmove][randn]][2];
        
        lastmove = saw_ptr[lastmove][randn];
        
        if (check_saw2(poly_ptr, bead, lastmove, saw_ptr, move_ptr, odd)==true){
            goto new_try;
        }
        
    }
}
