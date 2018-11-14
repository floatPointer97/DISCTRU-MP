/* DISCTRU MACHINE PROJECT 
 * AUTHORS: DEQUITO, CHRISTIAN && GERRA-CLARIN, MICHAEL RYAN && ROQUE, JOHN MARVIC
 * SECTION: S19
 * SUBMITTED TO: PROF. SHIRLEY CHU
 * SUBMITTED ON: APRIL 02, 2017
 * ABOUT THE PROGRAM: This program simulates a game which is a crossover of Magic Squares and
 *										Tic-Tac-Toe. This program was interpreted from the MP specifications given.
 */
#include <stdio.h>
#include <stdlib.h>

/* This function searches through the given array to check if the number 
 * was used throughout the game.
 * @param array[] = to check if the elements of the array were passed already
 * @param max = maximum number of times to complete the loop
 * @param input = passes the user's input to check if it was passed before
 * @return = 1 if the input was not passed before and 0 for the opposite
 */
int
Search(int array[],int max,int input)
{
	int i;
	
	for(i=0; i<max; i++)
	{
		if(input == array[i])
			return 0;
	}
	return 1;
}

/* This function counts the elements inside the array if they add up to 15,
 * which is the total to win the game.
 * @param array[] = to add all the elements inside the array
 * @return = 1 if the elements add up to 15 and 0 if not
 */
int
Count(int array[])
{
	int i;
	int sum=0;
	
	for(i=0; i<3; i++)
		sum = sum + array[i];
	if(sum==15)
		return 1;
		
	return 0;
}

/* This function checks the array only if there are 3 elements stored inside
 * the array, and if the Count() function has returned 1.
 * @param array[] = to check if the array has 3 elements inside
 * @return = 1 if there are elements in the array given and the has a total 
 * sum of 15 and 0 if not.
 */
int
Check(int array[])
{
	if(array[3]==3 && Count(array)==1)
		return 1;
	return 0;
		
}

/* This function prints the preliminary grid for the game's 
 * visual representation.
 * @param p11 = pointer for coordinate (1,1)
 * @param p12 = pointer for coordinate (1,2)
 * @param p13 = pointer for coordinate (1,3)
 * @param p21 = pointer for coordinate (2,1)
 * @param p22 = pointer for coordinate (2,2)
 * @param p23 = pointer for coordinate (2,3)
 * @param p31 = pointer for coordinate (3,1)
 * @param p32 = pointer for coordinate (3,2)
 * @param p33 = pointer for coordinate (3,3) 
 */
void
printBoard(char *p11, char *p12, char *p13,
			char *p21, char *p22, char *p23,
			char *p31, char *p32, char *p33)
{
	
	
  printf(" _______________________\n");
	printf("|       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |\n", *p11, *p12, *p13);
	printf("|_______|_______|_______|\n");
	printf("|       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |\n", *p21, *p22, *p23);
	printf("|_______|_______|_______|\n");
	printf("|       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |\n", *p31, *p32, *p33);
	printf("|_______|_______|_______|\n");
	
	
}

/* This function prints the grid for the game, and that the 
 * values inside are now changed by switched statements and 
 * inputs.
 * @param row = passes the user's input for row
 * @param col = passes the user's input for col
 * @param pass = passes the user's input to be placed in the specific 
 *               coordinate.
 * @param p11 = pointer for coordinate (1,1)
 * @param p12 = pointer for coordinate (1,2)
 * @param p13 = pointer for coordinate (1,3)
 * @param p21 = pointer for coordinate (2,1)
 * @param p22 = pointer for coordinate (2,2)
 * @param p23 = pointer for coordinate (2,3)
 * @param p31 = pointer for coordinate (3,1)
 * @param p32 = pointer for coordinate (3,2)
 * @param p33 = pointer for coordinate (3,3)
 */
void
printBoard2(int row, int col, int pass,
						char *p11, char *p12, char *p13,
						char *p21, char *p22, char *p23,
						char *p31, char *p32, char *p33)
{
	
	
	switch(row * 10 + col)
	{
		case 11: *p11 = pass+48;
						break;
		case 12: *p12 = pass+48;
						break;
		case 13: *p13 = pass+48;
						break;
		case 21: *p21 = pass+48;
						break;
		case 22: *p22 = pass+48;
						break;
		case 23: *p23 = pass+48;
						break;
		case 31: *p31 = pass+48;
						break;
		case 32: *p32 = pass+48;
						break;
		case 33: *p33 = pass+48;
						break;				
	}
	
  printf(" _______________________\n");
	printf("|       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |\n", *p11, *p12, *p13);
	printf("|_______|_______|_______|\n");
	printf("|       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |\n", *p21, *p22, *p23);
	printf("|_______|_______|_______|\n");
	printf("|       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |\n", *p31, *p32, *p33);
	printf("|_______|_______|_______|\n");
	
	
}

/* This function checks if there is a winner or if the match ends in a draw
 * @param nice = if it's value is 1 it implies that there was a successful 
 *               combination that adds up to 15 
 * @param turn = if it's value is 1 it implies that the combination that led 
 *               to 15 was made on the 1st player's turn, and 0 if made on 
 *               the 2nd player's turn. 
 */
void
EndGame(int nice, int turn)
{
	
	if(nice == 1 && turn == 1)
		printf("PLAYER 1 WINS!\n");	
	else if(nice == 1 && turn == 0)
		printf("PLAYER 2 WINS!\n");
	else
		printf("MATCH IS A DRAW!\n");
	
	exit(1);
}

int 
main()
{
	int P[3][3];

  //int J[3] = {P[0][0], P[0][1], P[0][2]};
  //int K[3] = {P[2][0], P[2][1], P[2][2]};
  //int L[3] = {P[0][0], P[1][1], P[2][2]};
  //int M[3] = {P[2][1], P[1][1], P[0][2]};

	int uno[4];
	int dos[4];
	int tres[4];
	int quad[4];
	
	int free[9] = {11, 12, 13, 21, 22, 23, 31, 32, 33};
// int tposn[9];
  int over = 0;
  int turn = 1;
  int good = 0;
  int nice = 0;
//  int F[5] = {1, 3, 5, 7, 9};
//  int S[5] = {0, 2, 4, 6, 8};
  int move;
  int posn = 0;

  int row;
  int col;
  int i;
  int j;

	char p11=' ', p12=' ', p13=' ';
	char p21=' ', p22=' ', p23=' ';
	char p31=' ', p32=' ', p33=' ';
	
	uno[0] = -9999;
	dos[0] = -9999;
	tres[0] = -9999;
	uno[1] = -9999;
	dos[1] = -9999;
	tres[1] = -9999;
	uno[2] = -9999;
	dos[2] = -9999;
	tres[2] = -9999;
	uno[3] = 0;
	dos[3] = 0;
	tres[3] = 0;
	quad[3] = 0;	
	
	printBoard(&p11, &p12, &p13, &p21, &p22, &p23, &p31, &p32, &p33);
	
	for(i = 0; i < 9; i++)
	{
		while(good==0)
		{
			if(turn==1)
				printf("Player 1's turn\nInput ODD number\n");
			else if(turn == 0)
				printf("Player 2's turn\nInput EVEN number\n'");
				
			printf("\nInput row: ");
			scanf("%d", &row);
	  		printf("Input column: ");
			scanf("%d", &col);
			printf("Input number to be put inside: ");
			scanf("%d", &move);
				
			posn = row * 10 + col;
				
			system("cls");
			//to check if the move is valid
			if(move >= 0 && move <= 9 && !Search(free, 9, posn) && Search(uno, 3, move) && Search(dos, 3, move) && Search(tres, 3, move))
			{		
				
				if((turn==1 && move%2==1)||(turn==0 && move%2==0))
					good = 1;
				else
				{
					if(turn==1)
						printf("Input ODD number\n");
					else if(turn == 0)
						printf("Input EVEN number\n'");
				}
				
			}
			else
				printf("That number is INVALID!\n");
			//to check where to put the move
			if(good==1 && !Search(free, 9, posn) && (posn==11 || posn==12 || posn==13))
			{
				uno[(uno[3])] = move;
				uno[3]++;
			}
			if(good==1 && !Search(free, 9, posn) && (posn==31 || posn==32 || posn==33))
			{
				dos[(dos[3])] = move;
				dos[3]++;
			}
			if(good==1 && !Search(free, 9, posn) && (posn==11 || posn==22 || posn==33))
			{
				tres[(tres[3])] = move;
				tres[3]++;
			}
			if(good==1 && !Search(free, 9, posn) && (posn==31 || posn==22 || posn==13))
			{
				quad[(quad[3])] = move;
				quad[3]++;
			}
			
			if(good==0)
				printBoard(&p11, &p12, &p13, &p21, &p22, &p23, &p31, &p32, &p33);
		}
		//to check if there's a winner
		if(good==1 && !Search(free, 9, posn) && (Check(uno)||Check(dos)||Check(tres)||Check(quad)))
		{
			over = 1;
			nice = 1;
		}
		//to update everything
		if(good==1 && over == 0 && !Search(free, 9, posn))
		{
			if(turn == 1)
				turn=0;
			else
				turn=1;
				
			//tposn[i] = posn;
			
			for(j=0; j<9; j++)
			{
				if(free[j] == posn)
					free[j] = 0;
			}
			
			printBoard2(row, col, move, &p11, &p12, &p13, &p21, &p22, &p23, &p31, &p32, &p33);
		}
				
		if(over == 0 && i == 8) 
			over = 1;

		good = 0;	
		
		if(over == 1)
		{
			printBoard2(row, col, move, &p11, &p12, &p13, &p21, &p22, &p23, &p31, &p32, &p33);
			EndGame(nice, turn);
		}
				
	}
	
	return 0; 
}

