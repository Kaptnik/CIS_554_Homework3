/***********************************************************************************************************
*																	 					   				   *
* CAI.h - CAI stands for Computer-Assisted Instructions. Presents simple multiplication/division questions *
*         collates responses, and provides some rudimentary feedback									   *	
*																						   				   *
* Author: Karthik Umashankar; Class: CIS 554 Object Oriented Programming; Term: Summer '18 				   *
*																						   				   *
***********************************************************************************************************/

#pragma once

#include "Equation.h"

#ifndef CAI_H
#define CAI_H

class CAI
{
public:
	CAI();
	Equation GenerateEquation(EquationType);
	void IncrementWrongTries();
	void IncrementCorrectOnFirstTry();
	int GetWrongTries();
	int GetNumberCorrectOnFirstTry();
	const char * GetNextCorrectResponse();
	const char * GetNextIncorrectResponse();
private:
	int GenerateRandomInteger(int min, int max);
	int wrongTries_;
	int correctOnFirstTry_;

	const char * CORRECT_RESPONSES[4] =
	{
		"Very good!",
		"Excellent!",
		"Nice work!",
		"Keep up the good work!"
	};

	const char * INCORRECT_RESPONSES[4] =
	{
		"No. Please try again.",
		"Wrong. Try once more.",
		"Don't give up!",
		"No. Keep trying."
	};
};

#endif
