#ifndef BOARD_H
#define BOARD_H
#define BOARDSIZE = 24;

// int board[BOARDSIZE][BOARDSIZE]

void loadBoard();
void createNewBoard();
void saveBoard();
void listBoards();
void updateBoard(int board[][24], int x, int y, int p);

#endif