#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 4

void printSkyScrapersArray(int *skyscrapers) {
  for (int i = 0; i < ARRAYSIZE; i++) {
    for (int j = 0; j < ARRAYSIZE; j++) {
      printf("%d ", skyscrapers[i * ARRAYSIZE + j]);
    }
    printf("\n");
  }
}

int putCondition(int row, int col, int content, int *skyscrapers) {
  // printf("PUT CONDITION\n");
  for (int loopValue = 0; loopValue < ARRAYSIZE; loopValue++) {
    if (skyscrapers[row * ARRAYSIZE + loopValue] == content || skyscrapers[loopValue * ARRAYSIZE + col] == content) {
      return 0;
    }
  }
  return 1;
}

int putSkyScrapersArray(int *skyscrapers) {
  int row = 0, column = 0;
  while (row < ARRAYSIZE) {
    int content = 1;
    while (content <= ARRAYSIZE) {
      if (putCondition(row, column, content, skyscrapers)) {
        skyscrapers[row * ARRAYSIZE + column] = content;
        column = (column + 1) % ARRAYSIZE;
        if (column == 0) {
          row++;
        }
        break;
      } else {
        content++;
      }
    }
  }

  return 1;
}

int main(void) {
  printf("SkyScrapers Oyununa Hoşgeldiniz :)\n");
  int *skyscrapers = (int *)malloc(ARRAYSIZE * ARRAYSIZE * sizeof(int));
  if (skyscrapers == NULL) {
    printf("Bellek tahsis edilirken bir hata oluştu\n");
    return 0;
  }

  if (putSkyScrapersArray(skyscrapers)) {
    printf("Dizi oluşturuldu ve Oyun Başladı\n");
    printSkyScrapersArray(skyscrapers);
    free(skyscrapers);
    return 1;
  } else {
    printf("Oyun Başlatılırken bir hata oluştu\n");
    free(skyscrapers);
    return 1;
  }

  return 0;
}
