//
//  checks.c
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

#include <stdbool.h> /* defines things like true, false etc  */
#include "checks.h"


//====================================================================================
// first the simple straightforward checks

int check_saw1(int (**check_ptr), int position) {
    
    for (int trybead=(position - 6); trybead>=0; trybead-=2){
        if ((check_ptr[position][0]==check_ptr[trybead][0]) && \
            (check_ptr[position][1]==check_ptr[trybead][1]) && \
            (check_ptr[position][2]==check_ptr[trybead][2]) ){
            return true;
        }
    }
    return false;
}



int check_saw2(int (**check_ptr), int position, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var ) {
    
    for (int trybead=(position - 5); trybead>=0; trybead-=2){
        for (int test=0; test<3; test++){
            if (((check_ptr[position][0]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test]][0])==check_ptr[trybead][0]) && \
                ((check_ptr[position][1]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test]][1])==check_ptr[trybead][1]) && \
                ((check_ptr[position][2]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test]][2])==check_ptr[trybead][2]) ){
                return true;
            }
        }
    }
    return false;
}



int check_saw3(int (**check_ptr), int position, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var ) {
    
    for (int trybead=(position - 4); trybead>=0; trybead-=2){
        for (int test1=0; test1<3; test1++){
            for (int test2=0; test2<3; test2++){
                if (((check_ptr[position][0]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][0]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][0])==check_ptr[trybead][0]) && \
                    ((check_ptr[position][1]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][1]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][1])==check_ptr[trybead][1]) && \
                    ((check_ptr[position][2]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][2]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][2])==check_ptr[trybead][2]) ){
                    return true;
                }
            }
        }
    }
    return false;
}


//====================================================================================
// checks for fragment parst, they are only checked partially

//=====================
// SAW1
//=====================

int check_fsaw1(int (**check_ptr), int position, int start_f){
    
    for (int trybead=(position - 6); trybead>=(start_f); trybead-=2){
        if ((check_ptr[position][0]==check_ptr[trybead][0]) && \
        (check_ptr[position][1]==check_ptr[trybead][1]) && \
        (check_ptr[position][2]==check_ptr[trybead][2]) ){
            return true;
        }
    }
    return false;
}
             

int check_whole_fsaw1(int (**check_ptr), int start_f, int end_f){
 
    int odd;
 
    for (int insert=(start_f+1); insert<=end_f; ++insert) {
     
        odd = insert%2;
     
        for (int tryrow = (start_f-odd); tryrow>=0; tryrow-=2){
            if ((check_ptr[insert][0]==check_ptr[tryrow][0]) && \
                (check_ptr[insert][1]==check_ptr[tryrow][1]) && \
                (check_ptr[insert][2]==check_ptr[tryrow][2])) {
                return true;}
        }
    }
    return false;
}
         

//=====================
// SAW2
//=====================

int check_fsaw2(int (**check_ptr), int position, int start_f, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var ){
    
    for (int trybead=(position - 5); trybead>=(start_f); trybead-=2){
        for (int test1=0; test1<3; test1++){
            if (((check_ptr[position][0]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][0])==check_ptr[trybead][0]) && \
                ((check_ptr[position][1]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][1])==check_ptr[trybead][1]) && \
                ((check_ptr[position][2]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][2])==check_ptr[trybead][2]) ){
                return true;
            }
        }
    }
    return false;
}


int check_whole_fsaw2(int (**check_ptr), int start_f, int end_f, const int (moves_ptr)[2][4][3]){
    
    static int temp_bead[4][3];
    int odd, not_odd;
    // we need this extra bead, beacause otherwise temp_bead overlaps with their allowed precursors,
    // however all following beads have to be compared with it!
    int first_beads = 2;
    
    for (int insert=(start_f+1); insert<=end_f; ++insert) {
        
        odd = insert%2;
        not_odd = 1 - odd%2;
        
        if (first_beads==2 && insert>(start_f+1)) {
            first_beads = 0;
        }
        
        temp_bead[0][0] = check_ptr[insert][0] + moves_ptr[not_odd][0][0];
        temp_bead[0][1] = check_ptr[insert][1] + moves_ptr[not_odd][0][1];
        temp_bead[0][2] = check_ptr[insert][2] + moves_ptr[not_odd][0][2];
        temp_bead[1][0] = check_ptr[insert][0] + moves_ptr[not_odd][1][0];
        temp_bead[1][1] = check_ptr[insert][1] + moves_ptr[not_odd][1][1];
        temp_bead[1][2] = check_ptr[insert][2] + moves_ptr[not_odd][1][2];
        temp_bead[2][0] = check_ptr[insert][0] + moves_ptr[not_odd][2][0];
        temp_bead[2][1] = check_ptr[insert][1] + moves_ptr[not_odd][2][1];
        temp_bead[2][2] = check_ptr[insert][2] + moves_ptr[not_odd][2][2];
        temp_bead[3][0] = check_ptr[insert][0] + moves_ptr[not_odd][3][0];
        temp_bead[3][1] = check_ptr[insert][1] + moves_ptr[not_odd][3][1];
        temp_bead[3][2] = check_ptr[insert][2] + moves_ptr[not_odd][3][2];

        
        for (int tryrow = (start_f - not_odd - first_beads); tryrow>=0; tryrow-=2){
            if ((temp_bead[0][0]==check_ptr[tryrow][0] && temp_bead[0][1]==check_ptr[tryrow][1] && temp_bead[0][2]==check_ptr[tryrow][2]) ||
                (temp_bead[1][0]==check_ptr[tryrow][0] && temp_bead[1][1]==check_ptr[tryrow][1] && temp_bead[1][2]==check_ptr[tryrow][2]) ||
                (temp_bead[2][0]==check_ptr[tryrow][0] && temp_bead[2][1]==check_ptr[tryrow][1] && temp_bead[2][2]==check_ptr[tryrow][2]) ||
                (temp_bead[3][0]==check_ptr[tryrow][0] && temp_bead[3][1]==check_ptr[tryrow][1] && temp_bead[3][2]==check_ptr[tryrow][2])
                ) {
                return true;}
        }
        
    }
    
    return false;
}

             
             
//=====================
// SAW3
//=====================

int check_fsaw3(int (**check_ptr), int position, int start_f, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var ){
    
    for (int trybead=(position - 4); trybead>=(start_f); trybead-=2){
        for (int test1=0; test1<3; test1++){
            for (int test2=0; test2<3; test2++){
                if (((check_ptr[position][0]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][0]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][0])==check_ptr[trybead][0]) && \
                    ((check_ptr[position][1]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][1]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][1])==check_ptr[trybead][1]) && \
                    ((check_ptr[position][2]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][2]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][2])==check_ptr[trybead][2]) ){
                    return true;
                }
            }
        }
    }
    return false;
}

int check_whole_fsaw3(int (**check_ptr), int start_f, int end_f, const int (moves_ptr)[2][4][3]){
    
    static int temp_bead[16][3];
    int odd, not_odd;
    // we need this extra two, for the first two beads, beacause otherwise temp_bead overlaps with their allowed precursors,
    // however all following beads have to be compared with them!
    int first_two_beads = 2;
    
    for (int insert=(start_f+1); insert<=end_f; ++insert) {
        
        odd = insert%2;
        not_odd = 1 - odd%2;
        
        if (first_two_beads==2 && insert>(start_f+2)) {
            first_two_beads = 0;
        }
        
        temp_bead[0][0] = check_ptr[insert][0] + moves_ptr[not_odd][0][0] + moves_ptr[odd][0][0];
        temp_bead[0][1] = check_ptr[insert][1] + moves_ptr[not_odd][0][1] + moves_ptr[odd][0][1];
        temp_bead[0][2] = check_ptr[insert][2] + moves_ptr[not_odd][0][2] + moves_ptr[odd][0][2];
        temp_bead[1][0] = check_ptr[insert][0] + moves_ptr[not_odd][0][0] + moves_ptr[odd][1][0];
        temp_bead[1][1] = check_ptr[insert][1] + moves_ptr[not_odd][0][1] + moves_ptr[odd][1][1];
        temp_bead[1][2] = check_ptr[insert][2] + moves_ptr[not_odd][0][2] + moves_ptr[odd][1][2];
        temp_bead[2][0] = check_ptr[insert][0] + moves_ptr[not_odd][0][0] + moves_ptr[odd][2][0];
        temp_bead[2][1] = check_ptr[insert][1] + moves_ptr[not_odd][0][1] + moves_ptr[odd][2][1];
        temp_bead[2][2] = check_ptr[insert][2] + moves_ptr[not_odd][0][2] + moves_ptr[odd][2][2];
        temp_bead[3][0] = check_ptr[insert][0] + moves_ptr[not_odd][0][0] + moves_ptr[odd][3][0];
        temp_bead[3][1] = check_ptr[insert][1] + moves_ptr[not_odd][0][1] + moves_ptr[odd][3][1];
        temp_bead[3][2] = check_ptr[insert][2] + moves_ptr[not_odd][0][2] + moves_ptr[odd][3][2];
        
        
        temp_bead[4][0] = check_ptr[insert][0] + moves_ptr[not_odd][1][0] + moves_ptr[odd][0][0];
        temp_bead[4][1] = check_ptr[insert][1] + moves_ptr[not_odd][1][1] + moves_ptr[odd][0][1];
        temp_bead[4][2] = check_ptr[insert][2] + moves_ptr[not_odd][1][2] + moves_ptr[odd][0][2];
        temp_bead[5][0] = check_ptr[insert][0] + moves_ptr[not_odd][1][0] + moves_ptr[odd][1][0];
        temp_bead[5][1] = check_ptr[insert][1] + moves_ptr[not_odd][1][1] + moves_ptr[odd][1][1];
        temp_bead[5][2] = check_ptr[insert][2] + moves_ptr[not_odd][1][2] + moves_ptr[odd][1][2];
        temp_bead[6][0] = check_ptr[insert][0] + moves_ptr[not_odd][1][0] + moves_ptr[odd][2][0];
        temp_bead[6][1] = check_ptr[insert][1] + moves_ptr[not_odd][1][1] + moves_ptr[odd][2][1];
        temp_bead[6][2] = check_ptr[insert][2] + moves_ptr[not_odd][1][2] + moves_ptr[odd][2][2];
        temp_bead[7][0] = check_ptr[insert][0] + moves_ptr[not_odd][1][0] + moves_ptr[odd][3][0];
        temp_bead[7][1] = check_ptr[insert][1] + moves_ptr[not_odd][1][1] + moves_ptr[odd][3][1];
        temp_bead[7][2] = check_ptr[insert][2] + moves_ptr[not_odd][1][2] + moves_ptr[odd][3][2];
        
        temp_bead[8][0] = check_ptr[insert][0] + moves_ptr[not_odd][2][0] + moves_ptr[odd][0][0];
        temp_bead[8][1] = check_ptr[insert][1] + moves_ptr[not_odd][2][1] + moves_ptr[odd][0][1];
        temp_bead[8][2] = check_ptr[insert][2] + moves_ptr[not_odd][2][2] + moves_ptr[odd][0][2];
        temp_bead[9][0] = check_ptr[insert][0] + moves_ptr[not_odd][2][0] + moves_ptr[odd][1][0];
        temp_bead[9][1] = check_ptr[insert][1] + moves_ptr[not_odd][2][1] + moves_ptr[odd][1][1];
        temp_bead[9][2] = check_ptr[insert][2] + moves_ptr[not_odd][2][2] + moves_ptr[odd][1][2];
        temp_bead[10][0] = check_ptr[insert][0] + moves_ptr[not_odd][2][0] + moves_ptr[odd][2][0];
        temp_bead[10][1] = check_ptr[insert][1] + moves_ptr[not_odd][2][1] + moves_ptr[odd][2][1];
        temp_bead[10][2] = check_ptr[insert][2] + moves_ptr[not_odd][2][2] + moves_ptr[odd][2][2];
        temp_bead[11][0] = check_ptr[insert][0] + moves_ptr[not_odd][2][0] + moves_ptr[odd][3][0];
        temp_bead[11][1] = check_ptr[insert][1] + moves_ptr[not_odd][2][1] + moves_ptr[odd][3][1];
        temp_bead[11][2] = check_ptr[insert][2] + moves_ptr[not_odd][2][2] + moves_ptr[odd][3][2];
        
        temp_bead[12][0] = check_ptr[insert][0] + moves_ptr[not_odd][3][0] + moves_ptr[odd][0][0];
        temp_bead[12][1] = check_ptr[insert][1] + moves_ptr[not_odd][3][1] + moves_ptr[odd][0][1];
        temp_bead[12][2] = check_ptr[insert][2] + moves_ptr[not_odd][3][2] + moves_ptr[odd][0][2];
        temp_bead[13][0] = check_ptr[insert][0] + moves_ptr[not_odd][3][0] + moves_ptr[odd][1][0];
        temp_bead[13][1] = check_ptr[insert][1] + moves_ptr[not_odd][3][1] + moves_ptr[odd][1][1];
        temp_bead[13][2] = check_ptr[insert][2] + moves_ptr[not_odd][3][2] + moves_ptr[odd][1][2];
        temp_bead[14][0] = check_ptr[insert][0] + moves_ptr[not_odd][3][0] + moves_ptr[odd][2][0];
        temp_bead[14][1] = check_ptr[insert][1] + moves_ptr[not_odd][3][1] + moves_ptr[odd][2][1];
        temp_bead[14][2] = check_ptr[insert][2] + moves_ptr[not_odd][3][2] + moves_ptr[odd][2][2];
        temp_bead[15][0] = check_ptr[insert][0] + moves_ptr[not_odd][3][0] + moves_ptr[odd][3][0];
        temp_bead[15][1] = check_ptr[insert][1] + moves_ptr[not_odd][3][1] + moves_ptr[odd][3][1];
        temp_bead[15][2] = check_ptr[insert][2] + moves_ptr[not_odd][3][2] + moves_ptr[odd][3][2];
        
        for (int tryrow = (start_f-odd-first_two_beads); tryrow>=0; tryrow-=2){
            if ((temp_bead[0][0]==check_ptr[tryrow][0] && temp_bead[0][1]==check_ptr[tryrow][1] && temp_bead[0][2]==check_ptr[tryrow][2]) ||
                (temp_bead[1][0]==check_ptr[tryrow][0] && temp_bead[1][1]==check_ptr[tryrow][1] && temp_bead[1][2]==check_ptr[tryrow][2]) ||
                (temp_bead[2][0]==check_ptr[tryrow][0] && temp_bead[2][1]==check_ptr[tryrow][1] && temp_bead[2][2]==check_ptr[tryrow][2]) ||
                (temp_bead[3][0]==check_ptr[tryrow][0] && temp_bead[3][1]==check_ptr[tryrow][1] && temp_bead[3][2]==check_ptr[tryrow][2]) ||
                (temp_bead[4][0]==check_ptr[tryrow][0] && temp_bead[4][1]==check_ptr[tryrow][1] && temp_bead[4][2]==check_ptr[tryrow][2]) ||
                (temp_bead[5][0]==check_ptr[tryrow][0] && temp_bead[5][1]==check_ptr[tryrow][1] && temp_bead[5][2]==check_ptr[tryrow][2]) ||
                (temp_bead[6][0]==check_ptr[tryrow][0] && temp_bead[6][1]==check_ptr[tryrow][1] && temp_bead[6][2]==check_ptr[tryrow][2]) ||
                (temp_bead[7][0]==check_ptr[tryrow][0] && temp_bead[7][1]==check_ptr[tryrow][1] && temp_bead[7][2]==check_ptr[tryrow][2]) ||
                (temp_bead[8][0]==check_ptr[tryrow][0] && temp_bead[8][1]==check_ptr[tryrow][1] && temp_bead[8][2]==check_ptr[tryrow][2]) ||
                (temp_bead[9][0]==check_ptr[tryrow][0] && temp_bead[9][1]==check_ptr[tryrow][1] && temp_bead[9][2]==check_ptr[tryrow][2]) ||
                (temp_bead[10][0]==check_ptr[tryrow][0] && temp_bead[10][1]==check_ptr[tryrow][1] && temp_bead[10][2]==check_ptr[tryrow][2]) ||
                (temp_bead[11][0]==check_ptr[tryrow][0] && temp_bead[11][1]==check_ptr[tryrow][1] && temp_bead[11][2]==check_ptr[tryrow][2]) ||
                (temp_bead[12][0]==check_ptr[tryrow][0] && temp_bead[12][1]==check_ptr[tryrow][1] && temp_bead[12][2]==check_ptr[tryrow][2]) ||
                (temp_bead[13][0]==check_ptr[tryrow][0] && temp_bead[13][1]==check_ptr[tryrow][1] && temp_bead[13][2]==check_ptr[tryrow][2]) ||
                (temp_bead[14][0]==check_ptr[tryrow][0] && temp_bead[14][1]==check_ptr[tryrow][1] && temp_bead[14][2]==check_ptr[tryrow][2]) ||
                (temp_bead[15][0]==check_ptr[tryrow][0] && temp_bead[15][1]==check_ptr[tryrow][1] && temp_bead[15][2]==check_ptr[tryrow][2])
                ) {
                return true;}
        }
        
    }
    
    return false;
}




//====================================================================================
// checks for things constructed by bricks, here a lot of checks can be saved

//=====================
// SAW1
//=====================

int check_bsaw1(int (**check_ptr), int position, int odd_var , int start_b){
    
    for (int trybead=(start_b - odd_var); trybead>=0; trybead-=2){
        if ((check_ptr[position][0]==check_ptr[trybead][0]) && \
            (check_ptr[position][1]==check_ptr[trybead][1]) && \
            (check_ptr[position][2]==check_ptr[trybead][2]) ){
            return true;
        }
    }
    return false;
}


int check_fb_saw1(int (**check_ptr), int position, int start_f , int bpos_var){
    
    int shift;
    shift = (bpos_var-1);
    shift += (shift%2);
    
    for (int trybead=(position - 6 - shift); trybead>=start_f; trybead-=2){
        if ((check_ptr[position][0]==check_ptr[trybead][0]) && \
            (check_ptr[position][1]==check_ptr[trybead][1]) && \
            (check_ptr[position][2]==check_ptr[trybead][2]) ) {
            return true;
        }
    }
    return false;
}



//=====================
// SAW2
//=====================

int check_bsaw2(int (**check_ptr), int position, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int even_var , int bpos_var){
    
    for (int trybead=(bpos_var - even_var); trybead>=0; trybead-=2){
        for (int test1=0; test1<3; test1++){
            if (((check_ptr[position][0]+moves_ptr[even_var][sawmoves_ptr[lastmove_var][test1]][0])==check_ptr[trybead][0]) && \
                ((check_ptr[position][1]+moves_ptr[even_var][sawmoves_ptr[lastmove_var][test1]][1])==check_ptr[trybead][1]) && \
                ((check_ptr[position][2]+moves_ptr[even_var][sawmoves_ptr[lastmove_var][test1]][2])==check_ptr[trybead][2]) ){
                return true;
            }
        }
    }
    return false;
}


int check_fb_saw2(int (**check_ptr), int position, int start_f, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int even_var , int bpos_var){
    
    int shift;
    shift = (bpos_var-2);
    shift += (shift%2);
    
    for (int trybead=(position - 5 - shift); trybead>=start_f; trybead-=2){
        for (int test1=0; test1<3; test1++){
            if (((check_ptr[position][0]+moves_ptr[even_var][sawmoves_ptr[lastmove_var][test1]][0])==check_ptr[trybead][0]) && \
                ((check_ptr[position][1]+moves_ptr[even_var][sawmoves_ptr[lastmove_var][test1]][1])==check_ptr[trybead][1]) && \
                ((check_ptr[position][2]+moves_ptr[even_var][sawmoves_ptr[lastmove_var][test1]][2])==check_ptr[trybead][2]) ){
                return true;
            }
        }
    }
    return false;
}



//=====================
// SAW3
//=====================

int check_bsaw3(int (**check_ptr), int position, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var , int bpos_var){
    
    for (int trybead=(bpos_var - odd_var); trybead>=0; trybead-=2){
        for (int test1=0; test1<3; test1++){
            for (int test2=0; test2<3; test2++){
                if (((check_ptr[position][0]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][0]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][0])==check_ptr[trybead][0]) && \
                    ((check_ptr[position][1]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][1]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][1])==check_ptr[trybead][1]) && \
                    ((check_ptr[position][2]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][2]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][2])==check_ptr[trybead][2]) ){
                    return true;
                }
            }
        }
    }
    return false;
}


int check_fb_saw3(int (**check_ptr), int position, int start_f, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var , int bpos_var){
    
    int shift;
    shift = (bpos_var-3);
    shift += (shift%2);
    
    for (int trybead=(position - 4 - shift); trybead>=start_f; trybead-=2){
        for (int test1=0; test1<3; test1++){
            for (int test2=0; test2<3; test2++){
                if (((check_ptr[position][0]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][0]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][0])==check_ptr[trybead][0]) && \
                    ((check_ptr[position][1]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][1]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][1])==check_ptr[trybead][1]) && \
                    ((check_ptr[position][2]+moves_ptr[1-odd_var][sawmoves_ptr[lastmove_var][test1]][2]+moves_ptr[odd_var][sawmoves_ptr[sawmoves_ptr[lastmove_var][test1]][test2]][2])==check_ptr[trybead][2]) ){
                    return true;
                }
            }
        }
    }
    return false;
}


