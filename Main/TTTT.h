#pragma once
#include <iostream>

//TTTT = Tic Tac Toe Table.


void Draw();
bool Tie();

class Player
{

public:
	void askUserTurn();
	void makeAMove();
	void surrender();
	void playerTurn();
	void Choices();
	bool checkWinCondition();

};
