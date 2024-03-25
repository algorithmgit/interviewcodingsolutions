/* 

// Chess game more recorder :
// Observing two people playing a chess game, then define data structure to record all the moves (so it to be retrived later). 

// Assumptions:
// Do not need to check the validity of the move 

// Goals :
// Minimize the memory usage (imagine this being used in a $5 eletronic chess board game)

// 8x8 chess game
// per side: rook x2, knight x2, bishop x2, queen, king, pawn x8, 

// 1) Data structure 
// 2) moving knight (1-offset) row 1 col 2 -> rol 3 col 3 // how would your API look to capture this move?

*/


#include <stdio.h>
#include <stdbool.h>

#define MAX_MOVES 100

typedef enum {
    EMPTY,
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
} ChessPiece;

// Define bitfields to save memory
typedef struct {
    unsigned int piece : 3; // Using 3 bits to represent 7 different ChessPiece values
    unsigned int start_row : 4; // Assuming board rows can be represented in 4 bits (0-15)
    unsigned int start_col : 4; // Assuming board columns can be represented in 4 bits (0-15)
    unsigned int end_row : 4; // Assuming board rows can be represented in 4 bits (0-15)
    unsigned int end_col : 4; // Assuming board columns can be represented in 4 bits (0-15)
} ChessMove;

ChessMove moves[MAX_MOVES];
int num_moves = 0;

void recordMove(ChessMove move) {
    if (num_moves < MAX_MOVES) {
        moves[num_moves] = move;
        num_moves++;
        printf("Move recorded: %d from (%d, %d) to (%d, %d)\n", move.piece, move.start_row, move.start_col, move.end_row, move.end_col);
    } else
        printf("Cannot record move. Maximum moves reached.\n");
}

int main() {
    // Record some sample moves
    ChessMove move1 = {KNIGHT, 1, 2, 3, 3};
    recordMove(move1);

    // Display recorded moves
    printf("Recorded moves:\n");
    for (int i = 0; i < num_moves; i++) {
        printf("Move %d: %d from (%d, %d) to (%d, %d)\n", i+1, moves[i].piece, moves[i].start_row, moves[i].start_col, moves[i].end_row, moves[i].end_col);
    }

    return 0;
}


/* Output 
Move recorded: 3 from (1, 2) to (3, 3)
Recorded moves:
Move 1: 3 from (1, 2) to (3, 3)
*/

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

/* Implementation before the above description was provided */ 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_MOVES 100

// Structure to represent a chess move
typedef struct {
    char piece;         // Piece moved (e.g., 'P' for pawn, 'R' for rook)
    char start[3];      // Starting position (e.g., "e2")
    char end[3];        // Ending position (e.g., "e4")
} ChessMove;

// Array to store recorded moves
ChessMove moves[MAX_MOVES];
int num_moves = 0;

// Function to record a move
void recordMove(char piece, const char* start, const char* end) {
    if (num_moves < MAX_MOVES) {
        moves[num_moves].piece = piece;
        strcpy(moves[num_moves].start, start);
        strcpy(moves[num_moves].end, end);
        num_moves++;
        printf("Move recorded: %c from %s to %s\n", piece, start, end);
    } else {
        printf("Cannot record move. Maximum moves reached.\n");
    }
}

// Function to display recorded moves
void displayMoves() {
    printf("Recorded moves:\n");
    for (int i = 0; i < num_moves; i++) {
        printf("%c: %s -> %s\n", moves[i].piece, moves[i].start, moves[i].end);
    }
}

int main() {
    // Record some sample moves
    recordMove('P', "e2", "e4");
    recordMove('N', "g1", "f3");
    recordMove('P', "d7", "d5");

    // Display recorded moves
    displayMoves();

    return 0;
}

/* Output :

Move recorded: P from e2 to e4
Move recorded: N from g1 to f3
Move recorded: P from d7 to d5
Recorded moves:
P: e2 -> e4
N: g1 -> f3
P: d7 -> d5

*/
