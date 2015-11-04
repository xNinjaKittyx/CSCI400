

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.



#include <iostream>		//inclusion of support for doing input & output
#include <vector>		//inclusion of support for doing input & output
#include <algorithm>	//inclusion of support for doing input & output
#include <ctime>
#include <time.h>
using namespace std;	//declare access to standard stuff like cin, cout



vector<int> findK(vector<int> A) {
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

	// Now we need to check the first two numbers of the second vector.

	// if C[0] > C[1], that means K exists in the second half.

	// To save K, we need to save the vectors.
	vector<int> results;
	if (C[0] > C[1]) {
		results = findK(C);
	}
		
	// if C[0] < C[1], that means K MIGHT exist in the first half. (It can be C[0] that is k)
	// so if the 2nd condition is true, we must check the last object of B.
	// if B[last] > C[0], then C[0] is k.
	// if B[last] < C[0], then we can conclude that K is in the first half.

	else if (C[0] < C[1]) {
		if (B[bsize - 1] > C[0]) {
			return { C[0] };
		}
		else if (B[bsize - 1] < C[0]) {
			results = findK(B);
		}
	}
	
	return results;
}


int main()

{

	srand(time(NULL));


	// Given an Array A of elements n, there is an unknown unique k value in the middle.
	// This k value is the minimum value. Everything to the left and right is greater than k in sorted order.
	// For example: 59 43 39 28 17 49 78.
	// k value is 17.

	// First we will create an Array A of elements n.
	cout << "How many elements?\n";
	int elements;
	cin >> elements;

	vector<int> A;
	cout << "A[i] > A[i+1] BEFORE the value k\n";
	cout << "A[i] < A[i+1] AFTER the value k\n";
	for (int i = 0; i < elements; i++) {
		cout << "A[" << i << "]: ";
		int asdf;
		cin >> asdf;
		A.push_back(asdf);
	}

	clock_t timer;
	timer = clock();
	clock_t temptime = clock();
	

	// So we need a function that recursively calls itself.

	vector<int> results = findK(A);

	cout << "K is " << results[0] << endl;
	cout << "Vector size should be 1 and it is... " << results.size() << endl;







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



