

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.


#include "BigNaturalNumber.h"

#include <iostream>		//inclusion of support for doing input & output
#include <vector>		//inclusion of support for doing input & output
#include <ctime>
#include <time.h>
#include <algorithm>
#include <fstream>

using namespace std;	//declare access to standard stuff like cin, cout


int main()

{

	srand(time(NULL));

	

	BigNaturalNumber x;
	BigNaturalNumber y;

	x.random(1000);
	y.random(1000);
	BigNaturalNumber z;

	cout << "Start Timer" << endl;
	//Where Timer Starts
	clock_t timer;
	timer = clock();
	z = x * y;

	// Where Timer Ends
	timer = clock() - timer;



	cout << "First Number" << endl;
	for (int i = 0; i < x.number.size(); i++) {
		cout << x.number[i];
	}
	cout << endl;
	cout << "Second Number" << endl;
	for (int i = 0; i < y.number.size(); i++) {
		cout << y.number[i];
	}
	cout << endl;
	for (int i = 32; i >= 0; i--) {
		cout << "-";
	}
	cout << endl;
	cout << "Answer" << endl;
	for (int i = 0; i < z.number.size(); i++) {
		cout << z.number[i];
	}
	cout << endl;


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



