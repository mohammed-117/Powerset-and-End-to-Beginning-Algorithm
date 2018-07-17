// Assignment#:2
// Power Set Algorithm
// Mohammed Hassnain
// CPSC 335
// Mon,Wed 2:30PM-3:45PM

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>

using namespace std;

void print_sequence(int n, float *seq)
{
	for (int i = 0; i < n; i++)
	{
		cout << seq[i] << " ";
	}

}


void checkSet(int *stack, int k, int *bestSet, int &bestSize, float *A)
{
	int i;

	if (k < 2)
	{
		if (k > bestSize)  // first case index 1
		{
			//we found a better set
			bestSet[k] = stack[k];
			bestSize = k;
			return;
		}
	}
	else
	{
		for (i = 0; i < k - 1; i++)
		{
			// WRITE CODE (AN IF STATEMENT) TO CHECK THAT THE ELEMENTS
			// IN ARRAY A AT INDEXES stack[i+1]-1 AND stack[i+2]-1 ARE IN increasing ORDER
			//IF THE TWO ELEMENTS ARE OUT OF ORDER THEN return


			if (!(A[stack[i + 1] - 1] < A[stack[i + 2] - 1]))
			{
				return;
			}


		}
	}

	if (k > bestSize)
	{
		// we found a better set
		bestSet[k] = stack[k];
		bestSize = k;

		return;
	}
	else
	{
		return;
	}




}



void printPowerset(int n, int *bestSet, int &bestSize, float *A)
{
	int *stack, k;

	// allocate space for the set
	stack = new int[n + 1];
	stack[0] = 0;  // 0 is not considered part of the set
	k = 0;

	while (1)
	{
		if (stack[k] < n)
		{
			stack[k + 1] = stack[k] + 1;
			k++;

		}
		else
		{
			stack[k - 1]++;
			k--;
		}

		if (k == 0)
			break;

		checkSet(stack, k, bestSet, bestSize, A);
	}



	//de-allocate space for the set
	delete[] stack;
	return;
}





int main()
{
	int n, bestSize, i;
	float *A, *R;
	int *bestSet;

	//display the header
	cout << endl << "CPSC 335-x-Programming Assignment #2" << endl;
	cout << "Longest increasing subsequence problem, power-set algorithm\n\n" << endl;
	cout << "Enter the number of elements in the sequence: " << endl;

	// read the number of elements
	cin >> n;

	//allocate space for the input sequence and array R
	A = new float[n];
	R = new float[n];

	//read the sequence
	cout << "\nEnter the elements in the sequence: " << endl;
	for (i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	//print the sequence
	cout << "\n\nInput sequence" << endl;
	print_sequence(n, A);

	//Start the chronograph to time the execution of the algorithm
	auto start = chrono::high_resolution_clock::now();

	//allocate space for the best set,
	// initialize its size to 0
	bestSet = new int[n + 1];
	bestSize = 0;

	//calculate the best sequence
	printPowerset(n, bestSet, bestSize, A);

	//retrieve the indices for generating the subsequence
	for (i = 0; i < bestSize; i++)
	{
		// decrease each index by one since the indices of array A are in
		// the range 0...n-1  and not  1...n
		R[i] = A[bestSet[i + 1] - 1];

	}

	// End the chronograph to time the loop
	auto end = chrono::high_resolution_clock::now();

	// display the output
	cout << "\n\nThe longest increasing subsequence has length" << endl;
	cout << bestSize << endl;
	cout << "\nThe longest increasing subsequence is" << endl;
	print_sequence(bestSize, R);


	//print the elapsed time in seconds and fractions of seconds
	int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
	double seconds = microseconds / 1E6;

	cout << "\n\nelapsed time: " << seconds << " seconds" << endl;


	// de-allocate the dynamic memory space
	delete[]A;
	delete[]R;
	delete[]bestSet;

	return 0;
}