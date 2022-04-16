/************************************************************
* Author: Julian Proko										*
* Purpose: Data Structures Labs								*
* Description: Introductory C/C++ concepts (Template Class)	*
* Date Created: 16/04/2022									*
* Last Modified: 16/04/2022									*
*************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef TEMPLATE_CLASS_H
#define TEMPLATE_CLASS_H

// This function is responsible for performing the necessary tasks to display 
// the desired template class functionality. 
void TemplateClassFunctionality();

// Template class that will receive primitive type Model
// Model might be: int, float, e.t.c.
template <class Model>
class Arithmetic 
{
	private:
		Model a;

	public:
		// Exclusive Overloaded Constructor. It takes
		// two Model parameters (that must be of the same type), and 
		// initializes the object.
		Arithmetic(Model par);

		// This function is responsible for performing addition/subtraction operation.
		// Given a <Model> variable x, it performs:
		//		a + x
		//		addition: if x>=0
		//		subtraction: if x<0
		Model Addition(Model x);

		// This function is responsible for performing multiplication/division operation.
		// Given a <Model> variable x, it performs:
		//		a * x
		//		multiplication: if x in Z
		//		division: if x in Q
		Model Multiplication(Model x);
};

#endif TEMPLATE_CLASS_H

