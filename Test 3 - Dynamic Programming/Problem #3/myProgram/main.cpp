

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

	//http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/
	// So we can create a 2D boolean table.
	// bool [size of A] [size of B] will return true, if it interleves.
	// Otherwise, false obviously means it does not.
	int aa = A.length();
	int bb = B.length();
	// IL means interleve
	vector<vector<bool>> IL = (aa, vector<bool> (bb));

	// Start the clock, this is where it actually begins.
	clock_t timer;
	timer = clock();

	for ()










	timer = clock() - timer;

	ofstream fout;
	fout.open("output.txt");



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



