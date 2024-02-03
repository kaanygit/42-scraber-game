#ifndef SKYSCRAPERS_H
#define SKYSCRAPERS_H

#define SIZE 4

void print_board(int board[][SIZE]);
int is_valid_placement(int board[][SIZE], int row, int col, int height);
int solve_skyscrapers(int board[][SIZE], int input[]);
#endif
