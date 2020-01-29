/*
	CO222-2019 Lab05
	Author: E/16/332

	TicTacToe game
*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 3

void scanBoard(int a[SIZE][SIZE]);
void printBoard(int b[SIZE][SIZE]);
int getWinner(int b[SIZE][SIZE]);

int main(){

	int inBoard[SIZE][SIZE];	//declaring an array

	printf("Please enter the board:\n");
	scanBoard(inBoard);	//scanBoard
	printf("Here is the board:\n");
	printBoard(inBoard);	//printBoard

	//printing the result
	if(getWinner(inBoard)==0)	
		printf("Noughts win\n");
	else if(getWinner(inBoard)==1)
		printf("Crosses win\n");
	else
		printf("There are no winners\n");
	
	return 0;
}


//scan function
void scanBoard(int board[SIZE][SIZE]){
	
	//check if the input is 0 || 1 || 2
	//else give the error message "Enter valid input." and terminate the program
	for(int i =0;i<SIZE;i++){
		
		for(int j=0;j<SIZE;j++){
			scanf("%d",&board[i][j]);
			
		}
		    printf("\n");
		
		//checking inputs
		for(int j=0;j<SIZE;j++){
			if(board[i][j]==0 ) continue;
			if(board[i][j]==1) continue;
			if(board[i][j]==2) continue;
			else{ printf("error"); 
			exit(0);}
		}
		
		
	
	}
	return;
}


//print function
void printBoard(int board[SIZE][SIZE]){
	//printing board
	for(int i=0;i<SIZE;i++){
		
		for(int j=0;j<SIZE;j++){
			if(board[i][j]==1)
		       printf("X ");
           	else if(board[i][j]==0)
				printf("0 ");
			else
				printf("_ ");
		}
		
	printf("\n");
	}
return;	
}


//find the winner of the game
//assume both two players can't win the game at the same time. It can't happen in a real game
int getWinner(int board[SIZE][SIZE]){
	
	int winner = 2;	
	
	//if winner is Noughts, winner = 0
	//if winner is Crosses, winner = 1
	//if there is no winner, winner = 2
	
	//check rows
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE-1;j++){
		
	       if(board[i][j]==board[i][j+1]){
		     
			 
				 if(board[i][j]==1){ winner=1;}
				 else {winner=0;}
			}
           else{ 
		   winner=2;
		   break;}			
		
	   }  
	
	if(winner==0||1){break;}
	
	}
	
	
	//check colloms
	
if(winner==2){
	
for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE-1;j++){
		
	       if(board[j][i]==board[j+1][i]){
		     
			 
				 if(board[j][i]==1){ winner=1;}
				 else {winner=0;}
			}
           else{ 
		   winner=2;
		   break;}			
		
	 }  
	if(winner==0||1){break;}
	
	}
}	
	
	//check the diagonals;
if(winner==2){	
for(int i=0;i<SIZE-1;i++){

		
	       if(board[i][i]==board[i+1][i+1]){
		     
			 
				 if(board[i][i]==1){ winner=1;}
				 else {winner=0;}
			}
           else{ 
		   winner=2;
		   break;}			
}
}	


if(winner==2){	
for(int i=0;i<SIZE-1;i++){

		
	       if(board[i][SIZE-1-i]==board[i+1][SIZE-2-i]){
		     
			 
				 if(board[i][SIZE-1-i]==1){ winner=1;}
				 else {winner=0;}
			}
           else{ 
		   winner=2;
		   break;}			
}
}
	return  winner;
}