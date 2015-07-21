//
//  checks.h
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

#ifndef ____checks__
#define ____checks__

int check_saw1(int (**check_ptr), int position);
int check_saw2(int (**check_ptr), int position, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var );
int check_saw3(int (**check_ptr), int position, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var );


int check_fsaw1(int (**check_ptr), int position, int start_f);
int check_fsaw2(int (**check_ptr), int position, int start_f, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var );
int check_fsaw3(int (**check_ptr), int position, int start_f, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var );

int check_whole_fsaw1(int (**check_ptr), int start_f, int end_f);
int check_whole_fsaw2(int (**check_ptr), int start_f, int end_f, const int (moves_ptr)[2][4][3]);
int check_whole_fsaw3(int (**check_ptr), int start_f, int end_f, const int (moves_ptr)[2][4][3]);

int check_bsaw1(int (**check_ptr), int position, int odd_var , int bpos_var);
int check_bsaw2(int (**check_ptr), int position, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int even_var , int bpos_var);
int check_bsaw3(int (**check_ptr), int position, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var , int bpos_var);

int check_fb_saw1(int (**check_ptr), int position, int start_f , int bpos_var);
int check_fb_saw2(int (**check_ptr), int position, int start_f, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int even_var , int bpos_var);
int check_fb_saw3(int (**check_ptr), int position, int start_f, int lastmove_var, const int (sawmoves_ptr)[4][3] , const int (moves_ptr)[2][4][3], int odd_var , int bpos_var);


#endif /* defined(____checks__) */
