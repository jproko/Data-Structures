/********************************************
* Author: Julian Proko                      *
* Purpose: Data Structures Labs             *
* Description: Recursion (Simple Recursion) *
* Date Created: 08/05/2022                  *
* Last Modified: 08/05/2022                 *
*********************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef RECURSIVE_IMPLEMENTATIONS_H
#define RECURSIVE_IMPLEMENTATIONS_H

/*
* This function, serves as pseudo - main function, for displaying the
* functionality of the implemented functions.
*/
void implementationMain();

/*
* This function is responsible for generating and finding the sum 
* of the first n numbers recursively.
*/
int sumOfFirstN(int n);

/*
* This recursive function finds the factorial of a given number N
*/
int factorial(int n);

/*
* This recursive function returns the result of m^n 
*/
int pow(int m, int n);

/*
* This recursive function returns the result of m^n, performing
* 1/2 of the computations needed from the base-recursive implementation,
* by performing 2 multiplications instead of one every even number of tree level.
*/
int fastPow(int m, int n);

/*
* This function makes use of the Taylor Series formula,
* to calculate e^x up to n-th sum term.
*/
double e(int x, int n);

/*
* This function utilizes Horner's rule in Taylor Series formula,
* to calculate e^x up to n-th sum term in O(n^2) - time complexity.
*/ 
double fastE(int x, int n);

/*
* This function is responsible for calculating Fibonacci series, in a recursive
* manner, using dynamic - programming concepts (more precisely saving sub-problems 
* to a static array so it does not have to perform same calculations.
* The reduction that occurs is from O(2^n) to O(n).
*/
int dynamicFibonacci(int n, int* A);

/*
* This function is responsible for calculating the number of (no-repeat) combinations
* of nCk = n!/k!(n-k)! using recursion on Pascal's triangle.
*/
int combinations(int n, int k);

/*
* This recursive function solves the well known Hanoi Tower Problem where someone has
* to transfer n ascending discs from column A to column C, with intermediate tower B. 
*/
void towerOfHanoi(int n_of_discs, char source, char intermidiate,char destination);
#endif