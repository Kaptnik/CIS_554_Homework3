/***********************************************************************************************************
*																	 					   				   *
* Equation.cpp - Defines the equation class. Holds two operands, an operator and the resultof applying the *
*         operator to the two operands																	   *
*																						   				   *
* Author: Karthik Umashankar; Class: CIS 554 Object Oriented Programming; Term: Summer '18 				   *
*																						   				   *
***********************************************************************************************************/

#pragma once

#include "Equation.h"

// Only constructor. Needs two operands and an operator type.
// Copies the operand & type values and...
Equation::Equation(int operand1, int operand2, EquationType type): operand1_(operand1), operand2_(operand2), type_(type)
{
	// Based on the operand type, generates the result
	// Multiplication is straight-forward
	if (type_ == EquationType::MULTIPLICATION)
		result_ = operand1_ * operand2_;
	// But with division, make sure we aren't shooting ourselves in the foot
	else if (type_ == EquationType::DIVISION)
	{
		if (operand2_ != 0)
			result_ = operand1_ / operand2_;
		else
			throw new std::exception("Division by zero huh? Really? What are you, in elementary school?");
	}
	// And we don't really support any other type.
	else
	{
		throw new std::exception("Invalid equation type");
	}
}

// Checks if the result parameter matches the result of the equation
bool Equation::DoesResultMatch(int result)
{
	return result_ == result;
}

// Converts the equation to a question.
std::string Equation::ToString()
{
	if (type_ == EquationType::MULTIPLICATION)
		return "How much is " + std::to_string(operand1_) + " times " + std::to_string(operand2_) + "?";
	else
		return "How much is " + std::to_string(operand1_) + " divided into " + std::to_string(operand2_) + " equal parts?";
}