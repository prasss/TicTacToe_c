/*
 * TicTacToe.h
 *
 *  Created on: 14-Nov-2020
 *      Author: prasanna
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <global.h>


#define num_rows 3
#define num_cols 3

typedef struct{
	uint8_t rows;
	uint8_t cols;
	char p1;
	char p2;
	char boardArray[num_rows*num_cols];
}board_t;

typedef struct{

}gameplay_t;

/**
 *  initBoard() is a function that updates the board with a default character
 *  It takes in the variable instance
 */
void initBoard(board_t *instance);

/**
 *  BoardIndexes() is a function that updates the board with the index numbers
 *  It takes in the variable instance
 */
void BoardIndexes(board_t *instance);

/**
 *  drawBoard() is a function that displays the board with the latest changes
 *  It takes in the variable instance
 */
void drawBoard(board_t *instance);

/**
 *  depositChar() is a function that updates the board with a character
 *  It takes in the variables instance, myChar, index
 */
void depositChar(board_t *instance, char myChar, uint8_t index);


/**
 *  checkGame() is a function that Checks for winners/draw
 *  It takes in the variables instance
 */
uint8_t checkGame(board_t *instance);


void clearStdin();




#endif /* TICTACTOE_H_ */
