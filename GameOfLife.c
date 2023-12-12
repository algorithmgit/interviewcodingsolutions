#include <stdio.h>

/*
Please read through all instructions thoroughly and let me know if you have any questions before you get started.

This editor *does* have vim/emacs binding support (at the bottom left, in Settings) if desired.

This task is called The Game of Life. You can use the Internet as long as you don’t look up the answer, and you have 30 minutes to finish after I see you log in.

Initial board:
101100001001
000010001011
010011100000
100100111100
101110000011

 -> 0001...
 -> .1.....

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Out-of-bound cells should be considered dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules:

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Most people copy/paste the board above into their code, then convert to a 2D array, adding commas.

Please have your program print out the next iteration of the board.
*/

#define ROWS 5
#define COLS 12


void print_board(int b[ROWS][COLS]){
  for (int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int c_neighbors(int board[ROWS][COLS], int x, int y){
  int count = 0; 
  for (int i = -1; i <= 1; i++){
    for (int j = -1; j <=1; j++){
      if (i != 0 || j != 0){
        int xx = x + i;
        int yy = y + j;

        if( xx >= 0 && xx < ROWS && yy >=0 && yy < COLS){
          count += board [xx][yy];
        }
      }
    }
  }
  return count;
}

void next_gen(int board[ROWS][COLS]){
    
    int new_board[ROWS][COLS];

    for (int i = 0; i < ROWS; i++){
      for(int j = 0; j < COLS; j++){
        int live_n = c_neighbors(board, i , j); // i = 0, j = 0, count = 0;
        if( board[i][j] == 1){
          if(live_n < 2 || live_n > 3) { /* rule 1 and rule 3 */
            new_board[i][j] = 0;
          } else {
            new_board[i][j] = 1;
          }
        } else {
          if (live_n == 3 ){
            new_board[i][j] = 1; /* rule 4 */
          } else {
            new_board[i][j] = 0;
          }
        }
      }
    }

    for (int i = 0; i < ROWS; i++){
      for(int j = 0; j < COLS; j++){
        board[i][j] = new_board[i][j];
      }
    }
}

/* Tested to generate the correct initial board. */
void create_board(int board[ROWS][COLS]){
  int r[5] = {2825,  139, 1248, 2364, 2947};

  /* now store row by row based on set bit */
  for(int i = 0; i < ROWS; i++){
     int val = r[i];
    for (int j = COLS - 1; j >=0; --j){
      int bit = (val >> j) & 1;

      board[i][COLS - 1 - j] = bit;
      //printf(" %d", board[i][COLS - 1 - j]);
    }
    //printf("\n");
  }
}

int main() { 
  int gameboard[ROWS][COLS];

  create_board(gameboard);
  print_board(gameboard);
  next_gen(gameboard);
  print_board(gameboard);

}
/*

initial board -> 
1 0 1 1 0 0 0 0 1 0 0 1 
0 0 0 0 1 0 0 0 1 0 1 1 
0 1 0 0 1 1 1 0 0 0 0 0 
1 0 0 1 0 0 1 1 1 1 0 0 
1 0 1 1 1 0 0 0 0 0 1 1 

Gen one board -> 
0 0 0 1 0 0 0 0 0 1 1 1 
0 1 1 0 1 0 0 1 0 1 1 1 
0 0 0 1 1 0 1 0 0 0 1 0 
1 0 0 0 0 0 1 1 1 1 1 0 
0 1 1 1 1 0 0 1 1 1 1 0 

*/

