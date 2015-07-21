//
//  pair_correlation_function.c
//  Created by Johannes Dietschreit on 12.06.15.
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
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "observables.h"
#include "pair_correlation_function.h"

int pair_correlation_fct(double (*corr_hist), double (**poly_ptr), const unsigned int numberofbeads){
    
    // this is the atom around which the pair correlation function is computed
    static int center_atom =0 ;
    if (center_atom==0){
        center_atom = numberofbeads/2;
        //printf("center_atom= %i\n", center_atom);
    }
    
    // distance between atoms squared
    double dist2;
    // bin for the histogram
    int bin = 0;
    double shell_width = 1.0; // in Angstrom
    int *local_hist;
    local_hist = (int *) calloc(2*numberofbeads, sizeof(int));
    if (NULL == local_hist) {
        fprintf(stderr, "No RAM for local hist in pair_correlation_fct! \n");
        return false;
    }
    
    
    // loop over all atoms, binning them in the different shells
    for (int dim2=0; dim2<center_atom; dim2++) {
        
        dist2 = double_distance2(poly_ptr[dim2], poly_ptr[center_atom]);
        
        bin = floor(sqrt(dist2)/shell_width);
        
        local_hist[bin]+=1;
        
    }
    
    for (int dim2=center_atom+1; dim2<numberofbeads; dim2++) {
     
        dist2 = double_distance2(poly_ptr[dim2], poly_ptr[center_atom]);
        
        bin = floor(sqrt(dist2)/shell_width);
        
        local_hist[bin]+=1;
        
    }
        

    for (int dim1=0; dim1<(2*numberofbeads); dim1++) {
        corr_hist[dim1] = (double)local_hist[dim1] / (4.0/3.0 * pi * shell_width*shell_width*shell_width * ((double)(3*dim1*dim1 + 3*dim1 + 1)));
    }
    
    
    free(local_hist);
    
    return true;
    
    
}