#include "skyscrapers.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != SIZE * 2 + 1) {
    printf("Hatalı giriş. Lütfen geçerli bir set sağlayın.\n");
    return 1;
  }

  int board[SIZE][SIZE] = {0};
  int input[SIZE * 2];

  // Argümanları integer dizisine dönüştür
  for (int i = 1; i < argc; i++) {
    input[i - 1] = atoi(argv[i]);
  }

  if (solve_skyscrapers(board, input)) {
    printf("Oyun çözüldü:\n");
    print_board(board);
  }

  return 0;
}


