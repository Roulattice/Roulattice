//
//  tetra_fsaw2.c
//  Created by Johannes Dietschreit on 21.07.15.
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

#include <stdio.h>
#include <stdbool.h>
#include "random_knuth.h"
#include "checks.h"

#include "tetra_fsaw2.h"


void tetra_fsaw2 (int (**poly_ptr), const int (move_ptr)[2][4][3], const int (saw_ptr)[4][3], unsigned int numberofbeads, int flength, unsigned long *tries) {
    
    
    // these values will be used in every loop and don't change within one run of the programm
    static int nfrags = 0;
    // determine some important values
    if (nfrags==0){
        nfrags = ((numberofbeads-1)/flength);
        printf("nfrags = %i; \n", nfrags);
    }
    
    
    // call all the variables needed in this function
    int odd, randn, lastmove, lastmove_lastf;
    int insert_start_f;
    
    
try_fsaw2:
    
    // count the try for whole chain
    tries[0] += 1;
    
    // set them for a fresh run
    lastmove_lastf = -1;
    insert_start_f = 0;
    
    
    
    for (int fragment=0; fragment<nfrags; ++fragment) {
        
    try_frag_fsaw2:
        
        // count the fragment
        tries[1] += 1;
        
        lastmove = lastmove_lastf;
        
        // distinguish between first fragment and all others
        if (fragment==0) {
            do {
                randn = (int) 4.0*rand_knuth(&ARG_randomseed);
            } while (randn > 3);
            
            poly_ptr[1][0] = poly_ptr[0][0] + move_ptr[1][randn][0];
            poly_ptr[1][1] = poly_ptr[0][1] + move_ptr[1][randn][1];
            poly_ptr[1][2] = poly_ptr[0][2] + move_ptr[1][randn][2];
            
            lastmove = randn;
        }
        else {
            odd=1;
            
            // random number generation
            do {
                randn = (int) 3.0*rand_knuth(&ARG_randomseed);
            } while (randn > 2);
            
            
            poly_ptr[insert_start_f+1][0] = poly_ptr[insert_start_f][0] + move_ptr[odd][saw_ptr[lastmove][randn]][0];
            poly_ptr[insert_start_f+1][1] = poly_ptr[insert_start_f][1] + move_ptr[odd][saw_ptr[lastmove][randn]][1];
            poly_ptr[insert_start_f+1][2] = poly_ptr[insert_start_f][2] + move_ptr[odd][saw_ptr[lastmove][randn]][2];
            
            lastmove = saw_ptr[lastmove][randn];
        }
        
        
        // make the rest of the fragent
        for (int bead=(insert_start_f+2); bead<=(insert_start_f+flength); ++bead){
            
            odd=bead%2;
            
            // random number generation
            do {
                randn = (int) 3.0*rand_knuth(&ARG_randomseed);
            } while (randn > 2);
            
            
            poly_ptr[bead][0] = poly_ptr[bead-1][0] + move_ptr[odd][saw_ptr[lastmove][randn]][0];
            poly_ptr[bead][1] = poly_ptr[bead-1][1] + move_ptr[odd][saw_ptr[lastmove][randn]][1];
            poly_ptr[bead][2] = poly_ptr[bead-1][2] + move_ptr[odd][saw_ptr[lastmove][randn]][2];
            
            lastmove = saw_ptr[lastmove][randn];
            
            if (check_fsaw2(poly_ptr, bead, insert_start_f, lastmove, saw_ptr, move_ptr, odd)==true){
                goto try_frag_fsaw2; // start again with this very fragment
            }
        }
        
        // count completion
        tries[2] += 1;
        
        // now the fragment itself is completed, now is the time to check it against the previous chain
        if (check_whole_fsaw2(poly_ptr, insert_start_f, (insert_start_f+flength), move_ptr)==true){
            goto try_fsaw2; // start all over again
        }
        
        // the current fragment was added succesfully to the chain
        
        lastmove_lastf = lastmove;
        insert_start_f += flength;
        
    }// end of fragments
    
    
    
    // assembling the last fragment/part of the chain
    
    
try_end_fsaw2:
    
    // count the attmepts for the chain end
    tries[3] += 1;
    
    lastmove = lastmove_lastf;
    
    
    for (int bead=(insert_start_f+1); bead<(numberofbeads); ++bead){
        
        odd=bead%2;
        
        // random number generation
        do {
            randn = (int) 3.0*rand_knuth(&ARG_randomseed);
        } while (randn > 2);
        
        
        poly_ptr[bead][0] = poly_ptr[bead-1][0] + move_ptr[odd][saw_ptr[lastmove][randn]][0];
        poly_ptr[bead][1] = poly_ptr[bead-1][1] + move_ptr[odd][saw_ptr[lastmove][randn]][1];
        poly_ptr[bead][2] = poly_ptr[bead-1][2] + move_ptr[odd][saw_ptr[lastmove][randn]][2];
        
        lastmove = saw_ptr[lastmove][randn];
        
        if (check_fsaw2(poly_ptr, bead, insert_start_f, lastmove, saw_ptr, move_ptr, odd)==true){
            goto try_end_fsaw2; // start again with this very fragment
        }
        
        
    }
    
    // created it successfully
    tries[4] += 1;
    
    // now the fragment itself is completed, now is the time to check it against the previous chain
    if (check_whole_fsaw2(poly_ptr, insert_start_f, (numberofbeads-1), move_ptr)==true){
        goto try_fsaw2; // start all over again
    }
    
    
    //done
    
}
