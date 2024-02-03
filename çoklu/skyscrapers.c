#include "skyscrapers.h"
#include <stdio.h>

void print_board(int board[][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int is_valid_placement(int board[][SIZE], int row, int col, int height) {
  if (board[row][col] != 0) {
    return 0;
  }

  for (int i = 0; i < SIZE; i++) {
    if (board[row][i] == height || board[i][col] == height) {
      return 0;
    }
  }

  return 1;
}

int solve_skyscrapers(int board[][SIZE], int *input) {
  int row = 0, col = 0;

  while (row < SIZE) {
    int height =
        input[row *
              2]; // Kullanıcıdan gelen input ile belirlenen yükseklik değeri

    if (is_valid_placement(board, row, col, height)) {
      board[row][col] = height;
      col = (col + 1) % SIZE;

      if (col == 0) {
        row++;
      }
    } else {
      printf("Bu tahta bir çözüme sahip değil.\n");
      return 0;
    }
  }

  return 1;
}
