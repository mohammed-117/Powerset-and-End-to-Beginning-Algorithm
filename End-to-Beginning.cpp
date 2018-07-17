// Assignment#:2
// End-to-Beginning Algorithm
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

int main()
{
	int n, i, j, max, index;
	float *A;
	float *R;
	int *H;

	// display the header
	cout << endl << "CPSC 335-x- Programming Assignment #2" << endl;
	cout << "Longest non-decreasing subsequence problem, end-to-beginning algorithm\n\n" << endl;
	cout << "Enter the number of elements in the sequence:" << endl;

	// read the number of elements
	cin >> n;

	// allocate space for the input sequence and array H
	A = new float[n];
	H = new int[n];

	// read the sequence
	cout << "\nEnter the elements in the sequence:" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	// print the sequence
	cout << "\n\nInput sequence:" << endl;
	print_sequence(n, A);

	// Start the chronograph to time the execution of the algorithm
	auto start = chrono::high_resolution_clock::now();

	// loop to populate the H array with all 0 values

	for (i = 0; i < n; i++)
	{
		H[i] = 0;
	}
	// loop to calculate the values of array H
	for (i = n - 2; i >= 0; i--)
	{
		for (j = i + 1; j < n; j++)
		{
			// WRITE CODE THAT IS AN IF CONDITON THAT DECIDES WHETHER
			// TO CHANGE OR NOT THE VALUE OF H[i]
			if ((A[i] < A[j]) && (H[i] <= H[j]))
			{
				H[i] = H[j] + 1;

			}
		}
	}

	//calculate in max the length of the longest subsequence by adding 1
	// to the maximum value in H
	max = H[0];

	for (i = 0; i < n; i++)
	{
		if (max < H[i])
		{
			max = H[i];
		}
	}
	max++;

	// allocate space for the subsequence R
	R = new float[max];
	//add elements to R by whose H's values are in decreasing order, starting
	// with max-1
	// store in index the H values sought
	index = max - 1;

	//store in j the index of the element appended to R
	j = 0;
	for (i = 0; i < n; i++)
	{
		if (H[i] == index)
		{
			//WRITE THE BLOCK OF STATEMENTS TO ADD A[i] TO THE R SEQUENCE BY
			//STORYING IT INTO R[j], DECREMENTING INDEX AND INCREMENTING j
			R[j] = A[i];
			j++;
			index--;
		}
	}

	//End the chronograph to time the loop
	auto end = chrono::high_resolution_clock::now();

	//write the output
	cout << "\nThe longest non-decreasing subsequence has length" << endl;
	cout << max << endl;
	cout << "\nThe longest non-decreasing subsequence is" << endl;

	print_sequence(max, R);

	//print the elapsed time in seconds and fractions of seconds
	int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
	double seconds = (microseconds / 1E6);

	cout << "\n\nelapsed time: " << seconds << " seconds" << endl;


	// de-allocate the dynamic memory space
	delete[] A;
	delete[] H;
	delete[] R;





	return 0;
}