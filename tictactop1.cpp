#include <iostream>
using namespace std;

#define SIZE 3
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
int player = 1;
bool isEndGame = false;
bool isTie = false;

void printBoard()
{
	cout << "-------------" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << endl;
		cout << "-------------" << endl;
	}
}

void update()
{
	char mark;
	player = (player % 2) ? 1 : 2;
	mark = (player == 1) ? 'X' : 'O';

	int x, y;
	do
	{
		cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
		cin >> x >> y;
	} while (x > 2 || y > 2 || board[x][y] != ' ');

	if (board[x][y] == ' ')
		board[x][y] = mark;
	player++;
}

bool checkWin()
{
	if (board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2])
		return true;
	else if (board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2])
		return true;
	else if (board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2])
		return true;
	else if (board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0])
		return true;
	else if (board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1])
		return true;
	else if (board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2])
		return true;
	else if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return true;
	else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return true;
	else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
		board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
		board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
	{
		isTie = true;
		return true;
	}
	return false;
}

int main()
{
	cout << "GAME TICTACTOE!!!" << endl;
	cout << "PLAYER 1 = [X]" << endl;
	cout << "PLAYER 2 = [O]" << endl;

    printBoard();

	while (!isEndGame)
	{
		update();
		printBoard();
		isEndGame = checkWin();

		if (isEndGame)
		{
			if (isTie)
				cout << "Game Over! It's a tie!";
			else
				cout << "Player " << player - 1 << " is winner" << endl;
		}
	}
	return 0;
}

