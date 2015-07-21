//
//  entropy.c
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

#include <stdlib.h>
#include <math.h>

#include "entropy.h"


double intra_entropy(double (*boltz_ptr), double (*boltzener_ptr), double logatt){
    
    double DS;
    double sum_boltz = 0.0;
    double sum_enerboltz = 0.0;
    
    for (int dim1=0; dim1<10; ++dim1){
        
        sum_boltz += boltz_ptr[dim1];
        sum_enerboltz += boltzener_ptr[dim1];
        
    }
    
    DS = log(sum_boltz) - logatt + sum_enerboltz/sum_boltz;
    
    return DS;
    
}


double intra_entropy_error_ten(double entropy, double (*boltz_ptr), double (*boltzener_ptr), double (*logatt)){
    
    double DS_err = 0.0;
    double *DS = (double *) calloc(10, sizeof(double));
    
    for (int dim1=0; dim1<10; ++dim1){
        
        DS[dim1] = log(boltz_ptr[dim1]) - logatt[dim1] + boltzener_ptr[dim1]/boltz_ptr[dim1];
        
        DS_err += (entropy-DS[dim1])*(entropy-DS[dim1]);
        
        
    }
    
    DS_err /= 10;
    
    DS_err = sqrt(DS_err);
    
    
    free(DS);
    
    
    return DS_err;
    
}
