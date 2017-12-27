
// Derek Simonds ML39
// 6 June 2014
// ttt.cpp
// Implementation file for the TicTacToe class

/*

left off at finding error in the double selection with count-- << maybe...
when player 1 tryes to take players 2 spot, you cant see the board and you can select the another spot with player 2.

*/


/*
Changes as of 13 June 2014
In CheckforWinner():
- Checks for tie game
- Condensed the check for winner algorithm based on insight
from creating the tie game algorithm. it's in one if statement now
- added second menu which I forgot to do in class last night
In Main() (in tttmain):
- changed count to start at 0, and use count++. Because with 9 and
count--, game has player 2 to choose first

Changes as of 14 June 2014
in ChoosePosition(int count, Player p1, Player p2):
- Added a while loop which validates user's position choice,
loops while user keeps choosing a position already taken
In CheckforWinner():
- In last night's upload, I forgot to correct how the program
determines who one. This is now corrected.
In ResetScore();
- It should reset the score, once we add scores to the program

Changes as of 17 June 2014
- Program now keeps and displays player's scores
- Fixed an issue where when you continued game play, it would ask you to hit enter twice
- Added new function "void Computer(int, Player, Player)" in file tttComp.cpp.
- This function has user play against computer. More information in tttComp.cpp.
In Main()
- Added a function call to run computer's choice.
- Rearranged order of function calls in game while loop. Now when there's a winner,
it displays final board before saying "<name> is the winner"
In Menu functions
- Included option to play against computer
- Quick start/Continue game is now option number 3
- Changed function from 'int' to 'char'. This is because when it was int, if someone
entered any letters, it would be stuck in an infinite loop.
- Shortened menus into one while loop
In SetPlayers()
- Only prompts for player two's name if there is a player two
otherwise if playing with computer, player two's name is computer

*/

#include "stdafx.h"
#include "ttt.h"
#include <iostream>
#include <iomanip>
#include <string>

//#define clear system("CLS");
//#define frz system("pause");
//#define wt system("color 0f");
//#define yl system("color 0e");
//#define re system("color 0c");

// colors; OA = green, OB = torq, OC = red, white = 00,

// function displays menu, returns user's choice
char TicTacToe::Menu1()
{
	string choice;

	// show logo
	cout << "*****************************************************************************" << endl;
	cout << "****** ******   ****  ******      ***         ****   ******   ****    *****  " << endl;
	cout << "****** ******  ****** ******     ** **       ******  ******  ******   **     " << endl;
	cout << "  **     **   **        **      **   **     **         **   **    **  ****   " << endl;
	cout << "  **     **   **        **     ** *** **    **         **   **    **  ****   " << endl;
	cout << "  **   ******  ******   **    **       **    ******    **    ******   **     " << endl;
	cout << "  **   ******   ****    **   **         **    ****     **     ****    *****  " << endl;
	cout << "*****************************************************************************" << endl;
	cout << "                                Derek Simonds                                " << endl;

	cout << "Press enter to continue ...";
	cin.get();
	 system("CLS");

	// validates choice
	while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
	{
		//re;
		cout << "Please enter your choice:";
		cout << "\n\t1) Start a new game with two new players.";
		cout << "\n\t2) New game against computer";
		cout << "\n\t3) Quick start game with two players.";
		cout << "\n\t4) Exit\n>> ";
		cin >> choice;

		if (choice != "1" && choice != "2" && choice != "3" && choice != "4")
		{
			 system("CLS");
			cout << "Error: Invalid choice. Please choose either 1, 2. 3, or 4." << endl;
		}
	}
	 system("CLS");
	//wt;
	return choice[0];

}

char TicTacToe::Menu2()
{
	string choice;

	 system("CLS");

	// validates choice
	while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
	{
		//re;
		cout << "Please enter your choice:";
		cout << "\n\t1) Start a new game with two new players.";
		cout << "\n\t2) New game against computer";
		cout << "\n\t3) Continue current game with the same two players.";
		cout << "\n\t4) Exit\n>> ";
		cin >> choice;

		if (choice != "1" && choice != "2" && choice != "3" && choice != "4")
		{
			 system("CLS");
			cout << "Error: Invalid choice. Please choose either 1, 2. 3, or 4." << endl;
		}
	}
	 system("CLS");
	//wt;
	return choice[0];

}

// sets player's name
void TicTacToe::SetPlayers(char MenuChoice, Player &p1, Player &p2)
{
	//wt;

	// prompts for player one's name
	cout << "Player 1, please enter your name: ";
	cin.ignore();
	getline(cin, p1.name);
	cout << endl;
	cout << p1.name << " would you like to be X's, or O's?  ";
	cin >> p1.symbol;

	// validates symbol choice
	while (toupper(p1.symbol) != 'X' && toupper(p1.symbol) != 'O')
	{
		 system("CLS");
		//re;
		cout << "Error: choice must be either and 'X' or an 'O'" << endl;
		cout << " \n" << p1.name << " would you like to be X's, or O's?  ";
		cin >> p1.symbol;
	}

	// saves player 2's symbol as opposite of player 1's
	p1.symbol = toupper(p1.symbol);
	if (p1.symbol == 'X')
		p2.symbol = 'O';

	else
		p2.symbol = 'X';


	 system("CLS");
	//wt;

	// if playing against computer
	if (MenuChoice == '2')
	{
		p2.name = "Computer";
		player2 = p2;
	}

	// if playing against another user
	else
	{
		// prompts for player 2's name
		cout << "Player 2, please enter your name: ";
		cin.ignore();
		getline(cin, p2.name);
		player2 = p2;
	}

	player1 = p1;

	 system("CLS");
}


// resets the board
void TicTacToe::BoardReset()
{
	// resets board
	board[0][0] = '1';
	board[0][1] = '2';
	board[0][2] = '3';
	board[1][0] = '4';
	board[1][1] = '5';
	board[1][2] = '6';
	board[2][0] = '7';
	board[2][1] = '8';
	board[2][2] = '9';
	cout << endl << endl;
	cout << "\t" << "-------------" << endl; // top - placement
	for (int i = 0; i<3; i++)
	{
		cout << "\t";
		for (int j = 0; j<3; j++)
		{
			cout << "| " << board[i][j] << " ";
		}
		cout << "| ";
		cout << endl << "\t" << "-------------" << endl;
	}
}


// displays the board
void TicTacToe::DisplayBoard()
{
	cout << endl << endl;
	cout << "\t" << "-------------" << endl; // top - placement
	for (int i = 0; i<3; i++)
	{
		cout << "\t";
		for (int j = 0; j<3; j++)
		{
			cout << "| " << board[i][j] << " ";
		}
		cout << "| ";
		cout << endl << "\t" << "-------------" << endl;
	}

}


// function allows user to choose their position
void TicTacToe::ChoosePosition(int count, Player p1, Player p2)
{
	char position;
	bool validate = false;

	// Player 1 choice
	if (count % 2 == 1)
	{
		// Loops while player 1 chooses a taken position
		//    validate becomes true when player chooses open position
		while (validate == false)
		{

			cout << "\n" << p1.name << ". Please choose a position: ";
			cin >> position;

			if (position == '1')
			{
				if (board[0][0] == 'X' || board[0][0] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[0][0] = (p1.symbol);
					validate = true;
				}
			}

			else if (position == '2')
			{
				if (board[0][1] == 'X' || board[0][1] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[0][1] = (p1.symbol);
					validate = true;
				}
			}

			else if (position == '3')
			{
				if (board[0][2] == 'X' || board[0][2] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[0][2] = (p1.symbol);
					validate = true;
				}
			}

			else if (position == '4')
			{
				if (board[1][0] == 'X' || board[1][0] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}

				else
				{
					board[1][0] = (p1.symbol);
					validate = true;
				}
			}

			else if (position == '5')
			{
				if (board[1][1] == 'X' || board[1][1] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[1][1] = (p1.symbol);
					validate = true;
				}
			}

			else if (position == '6')
			{
				if (board[1][2] == 'X' || board[1][2] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[1][2] = (p1.symbol);
					validate = true;
				}
			}

			else if (position == '7')
			{
				if (board[2][0] == 'X' || board[2][0] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[2][0] = (p1.symbol);
					validate = true;
				}
			}

			else if (position == '8')
			{
				if (board[2][1] == 'X' || board[2][1] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[2][1] = (p1.symbol);
					validate = true;
				}
			}

			else if (position == '9')
			{
				if (board[2][2] == 'X' || board[2][2] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[2][2] = (p1.symbol);
					validate = true;
				}
			}

			else
				cout << "Error: Invalid choice";

		}   /* Ends validation while loop */
	}       /* Ends player 1's choice */


			// Player 2 choice
	if (count % 2 == 0)
	{
		// Loops while player 2 chooses a taken position
		//    validate becomes true when player chooses open position
		while (validate == false)
		{

			cout << "\n" << p2.name << ". Please choose a position: ";
			cin >> position;


			if (position == '1')
			{
				if (board[0][0] == 'X' || board[0][0] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[0][0] = (p2.symbol);
					validate = true;
				}
			}

			else if (position == '2')
			{
				if (board[0][1] == 'X' || board[0][1] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[0][1] = (p2.symbol);
					validate = true;
				}
			}

			else if (position == '3')
			{
				if (board[0][2] == 'X' || board[0][2] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[0][2] = (p2.symbol);
					validate = true;
				}
			}

			else if (position == '4')
			{
				if (board[1][0] == 'X' || board[1][0] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}

				else
				{
					board[1][0] = (p2.symbol);
					validate = true;
				}
			}

			else if (position == '5')
			{
				if (board[1][1] == 'X' || board[1][1] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[1][1] = (p2.symbol);
					validate = true;
				}
			}

			else if (position == '6')
			{
				if (board[1][2] == 'X' || board[1][2] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[1][2] = (p2.symbol);
					validate = true;
				}
			}

			else if (position == '7')
			{
				if (board[2][0] == 'X' || board[2][0] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[2][0] = (p2.symbol);
					validate = true;
				}
			}

			else if (position == '8')
			{
				if (board[2][1] == 'X' || board[2][1] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[2][1] = (p2.symbol);
					validate = true;
				}
			}

			else if (position == '9')
			{
				if (board[2][2] == 'X' || board[2][2] == 'O')
				{
					cout << "Error: Position Taken" << endl;
				}
				else
				{
					board[2][2] = (p2.symbol);
					validate = true;
				}
			}

			else
				cout << "Error: Invalid choice";

		}   /* Ends validation while loop */
	}       /* Ends player 1's choice */

	 system("CLS");
}


// function checks if there is a winner
bool TicTacToe::CheckforWinner(int count, int &tieGame, Player &p1, Player &p2)
{
	bool winner = false;

	// checks for winner
	if ((board[0][0] == board[0][1] && board[0][0] == board[0][2]) ||   // Top row
		(board[1][0] == board[1][1] && board[1][0] == board[1][2]) ||   // Middle row
		(board[2][0] == board[2][1] && board[2][0] == board[2][2]) ||   // Bottom row
		(board[0][0] == board[1][0] && board[0][0] == board[2][0]) ||   // Left column
		(board[0][1] == board[1][1] && board[0][1] == board[2][1]) ||   // Middle column
		(board[0][2] == board[1][2] && board[0][2] == board[2][2]) ||   // Right column
		(board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||   // Diagonal, top left to bottom right (\)
		(board[2][0] == board[1][1] && board[2][0] == board[0][2]))     // Diagonal, top right to bottom left (/)
	{
		winner = true;
		// if player one wins
		if (count % 2 == 1)
		{
			cout << p1.name << " is the winner! " << endl << endl;
			cout << "Press enter to continue ...";
			cin.ignore().get();
			p1.score++;     // adds score to player one
		}
		// if player two wins
		else
		{
			cout << p2.name << " is the winner! " << endl << endl;
			cout << "Press enter to continue ...";
			cin.ignore().get();
			p2.score++;     // adds score to player two
		}
	}   /*  Ends checking for a winner  */


		// if there is no winner
	else
		winner = false;


	// Checks for cats game (tie game) if there is no winner
	if (winner == false)
	{
		// if each space is filled with an 'X' or 'O', not numbered
		//   and there was no winner from previous if statement
		if ((board[0][0] == 'X' || board[0][0] == 'O') &&
			(board[0][1] == 'X' || board[0][1] == 'O') &&
			(board[0][2] == 'X' || board[0][2] == 'O') &&
			(board[1][0] == 'X' || board[1][0] == 'O') &&
			(board[1][1] == 'X' || board[1][1] == 'O') &&
			(board[1][2] == 'X' || board[1][2] == 'O') &&
			(board[2][0] == 'X' || board[2][0] == 'O') &&
			(board[2][1] == 'X' || board[2][1] == 'O') &&
			(board[2][2] == 'X' || board[2][2] == 'O'))
		{
			winner = true;
			cout << "TIE GAME" << endl;
			tieGame++;
			cout << "Press enter to continue ...";
			cin.ignore().get();
		}  /*  Ends checking for a tie  */

		   // if there is no winner, or tie
		else
			winner = false;

	}
	return winner;
}


// Function displays player's scores
void TicTacToe::DisplayScore(int tieGame, Player p1, Player p2)
{
	cout << endl;
	cout << left << setw(20) << "Name" << right << setw(4) << "Wins" << setw(6) << "Loses" << setw(5) << "Ties";
	cout << "\n-----------------------------\n";
	cout << left << setw(20) << p1.name << right << setw(4) << p1.score << setw(6) << p2.score << setw(5) << tieGame << endl;
	cout << left << setw(20) << p2.name << right << setw(4) << p2.score << setw(6) << p1.score << setw(5) << tieGame << endl;
	cout << endl;

	cout << "Press enter to continue ...";
	cin.get();
}

// resets user's scores
void TicTacToe::ScoreReset(int &tieGame, Player &p1, Player &p2)
{
	tieGame = 0;
	p1.score = 0;
	p2.score = 0;
}


// void TicTacToe::DisplayWinner()


