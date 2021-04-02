/*
 * main.c
 *
 *  Created on: 14-Nov-2020
 *      Author: prasanna
 */

#include "TicTacToe.h"
#include <stdio.h>

int main(){

	board_t newBoard;

	int v = 126;
	printf("\n%c\n",v);

	BoardIndexes(&newBoard);
	drawBoard(&newBoard);

	initBoard(&newBoard);
//	drawBoard(&newBoard);
//	depositChar(&newBoard, 'x', 5);
//	drawBoard(&newBoard);

	uint8_t game = 0; //0 -> no status, 1 -> P1 wins, 2 -> P2 wins, 3-> Draw
	char playerChar;
	int index;

	do{
		printf("\nPlease provide an input: ");
		scanf(" %c%d", &playerChar, &index);
		printf("Player entered the value: %c%d\n", playerChar, index);

		depositChar(&newBoard, playerChar, index);
		drawBoard(&newBoard);

		game = checkGame(&newBoard);

		printf("\nGame val: %d\n\n", game);

		switch(game){
			case 1:
				printf("*** Player 1 wins! ***");
				break;

			case 2:
				printf("*** Player 2 wins! ***");
				break;

			case 3:
				printf("*** Game draw! ***");
				break;

			case 5:
				printf("*** Game continues ***");
				break;
		}



		clearStdin();

	}while(!(game == 1 || game == 2 || game == 3));

	printf("\nLoop exited!");


	return 0;
}





