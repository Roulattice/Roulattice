//
//  statistics.h
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

#ifndef ____statistics__
#define ____statistics__

double average(double (*obs_ptr), unsigned long numberofframes);

double weighted_average(double (*obs_ptr), double (*weights_ptr));

double error_ten(double mean, double (*obs_ptr), unsigned long numberofframes);

double error_sq_ten(double mean, double (*obs_ptr), unsigned long numberofframes);

double weighted_error_ten(double mean, double (*means_ptr), double (*weights_ptr));

double weighted_error_sq_ten(double mean, double (*means_ptr), double (*weights_ptr));

int histogram(int numbins, double (*obs_ptr), unsigned long numberofframes, FILE *file_ptr);

int histogram_boltz(int numbins, double (**obs_ptr), unsigned long numberofframes, int nfactors, FILE *file_ptr);

void convergence(OBSERVABLE *obs_ptr, double ntor, unsigned long convpoint, FILE *file_ptr);

void weighted_convergence(OBSERVABLE *obs_ptr, int num_eps, double (**weights_ptr), double ntor, unsigned long convpoint, FILE *file_ptr);

void weights_growth(double (**obs_ptr), int num_eps, unsigned long convpoint, FILE *file_ptr);

#endif /* defined(____statistics__) */
