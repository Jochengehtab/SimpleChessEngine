#ifndef DEFINISIONS
#define DEFINISIONS

// This defindes a new DataType
typedef unsigned long long U64;

#define NAME "Engine"
#define BOARD_SQUARE_NUMBER 120

#define MAXGAMESMOVES 2048

// This enum represents all of the pieces 
enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };

// This enum contains all of the files
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_NONE };

// This enum contains all of the ranks
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

// This enum contains all of the colors
enum { WHITE, BLACK, BOTH };

// This enum initialiezres all 120 squares
enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { FALSE, TRUE };

// This holds the casteling rights for each side
enum {WhiteKingCasteling = 1, WhiteQueenCasteling = 2, BlackKingCasteling = 4, BlackQueenCasteling = 8};

typedef struct {
	
	int move;
	int castelePerm;
	int enPassant;
	int fifty_Move_Rule;
	U64 posKey;
	
} S_UNDO;

typedef struct {
	// This makes an Array of the board in this case of the size of 120
	int pieces[BOARD_SQUARE_NUMBER];
	
	// This represents the color of the pawns on the board
	U64 pawns[3];
	
	// This holds the King Squares
	int KingsSquare[2];
	
	// This holds the current side that moves
	int side;
	
	//This holdes if enPassant is avaible
	int enPassant;
	
	// This is the counter for the fifty-Move-Rule
	int fiftyMoveCounter;
	
	// This represents how many halfmoves are we in the game
	int play;
	
	// This represents how many halfmoves are made in the hole game
	// This is useful for preventing repition of moves for example
	int historyPlay;
	
	// This holds the castle permissions
	int castelePerm;
	
	// This is a key that gets generated for each unique position
	U64 posKey;
	
	// This represents the number of paces that we have on the board
	int pceNum[13];
	
	// The following arrys are indexed with 3 because there get the pieces for each color stored
	// This stores the number of big pieces for example a Rook or anything that isnt a pawn
	int big[3];
	
	// This stores the Rook and Queen
	int majorPieces[3];
	
	// This stores the Knight and Bishop
	int minPieces[3];
	
	S_UNDO history[MAXGAMESMOVES];
	
} S_BOARD;

#endif
