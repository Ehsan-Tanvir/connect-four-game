#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
void credit();
void instructions();
void play_game();
bool toss();
int player1(char arr[][4]);
int player2(char arr[][4]);
void Data(char arr[][4], int size, char Turn);
void Board(char arr[][4], int size);
void check(char arr[][4], int size);
void draw(char arr[][4], int size);
int toss1;
//Main Function//
int static row = 3;
int main()
{
	cout << "press 0 if you dont want to play Game." << endl;
	cout << "press 1 for viewing the production team of Game" << endl;
	cout << "press 2 for viewing the instructions of Game." << endl;
	cout << "press 3 for if you want to play the Game." << endl;
	bool ooo = true;
	int oo;
	while (ooo)
	{
		cout << "Enter choice" << endl;
		cin >> oo;
		if (oo == 1)
		{
			credit();
		}
		if (oo == 2)
		{
			instructions();
		}
		if (oo == 3)
		{
			play_game();
		}
		if (oo == 0)
		{
			cout << "BYE" << endl;
			ooo = false;
		}
	}
	system("pause");
	return 0;
}
//Function for representing the name//
void credit()
{
	cout << "This Game is created by:" << endl;
	cout << "   Ehsan Tanvir" << endl;
	cout << endl;
}
//function for the instructions//
void instructions()
{
	cout << "Some instructions were given below:" << endl;
	cout << "1. Players must connect 4 of the same colored discs in a row to win." << endl;
	cout << "2. Only one piece is played at a time." << endl;
	cout << "3. Players can be on the offensive or defensive." << endl;
	cout << "4. The game ends when there is a 4 - in - a - row or a stalemate." << endl;
	cout << "5. The starter of the previous game goes second on the next game." << endl;
	cout << "6. please enter only an integer value not a character otherwise game ends " << endl;
	cout << endl;
}
//play game function//
void play_game()
{
	cout << "Welcome to the game CONNECT FOUR" << endl;
	char arr[4][4];
	char Turn = ' ';
	//Board//
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = '*';
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "   " << arr[i][j] << "   ";
		}
		cout << endl << endl << endl;
	}
	cout << "Player 1 is represented by A" << endl;
	cout << "Player 2 is represented by B" << endl;
	cout << endl;
	//Toss//
	toss1 = toss();
	if (toss1 == 0)
	{
		Turn = 'A';
		cout << "Player 1 win the toss" << endl;
	}
	else
	{
		Turn = 'B';
		cout << "Player 2 win the toss" << endl;
	}
	cout << endl;
	//input the data//
	while (true)
	{
		if (Turn == 'A')
			player1(arr), Turn = 'B';
		else
			player2(arr), Turn = 'A';
	}
}
//function of Board//
void Board(char arr[][4], int size)
{
	system("CLS");
	cout <<"         CONNECT FOUR" << endl;
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "   " << arr[i][j] << "   ";
		}
		cout << endl << endl << endl;
	}
}
//function of toss//
bool toss()
{
	bool status = true;
	int num;
	srand(time(0));
	num = (rand() % 2) + 1;
	if (num == 1)
	{
		status = false;
	}
	return status;
}
//function for player 1//
int player1(char arr[][4])
{
	int size = 4;
	cout << "Player 1 please enter the data" << endl;
	Data(arr, size, 'A');
	Board(arr, size);
	check(arr, size);
	draw(arr, size);
	return 0;
}
//function for player 2//
int player2(char arr[][4])
{
	int size = 4;
	cout << "Player 2 please enter data" << endl;
	Data(arr, size, 'B');
	Board(arr, size);
	check(arr, size);
	draw(arr, size);
	return 0;
}
//function for the data entering//
void Data(char arr[][4], int size, char Turn)
{
	int col;
	cout << "Enter column number" << endl;
	cin >> col;
	//check for invalid input//
	if (col != 0 && col != 1 && col != 2 && col != 3)
	{
		cout << "Game ends due to invalid input" << endl;
		exit(0);
	}
	int row = (size - 1);
	while (true)
	{
		if (row < 0 || col > 3)
		{
			cout << "\n Invalid Entry \n";
			cout << " Enter column number Again " << endl;
			cin >> col;
			row = (size - 1);
			continue;
		}
		else if (Turn == 'A' && arr[row][col] == '*')
		{
			arr[row][col] = 'A';
			break;
		}
		else if (Turn == 'B' && arr[row][col] == '*')
		{
			arr[row][col] = 'B';
			break;
		}
		row--;
	}
}
//check//
void check(char arr[][4], int size)
{
	//for left diagonal//
	if (arr[0][0] == 'A' && arr[1][1] == 'A' && arr[2][2] == 'A' && arr[3][3] == 'A')
	{
		cout << "player 1 wins" << endl;
		exit(0);
	}
	if (arr[0][0] == 'B' && arr[1][1] == 'B' && arr[2][2] == 'B' && arr[3][3] == 'B')
	{
		cout << "player 2 wins" << endl;
		exit(0);
	}
	//for right diagonal//
	if (arr[0][3] == 'A' && arr[1][2] == 'A' && arr[2][1] == 'A' && arr[3][0] == 'A')
	{
		cout << "player 1 wins" << endl;
		exit(0);
	}
	if (arr[0][3] == 'B' && arr[1][2] == 'B' && arr[2][1] == 'B' && arr[3][0] == 'B')
	{
		cout << "player 2 wins" << endl;
		exit(0);
	}
	//for rows//
	if (arr[0][0] == 'A' && arr[0][1] == 'A' && arr[0][2] == 'A' && arr[0][3] == 'A')
	{
		cout << "player 1 wins" << endl;
		exit(0);
	}
	if (arr[1][0] == 'A' && arr[1][1] == 'A' && arr[1][2] == 'A' && arr[1][3] == 'A')
	{
		cout << "player 1 wins" << endl;
		exit(0);
	}
	if (arr[2][0] == 'A' && arr[2][1] == 'A' && arr[2][2] == 'A' && arr[2][3] == 'A')
	{
		cout << "player 1 wins" << endl;
		exit(0);
	}
	if (arr[3][0] == 'A' && arr[3][1] == 'A' && arr[3][2] == 'A' && arr[3][3] == 'A')
	{
		cout << "player 1 wins" << endl;
		exit(0);
	}
	//
	if (arr[0][0] == 'B' && arr[0][1] == 'B' && arr[0][2] == 'B' && arr[0][3] == 'B')
	{
		cout << "player 2 wins" << endl;
		exit(0);
	}
	if (arr[1][0] == 'B' && arr[1][1] == 'B' && arr[1][2] == 'B' && arr[1][3] == 'B')
	{
		cout << "player 2 wins" << endl;
		exit(0);
	}
	if (arr[2][0] == 'B' && arr[2][1] == 'B' && arr[2][2] == 'B' && arr[2][3] == 'B')
	{
		cout << "player 2 wins" << endl;
		exit(0);
	}
	if (arr[3][0] == 'B' && arr[3][1] == 'B' && arr[3][2] == 'B' && arr[3][3] == 'B')
	{
		cout << "player 2 wins" << endl;
		exit(0);
	}
	//For columns//
	if (arr[0][0] == 'A' && arr[1][0] == 'A' && arr[2][0] == 'A' && arr[3][0] == 'A')
	{
		cout << "player 1 wins" << endl;
		exit(0);
	}
	if (arr[0][1] == 'A' && arr[1][1] == 'A' && arr[2][1] == 'A' && arr[3][1] == 'A')
	{
		cout << "player 1 wins" << endl;
		exit(0);
	}
	if (arr[0][2] == 'A' && arr[1][2] == 'A' && arr[2][2] == 'A' && arr[3][2] == 'A')
	{
		cout << "player 1 wins" << endl;
		exit(0);
	}
	if (arr[0][3] == 'A' && arr[1][3] == 'A' && arr[2][3] == 'A' && arr[3][3] == 'A')
	{
		cout << "player 1 wins" << endl;
		exit(0);
	}
	//
	if (arr[0][0] == 'B' && arr[1][0] == 'B' && arr[2][0] == 'B' && arr[3][0] == 'B')
	{
		cout << "player 2 wins" << endl;
		exit(0);
	}
	if (arr[0][1] == 'B' && arr[1][1] == 'B' && arr[2][1] == 'B' && arr[3][1] == 'B')
	{
		cout << "player 2 wins" << endl;
		exit(0);
	}
	if (arr[0][2] == 'B' && arr[1][2] == 'B' && arr[2][2] == 'B' && arr[3][2] == 'B')
	{
		cout << "player 2 wins" << endl;
		exit(0);
	}
	if (arr[0][3] == 'B' && arr[1][3] == 'B' && arr[2][3] == 'B' && arr[3][3] == 'B')
	{
		cout << "player 2 wins" << endl;
		exit(0);
	}
}//draw//
void draw(char arr[][4], int size)
{
	if ((arr[0][0] == 'A' || arr[0][0] == 'B') && (arr[0][1] == 'A' || arr[0][1] == 'B') && (arr[0][2] == 'A' || arr[0][2] == 'B') && (arr[0][3] == 'A' || arr[0][3] == 'B'))
	{
		cout << "None of the player Wins" << endl;
		exit(0);
	}
}

