#include <iostream>
#include <Windows.h>
#include "TicTacToe.h"
using std::cin, std::cout, std::endl, std::string;

void getNames(string* name, string* opponent, int option)
{
    cout << "What do you want your name to be?\n";
    cin >> *name;

    *opponent = option == 1 ? "Bot" : "Player 2";
}

void winningMessage(string name, string opponent)
{
    string winner = TicTacToe::currentTurn == 1 ? name : opponent;
    cout << "\nGame over!!! \n" << winner << " has won the game!";
    TicTacToe::board->clear();
}

int main()
{
	
	int option;
    string opponent, name;
	do
	{
        system("cls");
		option = TicTacToe::menu();
		if (option == 3)
		{
			cout << "\nThanks for playing!!!\n";
			return 0;
		}

        getNames(&name, &opponent, option);
		TicTacToe::board->printBoard(name, opponent);
		while (option == 1)
		{
            if (TicTacToe::currentTurn == 1)
            {
                TicTacToe::promptPlayer();
            }
            else
            {
                TicTacToe::botTurn();
                Sleep(1300);
            }

            TicTacToe::board->printBoard(name, opponent);

            if (TicTacToe::hasWon())
            {
                winningMessage(name, opponent);
                break;
            }

			TicTacToe::changePlayerTurn();
		}

        while (option == 2)
        {
            TicTacToe::promptPlayer();
            TicTacToe::board->printBoard(name, opponent);
            
            if (TicTacToe::hasWon())
            {
                winningMessage(name, opponent);
                break;
            }

            TicTacToe::changePlayerTurn();
        }

        Sleep(2500);
	} while (option != 3);
}