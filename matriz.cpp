#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_RANDOM 3

int main() {
    srand (time(NULL));
    
    int matrix[3][3] = { 
        {rand() % MAX_RANDOM + 1, rand() % MAX_RANDOM + 1, rand() % MAX_RANDOM + 1}, 
        {rand() % MAX_RANDOM + 1, rand() % MAX_RANDOM + 1, rand() % MAX_RANDOM + 1}, 
        {rand() % MAX_RANDOM + 1, rand() % MAX_RANDOM + 1, rand() % MAX_RANDOM + 1}
    };
    
    // int matrix[3][3] = { 
    //   {0,1,1}, 
    //   {1,1,0}, 
    //   {1,0,1}
    // };
    
    int ii, jj, c, d, b, cc, dd, bb = 0;
    ii = jj = c = d = b = cc = dd = bb;
    
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
	c = matrix[i][j];

	if (matrix[i][j-1] == c && j > 0) b++;
	if (matrix[i-1][j] == c && i > 0) bb++;
	if (b == 2) { d++; b = 0; }
	if (bb == 2) { dd++; bb = 0; }

	if (ii != i) {
	  b = 0;
	  c = 0;
	}
	if (jj != j) {
	  bb = 0;
	}

	jj = j;
	ii = i;

	printf("%i ", matrix[i][j]);
      }
	
      printf("\n");
    }
    
    // printf("\nc = %i | cc = %i\nd = %i || dd = %i\nb = %i | bb = %i\n", 
    // c, cc, d, dd, b, bb);

    printf("\nVocê teve números iguais em %i linhas e %i colunas.\n", d, dd);

    return 0;
}
