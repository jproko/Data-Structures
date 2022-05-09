#include "RecursiveImplementations.h"

int* arr;

void implementationMain() 
{
	printf("Function responsible for displaying purposes of Implementation header file.\n");
	printf("Sum of first 12 values is:%d\n", sumOfFirstN(12));
	printf("-----------------\n");
	printf("Factorial of number 12 is:%d\n", factorial(12));
	printf("-----------------\n");
	printf("Base number 2 in the 15th power (2^15) equals:%d\n",pow(2,15));
	printf("-----------------\n");
	printf("Using fast pow recursion: base number 2 in the 15th power (2^15) equals:%d\n", fastPow(2, 15));
	printf("-----------------\n");
	printf("Tailor Series for e^x:e^1 (precission n=10) : %lf\n", e(1,10));
	printf("-----------------\n");
	printf("Tailor Series for e^x:e^1 (precission n=50) : %lf\n", e(1, 50));
	printf("-----------------\n");
	printf("(Horner's Rule) Tailor Series for e^x:e^1 (precission n=10) : %lf\n", fastE(1, 10));
	printf("-----------------\n");
	printf("Initiating dynamic approach for fibonacci series.\n");
	printf("Initializing array of n+1 (15+1) spaces for calculation of fib(15)\n");
	int* arr = (int*)malloc(16 * sizeof(int));
	for (int i = 0; i < 16; i++) 
	{
		arr[i] = -1;
	}
	printf("The result trace of the algorithm is:\n");
	dynamicFibonacci(15,arr);
	printf("Pascal's triangle combinations algorithm for 5_C_3:%d\n", combinations(5,3));
	printf("-----------------\n");
	printf("Tower of Hanoi example for 4 discs:\n");
	towerOfHanoi(4, 'A', 'B', 'C');

}

int sumOfFirstN(int n) 
{
	if (n == 0) 
		return 0;
	return sumOfFirstN(n - 1) + n;
}

int factorial(int n) 
{
	if (n == 0)
		return 1;
	return factorial(n - 1) * n;
}

int pow(int m, int n) 
{
	if (n == 0)
		return 1;
	return pow(m, n - 1) * m;
}

int fastPow(int m, int n) 
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return fastPow(m * m, n / 2);
	return m * fastPow(m * m, (n - 1) / 2);
}

double e(int x, int n) 
{
	static double x_into_n;
	static double n_factorial;
	if (n == 0) 
	{
		x_into_n = 1;
		n_factorial = 1;
		return x_into_n / n_factorial;
	}
	double sum_term_n_minus_1 = e(x, n - 1);
	x_into_n *= x;
	n_factorial *= n;
	return sum_term_n_minus_1 + (x_into_n/ n_factorial);
}

double fastE(int x, int n) 
{
	static int denominator = 1;
	if (n == 1) 
	{
		denominator++;
		return 1 + double(x / denominator);
	}
	double partA = double(x) / double(denominator);
	denominator++;
	return 1 + (partA *fastE(x,n-1));
}

int dynamicFibonacci(int n, int* A) 
{
	if (n == 0) 
	{
		A[n] = 0;
		printf("\tn: %d => Fib[n] = %d\n",n,A[n]);
		printf("\t-------------\n");
		return A[n];
	}
	if (n == 1) 
	{
		A[n] = 1;
		printf("\tn: %d => Fib[n] = %d\n", n, A[n]);
		printf("\t-------------\n");
		return A[n];
	}
	if (A[n] == -1) 
	{
		printf("\tRecursion\n");
		A[n] = dynamicFibonacci(n - 2, A) + dynamicFibonacci(n - 1, A);
		printf("\tFib[%d] = %d\n", n, A[n]);
		printf("\t-------------\n");
		return A[n];
	}
	printf("\tNo - Recursion needed\n");
	printf("\tFib[%d] = %d\n", n, A[n]);
	printf("\t-------------\n");
	return A[n];
}

int combinations(int n, int k) 
{
	if (n == 0) 
	{
		return 1;
	}
	if (k == 0) 
	{
		return 1;
	}
	if (n == k) 
	{
		return 1;
	}

	return combinations(n-1,k-1)+ combinations(n - 1, k);
}

void towerOfHanoi(int n_of_discs, char source, char intermidiate, char destination) 
{
	if (n_of_discs>0)
	{
		towerOfHanoi(n_of_discs - 1, source, destination, intermidiate);
		printf("\tMove from:%c to %c\n", source, destination);
		printf("\t-----------------\n");
		towerOfHanoi(n_of_discs - 1, intermidiate, source, destination);
	}
}