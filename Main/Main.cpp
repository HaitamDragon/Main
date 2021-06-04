#include "TTTT.h"

//#include <iostream>


int main()
{
    
    Draw();
    
    Player pl1;

    pl1.askUserTurn();

    while (true)
    {
        /*
        if (pl1.checkWinCondition())
        {
            break;
        }
        */


        pl1.playerTurn();



    }

    


}

