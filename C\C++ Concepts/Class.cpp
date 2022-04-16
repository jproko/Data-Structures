#include "class.h"

void ClassFunctionality() 
{
	// Base constructor is invoked
	Rectangular object1;

	printf("Displaying components of object1:\n");
	printf("Surface Area of object1 : %.2f\n",object1.Area());
	printf("Perimeter of object1 : %.2f\n", object1.Perimeter());

	// Overloaded constructor is invoked
	Rectangular object2(10.0f, 5.0f);
}

Rectangular::Rectangular() 
{
	length = 0.0f;
	breadth = 0.0f;
}

Rectangular::Rectangular(float length, float breadth) 
{
	this->length = length;
	this->breadth = breadth;
}