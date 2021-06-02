// TTTT = Tic Tac Toe Table.
#include "TTTT.h"


std::string g_UserResponse;
//bool hasSurrendered = false;
int g_UserChoiceResponse;
bool g_player1Turn = false;
bool g_player2Turn = false;

int moves = 9;
//char g_player1Character = 'X';
//char g_player2Character = 'Y';



std::string board[7][8] =
{
	{	{"0"}, {"0"}, {"0"}, {"0"}, {"0"}, {"0"},	},
	{	{"0"}, {"1"}, {"0"}, {"2"}, {"0"}, {"3"},	},
	{	{"0"}, {"0"}, {"0"}, {"0"}, {"0"}, {"0"},	},
	{	{"0"}, {"4"}, {"0"}, {"5"}, {"0"}, {"6"},	},
	{	{"0"}, {"0"}, {"0"}, {"0"}, {"0"}, {"0"},	},
	{	{"0"}, {"7"}, {"0"}, {"8"}, {"0"}, {"9"},	},
	{	{"0"}, {"0"}, {"0"}, {"0"}, {"0"}, {"0"},	}

};

void Draw()
{
	using namespace std;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == "0")
			{
				cout << '*';
			}

			else
			{
				cout << " ";
			}
		}

		cout << " " << endl;
	}
}




void Player::askUserTurn()
{
	using namespace std;
	cout << "Do you want to start first ? (Y/N)" << endl;

	cin >> g_UserResponse;

	if (g_UserResponse == "Y")
	{
		cout << "Player 1 will start first " << endl;


		g_player1Turn = true;

	}
	else
	{
		cout << "Player 2 will start first " << endl;

		g_player2Turn = true;

	}
}


void Player::playerTurn()
{
	using namespace std;
	if (g_player1Turn)
	{
		cout << "Player 1 Turn :" << endl;
		Player::Choices();
		g_player1Turn = false;
		g_player2Turn = true;
	}

	if (g_player2Turn)
	{
		cout << "Player 2 Turn :" << endl;
		Player::Choices();
		g_player1Turn = true;
		g_player2Turn = false;
	}
}



void Player::surrender()
{
	using namespace std;
	if (g_player1Turn)
	{
		cout << "Player 1 has surrendered, Player 2 wins." << endl;
		exit(3);
		
	}

	else
	{
		cout << "Player 2 has surrendered, Player 1 wins" << endl;
		exit(3);
		
	}



}


void Player::Choices()
{
	using namespace std;


	
	cout << "Choose one of the following :" << endl;
	cout << "1. Place" << endl;
	cout << "2. Surrender" << endl;

	cin >> g_UserChoiceResponse;

	switch (g_UserChoiceResponse)
	{
	case 1:
		makeAMove();
		Draw();
		break;

	case 2:
		Player::surrender();
		break;

	default:
		cout << "Error, unknown command." << endl;
		break;

	}
}

void Player::makeAMove()
{
	

	int res;

	using namespace std;

	cout << "Where do you want to place it? (choose either : 1, 2, 3, 4, 5, 6, 7, 8, 9)" << endl;

	cin >> res;
	if (g_player1Turn)
	{
		switch (res)
		{
		case 1:
			board[1][1] = 'X';
			break;

		case 2:
			board[1][3] = 'X';
			break;

		case 3:
			board[1][5] = 'X';
			break;

		case 4:
			board[3][1] = 'X';
			break;

		case 5:
			board[3][3] = 'X';
			break;
		case 6:

			board[3][5] = 'X';
			break;

		case 7:
			board[5][1] = 'X';
			break;

		case 8:
			board[5][3] = 'X';
			break;

		case 9:
			board[5][5] = 'X';
			break;

		default:
			cout << "Error, unknown command." << endl;
			break;
		}
	}

	if (g_player2Turn)
	{
		switch (res)
		{
		case 1:
			board[1][1] = 'Y';
			break;

		case 2:
			board[1][3] = 'Y';
			break;

		case 3:
			board[1][5] = 'Y';
			break;

		case 4:
			board[3][1] = 'Y';
			break;

		case 5:
			board[3][3] = 'Y';
			break;
		case 6:

			board[3][5] = 'Y';
			break;

		case 7:
			board[5][1] = 'Y';
			break;

		case 8:
			board[5][3] = 'Y';
			break;

		case 9:
			board[5][5] = 'Y';
			break;

		default:
			cout << "Error, unknown command." << endl;
			break;
		}
	}

}