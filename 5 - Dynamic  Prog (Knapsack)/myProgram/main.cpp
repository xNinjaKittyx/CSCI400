

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
	Values : v Array
	Weights : w Array
	Number of Unique Items n
	Capacity of Knapsack : C
	Maximum value from i to w : m[i, w]
	*/
	//vector<int> v = {6, 7, 5, 7, 8, 2, 11, 9, 13, 11};
	//vector<int> w = {4, 5, 2, 3, 6, 1, 10, 7, 8, 9};

	//vector<int> v = {6, 7, 5, 7, 8, 2, 11, 9, 13, 11, 9, 10, 8, 9, 12, 5, 14, 11, 16, 13, 14, 16, 11, 15, 17, 5, 25, 21, 26, 25};
	//vector<int> w = {4, 5, 2, 3, 6, 1, 10, 7, 8, 9, 5, 6, 3, 4, 7, 2, 11, 8, 9, 10, 5, 7, 3, 4, 9, 4, 17, 14, 13, 15};


	//vector<int> v = { 18, 11, 5, 19, 15, 6, 28, 12, 3, 7, 25, 4, 23, 27, 6, 7, 19, 23, 20, 25, 22, 4, 15, 2, 29, 15, 28, 20, 22, 29 };
	//vector<int> w = { 12, 5, 30, 19, 23, 6, 2, 2, 26, 28, 22, 3, 23, 22, 9, 18, 12, 10, 18, 26, 24, 3, 4, 22, 24, 18, 23, 28, 24, 20 };

	vector<int> v = { 18, 11, 5, 19, 15, 6, 28, 12, 3, 7, 25, 4, 23, 27, 6, 7, 19, 23, 20, 25, 22, 4, 15, 2, 29 };
	vector<int> w = { 12, 5, 30, 19, 23, 6, 2, 2, 26, 28, 22, 3, 23, 22, 9, 18, 12, 10, 18, 26, 24, 3, 4, 22, 24 };

	int C = 300; // Edit this!


	if (v.size() != w.size()) {
		cout << "v and w vectors size are not the same!" << endl;
		char c;
		cin >> c; 
		return -1;
	}
	int n = v.size();
	vector<vector<int>> m(n + 1, vector<int> (C + 1, 0)); // m[i][j] i is number of items, and j is the weight capacity.

	vector<vector<int>> p(n + 1, vector<int> (C + 1, 0)); // Will store all answer files
	// Resizing all the vectors. Add one because of the 0 items vector.
	m.resize(n + 1);
	for (int x = 0; x < m.size(); x++) {
		//  Due to the 0 weight
		m[x].resize(C + 1);
	}
	
	// Start the clock, this is where it actually begins.
	clock_t timer;
	timer = clock();


	// Now for i = 0, number of items is 0. 
	for (int j = 0; j <= C; j++) {
		m[0][j] = 0;
	}

	// Checking all numbers from i to n (which is the v/w size)
	for (int i = 1; i <= n; i++) {

		// Going through all weight capabilities. As it adds the next weight, it will only consider if it needs to take the next variable
		for (int j = 0; j <= C; j++) {

			// Is it even possible to fit the weight in the assumed capacity (j)?
			if (w[i-1] <= j) {

				// If it is, max (Value w/o new item, m[Without the item and removing the amount of space] and add the value of the new item.
				m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i-1]] + v[i-1]);
				if (v[i - 1] + m[i - 1][j - w[i - 1]] > m[i - 1][j])
					p[i][j] = 1;
				else
					p[i][j] = -1;
					
			}
			else {
				// Otherwise it's just the same as the previous item.
				p[i][j] = -1;
				m[i][j] = m[i - 1][j];
			}
		}
	}


	timer = clock() - timer;

	ofstream fout;
	fout.open("output.txt");
	// Now let's output the values
	fout << "\t";
	for (int j = 0; j <= C; j++) {
		fout << j << "\t";
	}
	fout << "\n";
	for (int i = 0; i <= n; i++) {
		fout << i << "\t";
		for (int j = 0; j <= C; j++) {
			fout << m[i][j] << "\t";
		}
		fout << "\n";
	}

	fout << "Here is the list of items picked\n";

	// Check every item and see if it was chosen or not
	while (n > 0) {
		if (p[n][C] == 1) {
			fout << n << "\t";
			n--;
			C -= w[n];
		}
		else {
			n--;
		}
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



