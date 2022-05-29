/*
Name: Jason Zhang
Date: 10/3/2019
Period: 4
Program: Tic Tac Toe
*/

#include <iostream>
#include <string>
using namespace std;
struct moves {
  int row;
  int col;
};
//print the board
void printBoard(char board[3][3]){ 
  char letters[3] = {'a', 'b', 'c'};
  cout<<"  1 2 3"<<endl;
  for(int i =0;i<3;i++){
    cout <<letters[i];
    for(int k = 0; k<3; k++){
      cout<<" "<<board[i][k];
    }
    cout<<endl;
  }
}
//check win
bool checkWin(char player, char board[3][3]){
  for(int i = 0; i<3;i++){
    //check if there are 3 colums in a row
    if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
      return true;
    }
    //check if there are 3 rows in a row
    if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
      return true;
    }
  }
  //check for diaganals
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
    return true;
  }
  return false;
}
//check tie
bool isTie(char board[3][3]){
  //loop through board
  for(int i = 0; i<3; i++){
    for(int k = 0; k<3; k++){
      //if a spot is not taken return false
      if(!(board[i][k] == 'X' || board[i][k] == 'O'))
	return false;
    }
  }
  return true;
}
//mark the board
void markBoard(char board[3][3], char player){
  moves move;
  char playerMove[2];
  do{
    //ask for move
    cout<<"What is your move? Enter Row Col. Ex: a2, b3"<<endl;
    //take move in
    cin>>playerMove;
    //make it lower case
    playerMove[0] = tolower(playerMove[0]);
    //add it to the struct move
    move.row = (int)playerMove[0]-97;
    move.col = (int)playerMove[1]-49;
  }
  //make sure it is a valid input
  while(board[move.row][move.col] == 'X' || board[move.row][move.col] == 'O' ||
	!(playerMove[0] == 'a' || playerMove[0] == 'b' || playerMove[0] =='c') ||
	!(playerMove[1] == '1'|| playerMove[1] == '2' || playerMove[1] == '3'));
  //mark the board location
  board[move.row][move.col] = player;
}
int main(){
  int xwins = 0;
  int owins = 0;
  //current player
  while(true){
    //reset the board
    char board[3][3] = {' '};
    char player = 'X';
    while(true){
      //print the board
      printBoard(board);
      //mark the board
      markBoard(board, player);
      //check for x and y wins
      if(checkWin('X', board)){
	cout<<"X Wins!"<<endl;
	xwins++;
	break;
      }
      else if(checkWin('O', board)){
	cout<<"O Wins!" << endl;
	owins++;
	break;
      }
      //check for tie
      else if(isTie(board)){
	cout<<"It's a tie!"<<endl;
	break;
      }
      //swap current player
      if(player == 'X')
	player = 'O';
      else
	player = 'X';
    }
    char playAgain [80];
    printBoard(board);
    cout<<"X wins: "<<xwins<<endl;
    cout<<"O wins: "<<owins<<endl;
    do{
      //ask if they want to play again
      cout<<"Would you like to play again? (y/n)"<<endl;
      cin>>playAgain;
      //if no then return
      if(tolower(playAgain[0]) == 'n'){
	cout<<"Thanks for playing"<<endl;
	return 0;
      }
      //make sure it is a valid input
    } while(!(playAgain[0] == 'n' || playAgain[0] == 'y'));
  } 
}

