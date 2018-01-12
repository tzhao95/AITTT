#include <iostream>

using namespace std;

char board[3][3] = {'1', '2', '3',
					'4', '5', '6',
					'7', '8', '9'};
char turn = 'X';

void printBoard() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void input() {
	int x; 
	cout << "Where do you want to go? ";
	cin >> x;

	x--;
	board[x/3][x%3] = turn;
}

int rowWin() {
	for(int i = 0; i < 3; i++) {
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
			cout << "WINNER WINNER CHICKEN DINNER" << endl;
			return 1;
		}
	}
	return 0;
}

int colWin() {
	for(int i = 0; i < 3; i++) {
		if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') {
			cout << "WINNER WINNER CHICKEN DINNER" << endl;
			return 1;
		}
	}
	return 0;
}

char Win() {
	for(int i = 0; i < 3; i++) {
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return board[i][0];
		if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return board[0][i];
	}
	return '.';
}	

void turnChange() {
	if(turn == 'X') 
		turn = 'O';
	else
		turn = 'X';
}
int main() {
	cout << board[0][0] << endl;
	cout << "Welcome to Tic Tac Toe" << endl;
	cout << "This is the gameboard. You will input the number to designate where you are going" << endl;
	printBoard();
	while(1) {
		input();
		printBoard();
		turnChange();
		rowWin();
		colWin();
	}
	return 0;
}