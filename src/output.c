//
//  output.c
//  Created by Johannes Dietschreit on 29.05.15.
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
#include <stdarg.h>
#include "output.h"


void log_out(FILE *logfile, const char * fmt, ... ){
    
    va_list args1;                   // get all arguments from the variable list
    va_list args2;
    
    va_start(args1, fmt);            //initialiazes the variable argument list
    va_start(args2, fmt);
    
    vprintf(fmt, args1);             //prints the va-list to screen
    vfprintf(logfile, fmt, args2);   //prints the va-list to file
    
    
    va_end(args1);
    va_end(args2);                   //ends va-list
    
    fflush(logfile);
    fflush(stdout);
    
}

