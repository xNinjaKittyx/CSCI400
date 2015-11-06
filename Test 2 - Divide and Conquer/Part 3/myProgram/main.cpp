

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.



#include <iostream>		//inclusion of support for doing input & output
#include <vector>		//inclusion of support for doing input & output
#include <ctime>
#include <time.h>
using namespace std;	//declare access to standard stuff like cin, cout



int mergeSort(vector<int> &A, vector<int> &B, vector<int> &C) {
	int count = 0;
	int i = 0, j = 0;
	// Count Significant Inversions
	while (i < A.size() && j < B.size()) {
		if (A[i] > 2 * B[j]) {
			count += A.size() - 1;
			j++;
		}
		else {
			i++;
		}
	}
	i = 0, j = 0;

	int cpointer = 0;
	// Sort the Array.
	while (i < A.size() && j < B.size()) {
		if (A[i] < B[j]) {

			C[cpointer] = A[i];
			i++;
		}
		else {
			C[cpointer] = B[j];
			j++;
		}
		cpointer++;
	}
	while (i < A.size()) {
		C[cpointer] = A[i];
		i++;
		cpointer++;
	}
	while (j < B.size()) {
		C[cpointer] = B[j];
		j++;
		cpointer++;
	}

	return count;
	
}

int countInversions(vector<int> &A) {
	int size = A.size();

	// If the vector is only 1, there is no inversions to be counted.
	if (size <= 1) {
		return 0;
	}
	else if (size == 2) {
		if (A[0] > 2 * A[1]) {
			if (A[0] > A[1]) {
				int temp = A[0];
				A[0] = A[1];
				A[1] = temp;
			}
			return 1;
		}
		else
			if (A[0] > A[1]) {
				int temp = A[0];
				A[0] = A[1];
				A[1] = temp;
			}
			return 0;
	}
	else {

		// First we need to split the vector into two parts.
		vector<int> B;
		vector<int> C;

		// Now we need to know how much to put in each vector.
		int bsize = A.size() / 2;
		int csize = A.size() - bsize;

		// Now resize the vectors.
		B.resize(bsize);
		C.resize(csize);

		// Now we need to put all the values of A into these two vectors.
		for (int i = 0; i < bsize; i++) { // Reasons for using the csize/bsize, is to reduce number of vector calls.
			B[i] = A[i];

		}
		for (int i = 0; i < csize; i++) {
			C[i] = A[bsize + i];
		}


		int result = 0;
		result += countInversions(B);
		result += countInversions(C);
		result += mergeSort(B, C, A);

		return result;


	}
}

int main()

{

	srand(time(NULL));


	// First we will create an Array A of elements n.
	cout << "How many elements?\n";
	int elements;
	cin >> elements;

	vector<int> A;
	for (int i = 0; i < elements; i++) {
		cout << "A[" << i << "]: ";
		int asdf;
		cin >> asdf;
		A.push_back(asdf);
	}
	
	clock_t timer;
	timer = clock();
	
	int total = countInversions(A);

	cout << "There are " << total << " significant inversions" << endl;

	for (int i = 0; i < A.size(); i++) {
		cout << "Results[" << i << "]: " << A[i] << endl;
	}






	timer = clock() - timer;

	cout << "This took " << (((float)timer) / CLOCKS_PER_SEC) << " seconds" << endl;
	cout << endl << "Please enter any charcter and a return to quit the program." << endl;



	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;




}

//End of the main function.



