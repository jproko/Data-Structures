#include "TemplateClass.h"

void TemplateClassFunctionality() 
{
	printf("Performing integer operations:\n");
	Arithmetic<int> operator1(5);
	printf("Addition:%d\n", operator1.Addition(10));
	printf("Subtraction:%d\n", operator1.Addition(-25));
	printf("Multiplication:%d\n", operator1.Multiplication(6));
	printf("Division:%d\n", operator1.Multiplication(1 / 10));
	
	printf("Performing floating point operations:\n");
	Arithmetic<float> operator2(5);
	printf("Addition:%.2f\n", operator2.Addition(10));
	printf("Subtraction:%.2f\n", operator2.Addition(-25));
	printf("Multiplication:%.2f\n", operator2.Multiplication(6));
	printf("Division:%.2f\n", operator2.Multiplication(0.1f));
	}

template <class Model>
Arithmetic<Model> ::Arithmetic(Model par)
{
	a = par;
}

template <class Model>
Model Arithmetic<Model>::Addition(Model x)
{
	return a + x;
}

template <class Model>
Model Arithmetic<Model>::Multiplication(Model x)
{
	return a * x;
}