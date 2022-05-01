/********************************************
* Author: Julian Proko                      *
* Purpose: Data Structures Labs             *
* Description: Recursion (Simple Recursion) *
* Date Created: 28/04/2022                  *
* Last Modified: 28/04/2022                 *
*********************************************/

//Library declaration
#include <stdio.h>

#ifndef RECURSION_H
#define RECURSION_H

/*
* Simple (tail) recursive function which displays numbers n through 1 in 
* descending order: e.x. 5, 4, 3, 2, 1
* As it stands, this simple recursion takes advantage of stack by creating
* n consecutive stack memory frames : O(n) - space complexity 
*/
void TailFunction(int n);

/*
* Simple (head) recursive function which displays numbers 1 through n in 
* ascending order: e.x. 1, 2, 3, 4, 5
* As it stands, this simple recursion takes advantage of stack by creating
* n consecutive stack memory frames : O(n) - space complexity
*/
void HeadFunction(int n);

/*
* Simple tree - alike recursive function which prints numbers 5 through 5*n
* in descending order: e.x. 25, 20, 15, 10, 5 (n = 5)
* The underlying implemented recursion takes advantage of static declared variable 
* performing an: O(1) - space complexity
*/
void MemoryEfficientFunction(int n);


/*
* This function is responsible for performing a B.F.S. traversal of 
* a binary tree (using tree reccursion) and displaying all the 2^n
* values from 1 - 2^n : e.x. 1, 2, 4, 8, 16, 32 (n = 5)
* Time Complexity: O(2^n)
* Space Complexity: O(1)
*/
void BinaryTreeBFSFunction();

/*
* This function is responsible for invoking the necessary function 
* to display a specific type of recursion.
*/
void displayRecursion();
#endif