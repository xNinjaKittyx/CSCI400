

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


	cout << "How much does your postage cost?" << endl;
	int cost;
	cin >> cost;
	while (cost < 1) {
		cout << "Invalid postage cost." << endl;
		cout << "Type another cost." << endl;
		cin >> cost;
	}


	clock_t timer;
	timer = clock();
	vector<vector<int>> listOfCosts(3, vector<int>(cost+1)); // First number is the stamp type (1,4,5) and the second one is to keep track of all costs.
	for (int i = 0; i < 3; i++) {
		listOfCosts[i][0] = 0; // 0 should be 0. Cost of a 0 postage stamp, should be 0.
	}
	listOfCosts[0][1] = 1; // 1 cent postage has... 1 cent stamp
	listOfCosts[1][1] = 0; // 0 4 cent stamps
	listOfCosts[2][1] = 0; // 0 5 cent stamps.

	// I could just check 1, 4, 5 behind the current option to see which one will give the best solution.
	for (int i = 2; i <= cost; i++) { // the one that we're editing
		
		int totalStampsA = listOfCosts[0][i - 1] + listOfCosts[1][i - 1] + listOfCosts[2][i - 1];
		int totalStampsB;
		int totalStampsC;
		if (i > 3) {
			totalStampsB = listOfCosts[0][i - 4] + listOfCosts[1][i - 4] + listOfCosts[2][i - 4];
		}
		if (i > 4) {
			totalStampsC = listOfCosts[0][i - 5] + listOfCosts[1][i - 5] + listOfCosts[2][i - 5];
		}

		if (totalStampsA < totalStampsB) {
			if (totalStampsA < totalStampsC) {
				// if totalStampsA is the least amount of stamps
				listOfCosts[0][i] = listOfCosts[0][i - 1] + 1;
				listOfCosts[1][i] = listOfCosts[1][i - 1];
				listOfCosts[2][i] = listOfCosts[2][i - 1];
			}
			else {
				// if totalStampsC is the least amount of stamps
				listOfCosts[0][i] = listOfCosts[0][i - 5];
				listOfCosts[1][i] = listOfCosts[1][i - 5];
				listOfCosts[2][i] = listOfCosts[2][i - 5] + 1;
			}
		}
		else {
			if (totalStampsB < totalStampsC) {
				// if totalStampsB is the least amount of stamps
				listOfCosts[0][i] = listOfCosts[0][i - 4];
				listOfCosts[1][i] = listOfCosts[1][i - 4] + 1;
				listOfCosts[2][i] = listOfCosts[2][i - 4];
			}
			else {
				// if totalStampsC is the least amount of stamps
				listOfCosts[0][i] = listOfCosts[0][i - 5];
				listOfCosts[1][i] = listOfCosts[1][i - 5];
				listOfCosts[2][i] = listOfCosts[2][i - 5] + 1;
			}
		}
	}
	
	timer = clock() - timer;

	ifstream fin;
	ofstream fout;
	fout.open("output.txt");
	fout << "\tCosts\t1Cent\t4Cent\t5Cent" << endl;
	for (int i = 0; i <= cost; i++) {
		fout << "\t" << i << "\t" << listOfCosts[0][i] << "\t" << listOfCosts[1][i] << "\t" << listOfCosts[2][i] << endl;
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



