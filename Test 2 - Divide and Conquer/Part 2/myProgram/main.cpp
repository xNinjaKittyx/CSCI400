

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.



#include <iostream>		//inclusion of support for doing input & output
#include <vector>		//inclusion of support for doing input & output
#include <ctime>
#include <time.h>
using namespace std;	//declare access to standard stuff like cin, cout


vector<int> findMaxAndMin(vector<int> A) {
	// Alright, so first we gotta make sure to return if the vector is only 1 or 2 size.
	int size = A.size(); // so we don't have to call this every time.
	if (size == 1) {
		return A;
	}
	else if (size == 2) {
		// To make it easier, let us make A[0] the lower value and A[1] the higher value. Kinda like merge sort.
		if (A[0] > A[1]) {
			int temp = A[0];
			A[0] = A[1];
			A[1] = temp;
		}
		return A;
	}
	else {
		// First we need to split the vector into two parts.
		vector<int> B;
		vector<int> C;

		// Now we need to know how much to put in each vector.
		int bsize = size / 2;
		int csize = size - bsize;

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

		// Alright, so usually here we will have two vectors. We will call recursively on these two vectors.
		// Then we grab the results and compare, We should ONLY RETURN SIZE 1 OR 2 VECTORS

		vector<int> left = findMaxAndMin(B);
		vector<int> right = findMaxAndMin(C);
		// We now have the Max and Min of both sides.
		// Compare these two vectors.

		// We will always have either vectors that have 2, or one of them will have 1.
			
		if ((left.size() + right.size()) == 4) {
			// In the case we have a 2 and 2 vectors, let's find the smaller number, push it

			vector<int> results;

			if (left[0] < right[0]) {
				results.push_back(left[0]);
			}
			else {
				results.push_back(right[0]);
			}

			// Let's find the larger number, and push it.

			if (left[1] > right[1]) {
				results.push_back(left[1]);
			}
			else {
				results.push_back(right[1]);
			}
			
			// We have found the max/min of these two vectors, Return
			return results;

		}
		else if ((left.size() + right.size()) == 3) {
			// This means one of these vectors got the vector with size 1.
			// Let's find which one it is.
			if (left.size() == 1) {

				// Left side is one. Now we check if this number is a local min/max
				if (left[0] < right[0]) {

					// if left actually useful for the minimum.
					right[0] = left[0];
				}
				// if left side is useful for maximum.
				if (left[0] > right[1]) {

					right[1] = left[0];
				}

				// We are done here. Return the right vector.
				return right;
			}

			// Do the same thing for the right side if the right side vector is SIZE 1

			if (right.size() == 1) {

				// right side is one. Now we check if this number is a local min/max
				if (right[0] < left[0]) {

					// if right actually useful for the minimum.
					left[0] = right[0];
				}
				// if right side is useful for maximum.
				if (right[0] > left[1]) {

					left[1] = right[0];
				}

				// We are done here. Return the left vector.
				return left;
			}
		}




	

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

	// So in this algorithm, we will split until there are pairs, then compare them.
	// Then compare the results of the pairs.
	// Instead of calling 2 different programs finding max and min, we will find them at the same time.
	// We will pass a 2 integer vector
	
	vector<int> results; 

	results = findMaxAndMin(A);


	cout << "The Maximum Is: " << results[1] << endl;
	cout << "The Minimum Is: " << results[0] << endl;
	cout << "Therefore The Largest Gap Is: " << results[1] - results[0] << endl;



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



