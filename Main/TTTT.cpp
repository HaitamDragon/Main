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



char board[7][8] =
{
	{	{'0'}, {'0'}, {'0'}, {'0'}, {'0'}, {'0'}, {'0'}	},
	{	{'0'}, {'1'}, {'0'}, {'2'}, {'0'}, {'3'}, {'0'}	},
	{	{'0'}, {'0'}, {'0'}, {'0'}, {'0'}, {'0'}, {'0'}	},
	{	{'0'}, {'4'}, {'0'}, {'5'}, {'0'}, {'6'}, {'0'}	},
	{	{'0'}, {'0'}, {'0'}, {'0'}, {'0'}, {'0'}, {'0'}	},
	{	{'0'}, {'7'}, {'0'}, {'8'}, {'0'}, {'9'}, {'0'}	},
	{	{'0'}, {'0'}, {'0'}, {'0'}, {'0'}, {'0'}, {'0'}	}

};

void Draw()
{
	using namespace std;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == '0')
			{
				cout << '*';
			}
			//thanks to hostilenode for providing a simple fix for the X and Y output

			else if (board[i][j] == 'X')
			{
				cout << 'X';
				
			}

			else if (board[i][j] == 'O')
			{
				cout << 'O';
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


	jump:
		cout << "Choose one of the following :" << endl;
		cout << "1. Place" << endl;
		cout << "2. Surrender" << endl;

	cin >> g_UserChoiceResponse;

	switch (g_UserChoiceResponse)
	{
	case 1:
		makeAMove();
		//Draw();
		break;

	case 2:
		Player::surrender();
		break;

	default:
		cout << "Error, unknown command." << endl;
		goto jump;
		break;

	}
}

void Player::makeAMove()
{


	int res;

	using namespace std;

	//yes i know this is a bad practice but for now i am using this as a temporary solution to reprompt the user.
	jump:
		cout << "Where do you want to place it? (choose either : 1, 2, 3, 4, 5, 6, 7, 8, 9)" << endl;


	cin >> res;

	//WARNING : incoming trillions of ifs and goto statements

	if (g_player1Turn)
	{
		switch (res)
		{
		case 1:
			if (board[1][1] != 'X' && board[1][1] != 'O')
			{
				board[1][1] = 'X';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}
			break;

		case 2:
			if (board[1][3] != 'X' && board[1][3] != 'O')
			{
				board[1][3] = 'X';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}
			
			break;

		case 3:
			if (board[1][5] != 'X' && board[1][5] != 'O')
			{
				board[1][5] = 'X';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}
			
			break;

		case 4:
			if (board[3][1] != 'X' && board[3][1] != 'O')
			{
				board[3][1] = 'X';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}

			break;

		case 5:
			if (board[3][3] != 'X' && board[3][3] != 'O')
			{
				board[3][3] = 'X';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}
			
			break;
		case 6:
			if (board[3][5] != 'X' && board[3][5] != 'O')
			{
				board[3][5] = 'X';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}
			break;

		case 7:
			if (board[5][1] != 'X' && board[5][1] != 'O')
			{
				board[5][1] = 'X';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}
			
			break;

		case 8:
			if (board[5][3] != 'X' && board[5][3] != 'O')
			{
				board[5][3] = 'X';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}
			
			break;

		case 9:
			if (board[5][5] != 'X' && board[5][5] != 'O')
			{
				board[5][5] = 'X';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}
			
			break;

		default:
			cout << "Error, unknown command." << endl;
			goto jump;
			break;
		}
	}

	if (g_player2Turn)
	{
		switch (res)
		{
		case 1:
			if (board[1][1] != 'X' && board[1][1] != 'O')
			{
				board[1][1] = 'O';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}
			break;

		case 2:
			if (board[1][3] != 'X' && board[1][3] != 'O')
			{
				board[1][3] = 'O';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}

			break;

		case 3:
			if (board[1][5] != 'X' && board[1][5] != 'O')
			{
				board[1][5] = 'O';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}

			break;

		case 4:
			if (board[3][1] != 'X' && board[3][1] != 'O')
			{
				board[3][1] = 'O';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}

			break;

		case 5:
			if (board[3][3] != 'X' && board[3][3] != 'O')
			{
				board[3][3] = 'O';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}

			break;
		case 6:
			if (board[3][5] != 'X' && board[3][5] != 'O')
			{
				board[3][5] = 'O';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}
			break;

		case 7:
			if (board[5][1] != 'X' && board[5][1] != 'O')
			{
				board[5][1] = 'O';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}

			break;

		case 8:
			if (board[5][3] != 'X' && board[5][3] != 'O')
			{
				board[5][3] = 'O';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;

			}

			break;

		case 9:
			if (board[5][5] != 'X' && board[5][5] != 'O')
			{
				board[5][5] = 'O';
				moves--;
			}
			else
			{
				cout << "Already full ! " << std::endl;
				goto jump;
			}

			break;

		default:
			cout << "Error, unknown command." << endl;
			goto jump;
			break;
		}
	}


	//thanks to a akhnos for telling me that i need to clear the screen and redraw the board.
	system("cls");
	Draw();
	

	
	if (checkWinCondition())
	{
		exit(3);
	}

	if (Tie())
	{
		cout << "It's a tie!." << endl;
		exit(3);
	}
	
}

bool Player::checkWinCondition()
{
	using namespace std;

	if (g_player1Turn)
	{
		if (board[1][1] == 'X' && board[1][3] == 'X' && board[1][5] == 'X' || 
			board[3][1] == 'X' && board[3][3] == 'X' && board[3][5] == 'X' ||
			board[5][1] == 'X' && board[5][3] == 'X' && board[5][5] == 'X' ||
			board[1][1] == 'X' && board[3][1] == 'X' && board[5][1] == 'X' ||
			board[1][3] == 'X' && board[3][3] == 'X' && board[5][3] == 'X' || 
			board[1][5] == 'X' && board[3][5] == 'X' && board[5][5] == 'X' ||
			board[1][1] == 'X' && board[3][3] == 'X' && board[5][5] == 'X' ||
			board[1][5] == 'X' && board[3][3] == 'X' && board[5][1] == 'X'  )
		{
			cout << "Player 1 wins!." << endl;
			system("pause");
			return true;
		}

		else
		{
			return false;
		}
	}

	if (g_player2Turn)
	{
		if (board[1][1] == 'O' && board[1][3] == 'O' && board[1][5] == 'O' ||
			board[3][1] == 'O' && board[3][3] == 'O' && board[3][5] == 'O' ||
			board[5][1] == 'O' && board[5][3] == 'O' && board[5][5] == 'O' ||
			board[1][1] == 'O' && board[3][1] == 'O' && board[5][1] == 'O' ||
			board[1][3] == 'O' && board[3][3] == 'O' && board[5][3] == 'O' ||
			board[1][5] == 'O' && board[3][5] == 'O' && board[5][5] == 'O' ||
			board[1][1] == 'O' && board[3][3] == 'O' && board[5][5] == 'O' ||
			board[1][5] == 'O' && board[3][3] == 'O' && board[5][1] == 'O')
		{
			cout << "Player 2 wins!." << endl;
			system("pause");
			return true;
		}

		else
		{
			return false;
		}
	}

	
	
	
}

bool Tie()
{
	if (moves == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}