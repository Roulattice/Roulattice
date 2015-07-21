//
//  tetra_bsaw1.c
//  Created by Johannes Dietschreit on 17.07.15.
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

#include "tetra_bsaw1.h"

void tetra_bsaw1 (int (**poly_ptr), const int (move_ptr)[2][4][3], const int (saw_ptr)[4][3], unsigned int numberofbeads, int blength_var, int numbricks_var, int (***bricks_ptr), unsigned long *tries){
    
    int odd, randn, lastmove, lastmove_lastf, insert_start, position;
    
    // thies will have in every run the very same value
    static int nbricks = 0;
    if (nbricks==0){
        nbricks = (numberofbeads-1)/blength_var;
    }
    
    
try_bsaw1:
    
    // count the try for whole chain
    tries[0] += 1;
    
    lastmove = -1;
    
    for (int brick=0; brick<nbricks; brick++){
        
        insert_start = brick*blength_var;
        
    new_brick_bsaw1:
        
        // random number generation
        do {
            randn = (int) ((double)numbricks_var*rand_knuth(&ARG_randomseed));
        } while (randn > (numbricks_var-1));
        
        
        if (bricks_ptr[randn][0][3]==lastmove){
            goto new_brick_bsaw1;
        }
        
        position = insert_start;
        
        for (int atom=0; atom<blength_var; atom++) {
            
            position++;
            odd = position%2;
            
            poly_ptr[position][0] = poly_ptr[insert_start][0] + bricks_ptr[randn][atom][0];
            poly_ptr[position][1] = poly_ptr[insert_start][1] + bricks_ptr[randn][atom][1];
            poly_ptr[position][2] = poly_ptr[insert_start][2] + bricks_ptr[randn][atom][2];
            
            if (check_bsaw1(poly_ptr, position, odd, insert_start)==true){
                goto try_bsaw1;
            }
            
        }
        
        lastmove = bricks_ptr[randn][blength_var-1][3];
    }
    
    
    insert_start += blength_var;
    lastmove_lastf = lastmove;
    
try_end_bsaw1:
    
    tries[1] += 1;
    
    lastmove = lastmove_lastf;
    
    for (int bead=(insert_start+1); bead<(numberofbeads); bead++){
        
        odd=bead%2;
        
        // random number generation
        do {
            randn = (int) 3.0*rand_knuth(&ARG_randomseed);
        } while (randn > 2);
        
        
        poly_ptr[bead][0] = poly_ptr[bead-1][0] + move_ptr[odd][saw_ptr[lastmove][randn]][0];
        poly_ptr[bead][1] = poly_ptr[bead-1][1] + move_ptr[odd][saw_ptr[lastmove][randn]][1];
        poly_ptr[bead][2] = poly_ptr[bead-1][2] + move_ptr[odd][saw_ptr[lastmove][randn]][2];
        
        lastmove = saw_ptr[lastmove][randn];
        
        if (check_fsaw1(poly_ptr, bead, insert_start)==true){
            goto try_end_bsaw1; // start again with this very fragment
        }
    }
    
    // succeeded with the last part
    tries[2] += 1;
    
    // now the end is completed, now is the time to check it against the previous chain
    if (check_whole_fsaw1(poly_ptr, insert_start, (numberofbeads-1))==true){
        goto try_bsaw1; // start all over again
    }
    
}

