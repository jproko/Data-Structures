#include "Histogram.h"
#include "LinkedList.h"
#include <ctype.h>
#include <iostream>
#include <string>
// * This header introduces random number generation facilities.
// * https://www.cplusplus.com/reference/random/
#include <random>


/*
* This function is responsible for reading input from the user, which 
* input represents the n integer number >=1.
*/
std::string readInput()
{
	int max_capacity = 1;
	std::string input;

	printf("Please insert an integer (>=1 and <=20) for list initialization:\n");
	std::cin >> input;
	std::cout << "Given input: " << input << std::endl;
	return input;
}

/*
* This function is responsible for verifying that the given user input is 
* exclusively consisted of digits, so that it can be succesfully parsed into
* an integer number.
*/
bool stringVerification(std::string input) 
{
	bool isDigit = true;
	for (int i = 0; i < input.size(); i++) 
	{
		if (!isdigit(input[i])) 
		{
			isDigit = false;
			return isDigit;
		}
	}
	return isDigit;
}

/*
* This function is responsible for generating an integer number n, which
* describes the maximum list capacity for H and L, where n>=1.
*/
int accepatbleListCapacity() 
{
	bool isInitializationSuccesfull = false;
	while (!isInitializationSuccesfull)
	{
		bool isInputAcceptable = false;
		std::string input = readInput();
		isInputAcceptable = stringVerification(input);
		while (!isInputAcceptable)
		{
			printf("Wrong Input. You are kindly requested to try again.\n");
			input = readInput();
			isInputAcceptable = stringVerification(input);
		}
		printf("Correct input\n");

		int maxCapacity = stoi(input);
		if ((maxCapacity >= 1) && (maxCapacity <= 20))
		{
			isInitializationSuccesfull = true;
			return maxCapacity;
		}
		else 
		{
			printf("Max Capacity:%d out of bounds [1,20].\n",maxCapacity);
		}
	}
}

int generateRandomInteger(int minBound, int maxBound) 
{
	// A random number generator that produces non-deterministic random numbers, if supported.
	// Unlike the other standard generators, this is not meant to be an engine that generates pseudo - random numbers, 
	// but a generator based on stochastic processes to generate a sequence of uniformly distributed random numbers.
	// https://www.cplusplus.com/reference/random/random_device/
	std::random_device randomDevice;

	// This is a random number engine class that generates pseudo-random numbers.
	// It is the library implemention's selection of a generator that provides at least acceptable 
	// engine behavior for relatively casual, inexpert, and/or lightweight use.
	// https://www.cplusplus.com/reference/random/default_random_engine/
	std::default_random_engine randomEngine(randomDevice());

	// Random number distribution that produces integer values according to a uniform discrete distribution.
	// This distribution produces random integers in a range [a,b] where each possible value has an equal likelihood of being produced. 
	// This is the distribution function that appears on many trivial random processes (like the result of rolling a die).
	std::uniform_int_distribution<int> rectangularDistribution(minBound, maxBound);

	return rectangularDistribution(randomEngine);
}

int main()
{
	// Extract maximum capacity of the list
	int maxCapacity = accepatbleListCapacity();

	// Initialize H and L with maximum capacity >=1
	L_List* L = new L_List(maxCapacity);
	H_List* H = new H_List(maxCapacity);

	for (int i = 0; i < maxCapacity; i++) 
	{
		int x = generateRandomInteger(0, 10);
		printf("Generated Number:%d\n",x);
		L->Insert(x);
		H->InsertAscend(x);
	}
	L->ListIdentity();
	H->ListIdentity();
}



