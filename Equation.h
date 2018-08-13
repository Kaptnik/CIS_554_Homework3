/***********************************************************************************************************
*																	 					   				   *
* Equation.h - Defines the equation class. Holds two operands, an operator and the resultof applying the   *
*         operator to the two operands																	   *
*																						   				   *
* Author: Karthik Umashankar; Class: CIS 554 Object Oriented Programming; Term: Summer '18 				   *
*																						   				   *
***********************************************************************************************************/

#pragma once

#ifndef EQUATION_H
#define EQUATION_H

#include <string>

enum EquationType
{
	MULTIPLICATION,
	DIVISION
};

class Equation
{
public:
	Equation(int operand1, int operand2, EquationType type);
	bool DoesResultMatch(int result);
	std::string ToString();	
private:
	int operand1_, operand2_, result_;
	EquationType type_;
};

#endif