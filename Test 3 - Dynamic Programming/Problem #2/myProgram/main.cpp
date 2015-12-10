

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.



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

	
	
	/*
	DESIGN:

	We start with the first of the array.
	We grab the very first of the array, and the very last before the current spot 
	Then we add the pointer to the first of the array by 1,
	and delete the pointer of the last before current by 1.

	Then we add those up and find the most optimal solution
	Then, we set that solution as the current spot.
	
	
	*/

	clock_t timer;
	timer = clock();


	//fout << "This took " << (((float)timer) / CLOCKS_PER_SEC) << " seconds" << endl;
	//fout.close();


	cout << "All results have been saved to output.txt." << endl;
	cout << endl << "Please enter any charcter and a return to quit the program." << endl;



	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;




}

//End of the main function.



