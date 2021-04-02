/*
 ============================================================================
 Name        : TicTacToe.c
 Author      : Prasanna
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "TicTacToe.h"
#include <global.h>

void BoardIndexes(board_t *instance){
	instance->cols = num_cols;
	instance->rows = num_rows;


	for(int i = 0; i < ((instance->cols*instance->rows)) ; i++){

				instance->boardArray[i] = i + '0';
		}
	printf("Displaying Indexes...\n");
}


void initBoard(board_t *instance){
	instance->cols = num_cols;
	instance->rows = num_rows;
	instance->p1 = 'x';
	instance->p2 = 'o';

	for(int i = 0; i < ((instance->cols*instance->rows)) ; i++){

				instance->boardArray[i] = '-';
		}
}

void drawBoard(board_t *instance){

	printf("\n  --  --  --\n");
	for(int i = 0; i < instance->rows; i++){
		printf("|");

		for(int j = 0; j < instance->cols; j++){
			printf(" %c |", (char)instance->boardArray[i*instance->rows + j]);
		}
		printf("\n ---------\n");

	}
	printf("\nPlayer 1 -> x\nPlayer2 -> o\n");
	printf("Enter [char][index] to place a char eg. 'x 1' for P1 @ index 1");
}

void depositChar(board_t *instance, char myChar, uint8_t index){

	if(myChar == instance->p1 || myChar == instance->p2){
		if(instance->boardArray[index] == '-')
			instance->boardArray[index] = myChar;
		else
			printf("\nBlock already occupied! Try a different one!");
	}
	else{
		printf("\nEnter valid character!\n");
	}
}

uint8_t checkGame(board_t *instance){

	for(int r = 0; r < instance->rows; r++){
		if(instance->boardArray[r*3] == instance->p1 && instance->boardArray[r*3 + 1] == instance->p1 && instance->boardArray[r*3 + 2] == instance->p1)
			{
			return 1;
			}

		if(instance->boardArray[r*3] == instance->p2 && instance->boardArray[r*3 + 1] == instance->p2 && instance->boardArray[r*3 + 2] == instance->p2)
			return 2;
	}

	for(int c = 0; c < instance->cols; c++){
		if(instance->boardArray[c*3] == instance->p1 && instance->boardArray[c*3 + 1] == instance->p1 && instance->boardArray[c*3 + 2] == instance->p1)
			{
				return 1;
				}

		if(instance->boardArray[c*3] == instance->p2 && instance->boardArray[c*3 + 1] == instance->p2 && instance->boardArray[c*3 + 2] == instance->p2)
			return 2;
	}

	if(instance->boardArray[0] == instance->p1 && instance->boardArray[4] == instance->p1 && instance->boardArray[8] == instance->p1)
		return 1;

	if(instance->boardArray[0] == instance->p2 && instance->boardArray[4] == instance->p2 && instance->boardArray[8] == instance->p2)
		return 2;


	if(instance->boardArray[2] == instance->p1 && instance->boardArray[4] == instance->p1 && instance->boardArray[6] == instance->p1)
		return 1;

	if(instance->boardArray[2] == instance->p2 && instance->boardArray[4] == instance->p2 && instance->boardArray[6] == instance->p2)
		return 2;

	//check for draw
	int count = 0;

	for(int i = 0; i < ((instance->cols*instance->rows)) ; i++){

			if(instance->boardArray[i] == instance->p1 || instance->boardArray[i] == instance->p2){
				count++;
			}
		}

	printf("\nCount val: %d\n", count);
	if(count>8){
		return 3;
	}

	return 5;
}

void clearStdin(){
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}
