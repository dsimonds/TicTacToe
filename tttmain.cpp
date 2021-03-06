// TicTacToe.cpp : Defines the entry point for the console application.
//

// Derek Simonds
// 6 June 2014
// tttmain.cpp
// driver program to run tic tac toe game

#include "stdafx.h"
#include "ttt.h"
#include <iostream>
#include <string>

//#define frz system("pause");

using namespace std;

int main(int argc, const char * argv[])
{
	char MenuChoice;
	int count = 0, tie;
	Player p1, p2;
	TicTacToe Game(tie, p1, p2);
	// is user playing against computer
	bool IsComp = false;

	// Displays first menu
	// stores user's answer in MenuChoice
	MenuChoice = Game.Menu1();

	// loops game while user chooses to keep playing
	while (MenuChoice != '4')
	{

		// if user chooses to start new two player game
		if (MenuChoice == '1')
		{
			// Player is not playing against computer
			IsComp = false;

			// resets board and player
			Game.SetPlayers(MenuChoice, p1, p2);
			Game.BoardReset();
			Game.ScoreReset(tie, p1, p2);

			// Resets count(Count keeps track of who's turn it is)
			count = 0;

			// loops through game
			do {

				count++;
				Game.CheckforWinner(count, tie, p1, p2);
				Game.ChoosePosition(count, p1, p2);
				Game.DisplayBoard();
			} while (Game.CheckforWinner(count, tie, p1, p2) == false);

			//frz;

			// displays score
			Game.DisplayScore(tie, p1, p2);

			// displays second menu
			MenuChoice = Game.Menu2();
		}


		// If user chooses to play against computer
		else if (MenuChoice == '2')
		{
			// player is playing against computer
			IsComp = true;

			// Resets count(Count keeps track of who's turn it is)
			count = 0;

			// resets board and player
			Game.SetPlayers(MenuChoice, p1, p2);
			Game.BoardReset();
			Game.ScoreReset(tie, p1, p2);

			// loops through game
			do {

				count++;
				Game.CheckforWinner(count, tie, p1, p2);
				Game.Computer(count, p1, p2);
				Game.DisplayBoard();
			} while (Game.CheckforWinner(count, tie, p1, p2) == false);

			//frz;

			// displays score
			Game.DisplayScore(tie, p1, p2);

			// displays second menu
			MenuChoice = Game.Menu2();
		}


		// if user chooses to continue current game
		else if (MenuChoice == '3')
		{
			// resets board
			Game.BoardReset();

			// resets counter
			count = 0;
			// loops through game
			do {
				count++;
				Game.CheckforWinner(count, tie, p1, p2);
				// if user was playing against computer
				if (IsComp == true)
					Game.Computer(count, p1, p2);
				// if user was playing against another player
				else
					Game.ChoosePosition(count, p1, p2);
				Game.DisplayBoard();
			} while (Game.CheckforWinner(count, tie, p1, p2) == false);


			// displays score
			Game.DisplayScore(tie, p1, p2);

			// displays second menu
			MenuChoice = Game.Menu2();

		}

		// if user chooses to exit program
		else if (MenuChoice == '4')
			exit(0);
	}

	return 0;
}
