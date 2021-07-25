//
//  tetra_rw.h
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

#ifndef ____tetra_rw__
#define ____tetra_rw__

extern long ARG_randomseed;

void tetra_rw (int (**poly_ptr), const int (move_ptr)[2][4][3], unsigned int numberofbeads);

#endif /* defined(____tetra_rw__) */
