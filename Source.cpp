/***********************************************************************************************************
*																	 					   				   *
* Source.cpp - This is where the meat of the work happens. The entry point. Uses both Equation & CAI to	   *
*	           provide users with simple elementary math questions						   				   *
*																						   				   *
* Author: Karthik Umashankar; Class: CIS 554 Object Oriented Programming; Term: Summer '18 				   *
*																						   				   *
***********************************************************************************************************/

#include "CAI.h"
#include <iostream>
#include <string>

void AskQuestions(CAI* cai, EquationType type, int numberOfQuestions);

int main()
{
	// Just some general banter before we get on to the math stuff
	std::string name;

	std::cout << "Well, hello there! What's your name?" << std::endl;
	std::cin >> name;

	std::cout << "\nHi " << name << "! I'm the Limpid Luv Deity, a math bot here to guide you through some elementary mathematics!\nAre you ready?" << std::endl;
	std::cout << "[Y]es or [N]o (Type Y or N followed by the enter key) ";

	// I want the user to hit Y or N. Initialize it to something that's not either so 
	// we don't have to use the much dreaded break/continue
	char beginSession = 'A';

	while (beginSession != 'y' && beginSession != 'n')
	{
		std::cin.get(beginSession);
		beginSession = tolower(beginSession);
	}
	// We're out of the while loop, and the user chose "Nooooooooo"
	if (beginSession == 'n')
	{
		std::cout << "\nAlright. No worries! I hope my name didn't scare you. It's just an anagram for 'Multiply Divide'. I'll see you later!" << std::endl;
		exit(0);
	}

	// If we made it this far, it's only because the user chose to go on.
	// Plaster them with more text before the start (just like any Star Wars movie)
	std::cout << "\nGreat! Here's what we're going to do. I'll present you 5 simple multiplication problems" << std::endl;
	std::cout << "I'll then proceed to give you 5 simple division problems.\nYou do your best to answer them correctly, in the least number of tries, ok champ?" << std::endl;
	std::cout << "\nLet's start with the multiplication" << std::endl;

	// Set up a new CAI object
	CAI cai;

	// Pass it on to the AskQuestions function, suggesting it ask multiplication questions, 5 of them to be precise.
	AskQuestions(&cai, EquationType::MULTIPLICATION, 5);

	std::cout << "\nGood job there " << name << "! You're a trooper! Now let's move on to some division shall we?" << std::endl;
	
	// Do the same, but with division
	AskQuestions(&cai, EquationType::DIVISION, 5);

	// More banter, but this time thrown in with some trivia
	std::cout << "\nGreat job there champ! You did exceedingly well." << std::endl;
	std::cout << "Here are some raw stats about how well you did.\nNow remember, there is no good or bad, just how much better you've gotten since last time, ok?" << std::endl;
	std::cout << "\nNumber of answers correct on first try: " << cai.GetNumberCorrectOnFirstTry() << std::endl;
	std::cout << "Average number of wrong answers before you got the right one: " << cai.GetWrongTries() / 10 << std::endl;
	std::cout << "(If you're seeing a 0 for the average number of wrong answers,\npat yourself on the back, as you had less than 10 wrong answers overall!)" << std::endl;

	// And we're done!
	return 0;
}

// Asks questions of a specified type, and a specific number of them
// Will not move on to new question if old one is unanswered or answered incorrectly
void AskQuestions(CAI* cai, EquationType type, int numberOfQuestions)
{
	for (int i = 0; i < numberOfQuestions; ++i)
	{
		// Generate an equation
		Equation equation = cai->GenerateEquation(type);
		// Print it out, which basically translates to post it as a question
		std::cout << equation.ToString() << std::endl;
		// Start with an invalid result
		int result = -1;
		
		bool firstTry = true;

		// And while the result isn't correct
		// You will notice professor, that I've taken your
		// break/continue advise to heart. :)
		while (!equation.DoesResultMatch(result))
		{
			// Keep bugging the user for the right answer
			std::cin >> result;

			// If the user is a smart-ass as opposed to just being smart, put him/her in his/her place.
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(999, '\n');
				std::cout << "Come on now, let's stick to numbers shall we? This is, after all, a math quiz of sorts" << std::endl;
			}
			else
			{
				// The user entered valid input
				// But is it correct?
				if (equation.DoesResultMatch(result))
				{
					// It is! Praise them
					std::cout << cai->GetNextCorrectResponse() << std::endl;
					// If it's on the first try, add a merit badge.
					if (firstTry)
						cai->IncrementCorrectOnFirstTry();
				}
				else
				{
					// It's the wrong answer. Taunt them!
					// Just kidding, keep appreciating them and pushing them
					// to give the right answer.
					std::cout << cai->GetNextIncorrectResponse() << std::endl;

					// But keep tabs on how much they messed up
					cai->IncrementWrongTries();
				}
				firstTry = false;
			}
		}
	}
}
