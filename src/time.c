//
//  time.c
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

#include <sys/time.h> /* for time of day */
#include <stdlib.h> 

#include "time.h"


/* get the time of day from the system clock, and store it (in seconds) */
double time_of_day(void) {
#if defined(_MSC_VER)
    double t;
    
    t = GetTickCount();
    t = t / 1000.0;
    
    return t;
#else
    struct timeval tm;
    //    struct timezone tz;
    
    //    gettimeofday(&tm, &tz);
    gettimeofday(&tm, NULL);
    return((double)(tm.tv_sec) + (double)(tm.tv_usec)/1000000.0);
#endif
}
