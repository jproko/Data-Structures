#include "Recursion.h"


void TailFunction(int n) 
{
	// base terminating condition
	if (n > 0) 
	{
		// call - time operation
		printf("Recursive call:%d\n", n);
		// recursive call
		TailFunction(n-1);
	}
}

void HeadFunction(int n) 
{
	// base terminating condition
	if (n > 0)
	{
		// recursive call
		HeadFunction(n - 1);
		// return - time operation
		printf("Recursive call:%d\n", n);

	}
}

void MemoryEfficientFunction(int n)
{
	// Static variables have the property of preserving their value 
	// even after they are out of scope. Static variables preserve their 
	// previous value in their previous scope and are not initialized again 
	// in the new scope.
	// https://www.geeksforgeeks.org/static-variables-in-c/
	static int x = 0;

	if (n > 0) 
	{
		// tree - alike structure

		// call - time operation
		x += 5;
		// recursive call
		MemoryEfficientFunction(n - 1);
		// return - time operations
		printf("Recursive call:%d\n", x);
		x -= 5;
	}
}

int depth = 0;
int value = 0;

void BinaryTreeBFSFunction()
{
	// Current Level: n
	// Base breaking condition: Is n>0?
	if (depth > 0) 
	{
		// Yes : n > 0 is true
		// Direction Left Child:
		// Down traversal < from level n towards level n-1
		depth --;
		BinaryTreeBFSFunction();
		// Direction Right Child:
		// Down traversal > from level n towards level n-1
		depth --;
		BinaryTreeBFSFunction();
		// Direction Parent
		// Up traversal ^ from level n towards level n+1
		depth ++;
	}
	else 
	{
		// Base case enabled: n = 0
		// No : n > 0 is false
		// Incremeant global value +1
		value++;
		printf("Leaf Node: %d\n", value);
		// Direction Parent
		// Up traversal ^ from 0 towards level 1
		depth++;
	}
	
}

void displayRecursion() 
{
	printf("Display of simple tail recursion\n");
	TailFunction(5);
	printf("-----------------\n");
	printf("Display of simple head recursion\n");
	HeadFunction(5);
	printf("-----------------\n");
	printf("Display of memory eficient (tree - alike) recursion\n");
	MemoryEfficientFunction(5);
	printf("-----------------\n");
	printf("Display 2^n values performing B.F.S.\n");
	depth = 4;
	BinaryTreeBFSFunction();
	printf("-----------------\n");

}