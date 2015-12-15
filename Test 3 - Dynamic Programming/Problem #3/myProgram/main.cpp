

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.



#include <iostream>		//inclusion of support for doing input & output
#include <vector>		//inclusion of support for doing input & output
#include <ctime>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;	//declare access to standard stuff like cin, cout





int main()

{

	srand(time(NULL));

	
	
	/*

	

	*/
	string A, B, C;

	cout << "Please type the first string." << endl;
	cin >> A;

	cout << "Please type the second string." << endl;
	cin >> B;

	cout << "Please type in the string that interleaves between the two." << endl;
	cin >> C;

	// if the string lengths are not correct.
	while (A.length() + B.length() != C.length()) {
		cout << "1st and 2nd String do not interleve into the 3rd string." << endl;
		cout << "Would you like to try again? (Y/N)" << endl;
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			cout << "Please type the first string." << endl;
			cin >> A;

			cout << "Please type the second string." << endl;
			cin >> B;

			cout << "Please type in the string that interleaves between the two." << endl;
			cin >> C;
		}
		else if (choice == 'N' || choice == 'n') {
			return 0;
		}
	
	}

	// So we can create a 2D boolean table.
	// bool [size of A] [size of B] will return true, if it interleves.
	// Otherwise, false obviously means it does not.
	// IL means interleve
	vector<vector<bool>> ILChart(A.length()+1, vector<bool> (B.length()+1, false));


	// Start the clock, this is where it actually begins.
	clock_t timer;
	timer = clock();

	for (int i = 0; i <= A.length(); i++) {
		for (int j = 0; j <= B.length(); j++) {

			// If both strings are at the 0 mark, that means both of them have an empty string
			if (i == 0 && j == 0) {
				ILChart[i][j] = true;
			}
			// When ILChart[0][j] is happening. Which means its only checking B characters at the moment. All A's are empty.
			// Since i == 0 happens first, this must be checked before j==0
			else if (i == 0 && B[j - 1]==C[j-1]) {
				ILChart[i][j] = ILChart[i][j - 1];
			}

			// When ILChart[i][0] is happening.
			else if (j == 0 && A[i - 1] == C[i - 1]) {
				ILChart[i][j] = ILChart[i - 1][j];
			}

			// if i or j == 0 and the above does not work then do the following.
			else if (i == 0 || j == 0) {
				ILChart[i][j] = false;
			}

			// When C matches A, but not B.
			else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) {
				ILChart[i][j] = ILChart[i - 1][j];
			}
			// When C matches B, but not A.

			else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1]) {
				ILChart[i][j] = ILChart[i][j - 1];
			}

			// When C matches both...
			else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]) {
				ILChart[i][j] = (ILChart[i - 1][j] || ILChart[i][j - 1]); // So this means, if either pathing works, then return as true. Since the next iteration will
				// check ther previous one for the answer, 
			}
			else {
				ILChart[i][j] = false;
			}
		}
	}

	timer = clock() - timer;


	// The answer is found in ILChart[A.length()][B.length()]
	if (ILChart[A.length()][B.length()])
		cout << "The Answer is TRUE" << endl;
	else
		cout << "The Answer is FALSE" << endl;



	ofstream fout;
	fout.open("output.txt");

	for (int i = 0; i <= A.length(); i++) {
		for (int j = 0; j <= B.length(); j++) {
			fout << ILChart[i][j] << "\t";
		}
		fout << endl;

	}


	fout << "This took " << (((float)timer) / CLOCKS_PER_SEC) << " seconds" << endl;
	fout.close();


	cout << "All results have been saved to output.txt." << endl;
	cout << endl << "Please enter any charcter and a return to quit the program." << endl;



	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;




}

//End of the main function.



