//
//  intra_potential.h
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

#ifndef ____intra_potential__
#define ____intra_potential__


void intrapot_torsion_well(double (*boltz_ptr), double (*energy_ptr), int (*interaction_hist_ptr), double (*highest_factor_ptr), double (*well_ptr), double (*tor_ptr), double (nT_ptr), const unsigned int ntorangles, int (**poly_ptr), const unsigned int numberofbeads);

void intrapot_torsion_well_scan(double (*boltz_ptr), double (*energy_ptr), int (*interaction_hist_ptr), double (*highest_factor_ptr), double (*well_ptr), double (*tor_ptr), double (nT_ptr), const unsigned int ntorangles, int (**poly_ptr), const unsigned int numberofbeads);


void intrapot_torsion_well_test(double (*boltz_ptr), double (*energy_ptr), int (*interaction_hist_ptr), double(*extra_histogram), double (*highest_factor_ptr), double (*well_ptr), double (*tor_ptr), double (nT_ptr), const unsigned int ntorangles, int (**poly_ptr), const unsigned int numberofbeads);

void intra_binenergy(double energy, double min, double width, int (*histogram));

double intra_loss_of_conf(double (*sum_boltz_ptr), double highest_factor, unsigned long numberofframes);



#endif /* defined(____intra_potential__) */
