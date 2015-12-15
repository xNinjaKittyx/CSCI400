

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.



#include <iostream>		//inclusion of support for doing input & output
#include <vector>		//inclusion of support for doing input & output
#include <ctime>
#include <time.h>
#include <algorithm>
#include <fstream>
using namespace std;	//declare access to standard stuff like cin, cout


// i and j are the position of the base in RNA.

string RNA = "";

bool pairing(char A, char B) {
	if (A == 'A' && B == 'U') {
		return true;
	}
	else if (A == 'U' && B == 'A') {
		return true;
	}
	else if (A == 'C' && B == 'G') {
		return true;
	}
	else if (A == 'G' && B == 'C') {
		return true;
	}
	else
		return false;
}

int opt(int i, int j) {
	if (i <= j - 4) {
		return 0;
	}
	int pair;

	
	if (RNA) {
		pair++;
		opt(i + 1, j - 1);
	}
	for (int x = i; x < j - 4; x++) {

	}
	return 

}

int main()

{

	srand(time(NULL));



	/*

	*/

	vector<vector<int>> pairs(RNA.length(), vector<int>(RNA.length(), 0));
	
	// Start the clock, this is where it actually begins.
	clock_t timer;
	timer = clock();

	for (int k = 5; k < RNA.length(); k++) {
		for (int i = 1; i < RNA.length() - k; i++) {
			int j = i + k;
			pairs[i][j] = max(pairs[i][j-1], max(1 + pairs[i][]))
		}
	}






	timer = clock() - timer;

	ofstream fout;
	fout.open("output.txt");
	// Now let's output the values


	fout << "Here is the list of items picked\n";


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



