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
		if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
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

void turnChange() {
	if(turn == 'X') 
		turn = 'O';
	else
		turn = 'X';
}
int main() {
	cout << "Welcome to Tic Tac Toe" << endl;
	cout << "This is the gameboard. You will input the number to designate where you are going" << endl;
	printBoard();
	while(1) {
		input();
		printBoard();
		turnChange();
		colWin();
	}
	return 0;
}