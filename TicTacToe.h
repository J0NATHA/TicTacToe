#ifndef TICTACTOE_H
#define TICTACTOE_H

#include<stdlib.h>
using std::cin, std::cout, std::string;

namespace TicTacToe
{
    class Board
    {
        private:
        char elements[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

        public:
        Board() 
        {
            srand(static_cast<long int>(time(NULL)));
        }

        void clear()
        {
            char temp[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
            for (int i = 0; i < 9; i++)
            {
                elements[i] = temp[i];
            }
        }

        void printBoard(string name, string opponent)
        {
            system("cls");
            cout << "\tTic Tac Toe\n"
                << "  "<< name << "(X) vs "<< opponent << "(O)\n\n";
            for (int i = 0; i < 9; i += 3)
            {
                cout << "\t     |     |     \n"
                    << "\t  " << elements[i] << "  |  " << elements[i + 1] << "  |  " << elements[i + 2];
                if (i != 6) cout << "\n\t_____|_____|_____\n";
                else cout << "\n\t     |     |     \n\n";
            }
        }

        void replace(int position, const char* value)
        {
            elements[position] = value[0];
        }

        void replace(int position, char value)
        {
            elements[position] = value;
        }

        bool checkAvailable(int position)
        {
            return elements[position] != 'X' && elements[position] != 'O';
        }

        bool hasWon()
        {
            if ((elements[0] == elements[4] && elements[4] == elements[8]) ||
                (elements[2] == elements[4] && elements[4] == elements[6]))
            {
                return true;
            }

            for (int i = 0; i < 9; i ++)
            {
                if(i % 3 == 0)
                {
                    if (elements[i] == elements[i + 1] && elements[i] == elements[i + 2])
                    {
                        return true;
                    }
                }
                if (i < 3)
                {
                    if (elements[i] == elements[i + 3] && elements[i] == elements[i + 6])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    };

    Board* createBoard()
    {
        Board* board = NULL;
        board = new Board;
        return board;
    }
    
    Board* board = createBoard();
    int currentTurn = rand() % 2 + 1;

    int menu()
    {
        int option;
        do
        {
            cout << "\t===== Welcome to Tic Tac Toe! Choose an option =====\n"
                << "\t\t\t [ 1 ] Singleplayer\n"
                << "\t\t\t [ 2 ] Multiplayer\n"
                << "\t\t\t [ 3 ] Exit\n"
                << "\t\t -> ";
            cin >> option;
            system("cls");
        } while (option < 1 || option > 3);
        return option;
    }

    void promptPlayer()
    {
        int number;
        bool available;
        string playerSymbol;

        do
        {
            playerSymbol = currentTurn == 1 ? "X" : "O";
            cout << "Where do you want to place your " << playerSymbol << "?\n"
                << "-> ";
            cin >> number;
            available = board->checkAvailable(number - 1);
            
        } while (number < 1 || number > 9 || !available);

        board->replace(number - 1, playerSymbol.c_str());
    }

    void botTurn()
    {
        int number;
        do
        {
            number = rand() % 9;
        } while (!board->checkAvailable(number));

        board->replace(number, 'O');
        cout << "Bot played O in " << number + 1 << "\n";
    }

    void changePlayerTurn()
    {
        currentTurn = currentTurn == 1 ? 2 : 1;
    }

    bool hasWon()
    {
        if (board->hasWon()) return true;
        return false;
    }
}

#endif