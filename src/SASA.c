//
//  SASA.c
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

#include <math.h>
#include "observables.h"
#include "SASA.h"


double get_asa(double (**chain), unsigned int numberofbeads, double r){
    
    // to compute the availiable surface area we make use of the
    // Linear Combination of Spherical Overlap
    // Weiser, Shenkin, Still, J. Comput. Chem., 20, 1999
    
    // surface sphere       $ S_i = 4 \pi r^2 $
    // overlap of i with j  $ A_{ij} = 2 \pi r (r - \frac{d_{ij}}{2} - \frac{r_i^2 - r_j^2}{2d_{ij}})   $
    // here there is only one r_i, thus A_ij = A_ji
    // we don't count every pair twice, thereforre we subtract 2A_ij and no A_ji!
    
    double asa; // availiable surface area
    double dist;
    double diameter = 2.0 * r;
    
    asa = 0.56482*(double)numberofbeads * 4.0 * r * r; // surface of all spheres
    
    for (int dim1=0; dim1<(numberofbeads-1); dim1++){
        for (int dim2=dim1+1; dim2<numberofbeads; dim2++) {
            
            dist = sqrt(double_distance2(chain[dim1], chain[dim2]));
            
            if (dist < diameter){
                
                asa -= 0.19608*(4.0 * pi * r * ( r -  (dist/2.0) ));
                
            }
            
        }
    }
    
    
    
    return asa;
    
}



// let's consider that the overlap of a contact does not partially include any other overlap
// the double counting of the overlap is done by using again P2=0.19608

double delta_asa(double (**chain), unsigned int numberofbeads, double b){
    
    
    double d_asa = 0.0;
    double dist;
    double r = (sqrt(19.0/3.0)*b/2.0);
    
    for (int dim1=0; dim1<(numberofbeads-3); dim1++){
        for (int dim2=(dim1+3); dim2<numberofbeads; dim2++) {
            
            dist = sqrt(double_distance2(chain[dim1], chain[dim2]));
            
            if (( r -  (dist/2.0) )>0.0){
                
                d_asa -= 0.19608*(4.0 * pi * r * ( r -  (dist/2.0) ));
                
            }
        }
    }
    
    
    return d_asa;
    
}

