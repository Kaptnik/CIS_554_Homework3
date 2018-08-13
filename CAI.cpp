/*************************************************************************************************************
*															 		 					   				     *
* CAI.cpp - CAI stands for Computer-Assisted Instructions. Presents simple multiplication/division questions *
*         collates responses, and provides some rudimentary feedback									     *
*																						   				     *
* Author: Karthik Umashankar; Class: CIS 554 Object Oriented Programming; Term: Summer '18 				     *
*																						   				     *
*************************************************************************************************************/

#include "CAI.h"

#include <chrono>
#include <cstdlib>

// In the constructor, just set default values
// for performance counters
CAI::CAI()
{
	wrongTries_ = 0;
	correctOnFirstTry_ = 0;
}

// Add one more strike.
// Doesn't really mean anything, as the user gets 
// unlimited strikes anyway.
void CAI::IncrementWrongTries()
{
	++wrongTries_;
}

// Add a bingo!
// The more the user gets these, the more they 
// deserver pats on their backs
void CAI::IncrementCorrectOnFirstTry()
{
	++correctOnFirstTry_;
}

// Return the strike count
int CAI::GetWrongTries()
{
	return wrongTries_;
}

// Return the bingo! count
int CAI::GetNumberCorrectOnFirstTry()
{
	return correctOnFirstTry_;
}

// This is where the meat of the work happens.
// An equation is generated using two operands
// that are totally random.

Equation CAI::GenerateEquation(EquationType type)
{
	// We generate two single digit random numbers.
	int operand1 = GenerateRandomInteger(1, 9);
	int operand2 = GenerateRandomInteger(1, 9);

	// If the type is division, we don't want questions
	// where we ask the user to divide 6 by 7.
	// Instead, we multiple operand1 by operand2, 
	// so it always divides cleanly.

	// We have a slack channel going on with other students
	// This was discussed there. 
	// And this is totally Alexander Pharo's idea.
	// Credit where it's due! :)

	if (type == EquationType::DIVISION)
		operand1 = operand1 * operand2;

	// Initialize a new Equation object, and pass it back
	return Equation(operand1, operand2, type);
}

// Fetch a new response to a correct answer
const char* CAI::GetNextCorrectResponse()
{
	/* This next line should've been the function body. But since we're required to use switch...
	return CORRECT_RESPONSES[GenerateRandomInteger(0,3)];
	*/

	// Generate a random number between 1 & 4
	int responseNumber = GenerateRandomInteger(1, 4);

	// Use a switch, and based on the value, return
	// a different response.
	switch (responseNumber)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		return CORRECT_RESPONSES[responseNumber - 1];
	default:
		// The code really shouldn't ever reach here, but if it does, we'll send it further down the rabbit hole
		return nullptr;
	}
}

// The same as the previous function, but for incorrect responses.
// I'm not proud of this copy paste. But then again, in an ideal world,
// this would've been a one line function!
const char * CAI::GetNextIncorrectResponse()
{
	/* This next line should've been the function body. But since we're required to use switch...
	return INCORRECT_RESPONSES[GenerateRandomInteger(0,3)];
	*/
	int responseNumber = GenerateRandomInteger(1, 4);
	switch (responseNumber)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		return INCORRECT_RESPONSES[responseNumber - 1];
	default:
		// The code really shouldn't ever reach here, but if it does, we'll send it further down the rabbit hole
		return nullptr;
	}
}

// Function that generates a random number 
// and ensures it lies in between min & max (inclusive)
int CAI::GenerateRandomInteger(int min, int max)
{
	// Generate a seed based on the number of microseconds since epoch time.
	unsigned long seed = (unsigned long) std::chrono::duration_cast<std::chrono::microseconds>(
			std::chrono::system_clock::now().time_since_epoch()
		).count();
	// Feed the seed into srand.
	srand(seed);
	// Now generate a random number,
	// Get the remainder when you divide it by 
	// the range length, and add min to it.
	// This is standard rng practice.
	return rand() % (max - min + 1) + min;
}