#pragma once
#include <iostream>

//TTTT = Tic Tac Toe Table.


void Draw();
void Tie();

class Player
{

public:
	void askUserTurn();
	void makeAMove();
	void surrender();
	void playerTurn();
	void Choices();
	void checkWinCondition();

};
