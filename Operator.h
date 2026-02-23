#pragma once
#include <iostream>
#include <stdlib.h>

class Operation
{
public:
	virtual double Result()
	{
		result = 0;
		return result;
	}
	double result;
	double number_A;
	double number_B;
};

class Add :public Operation
{
	virtual double Result()
	{
		result = number_A + number_B;
		return result;
	}
};

class Subtraction :public Operation
{
	virtual double Result()
	{
		result = number_A - number_B;
		return result;
	}
};

class Multiplication :public Operation
{
	virtual double Result()
	{
		result = number_A * number_B;
		return result;
	}
};

class Division :public Operation
{
	virtual double Result()
	{
		if (number_B == 0)
		{
			std::cout << "number_B can't be 0" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		else
		{
			result = number_A / number_B;
			return result;
		}
	}
};

class Factory
{
public:
	Factory(const int c)
		:_choice(c)
	{ }

	Operation* Choose() 
	{
		switch (_choice)
		{
		case 1: return new Add();
		case 2: return new Subtraction();
		case 3: return new Multiplication();
		case 4: return new Division();
		default:
			std::cerr << "Invalid choice!" << std::endl;
			return nullptr;
		}
	}
private:
	int _choice;
};