

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.



#include <iostream>		//inclusion of support for doing input & output
#include <vector>		//inclusion of support for doing input & output
#include <ctime>
#include <time.h>
using namespace std;	//declare access to standard stuff like cin, cout

bool found = false;

vector<int> gradientSearch(vector<vector<int>> &A, vector<int> selected) {
	// Assumes that columns and Rows are EQUAL

	int size = A[0].size();

	int x = selected[0];
	int y = selected[1];

	// Check for lowest number
	int lowestNumber = A[x][y];

	bool up = true;
	bool down = true;
	bool left = true;
	bool right = true;

	if (x == 0)
		left = false;
	if (x == size - 1)
		right = false;
	if (y == 0)
		down = false;
	if (y == size - 1)
		up = false;
	
	bool auth = true;
	if (up) {
		if (A[x][y + 1] < A[x][y]) {
			auth = false;
			selected = gradientSearch(A, { x, y + 1 });
			if (found)
				return selected;
		}
	}
	if (down) {

		if (A[x][y - 1] < A[x][y]) {
			auth = false;
			selected = gradientSearch(A, { x, y - 1 });
			if (found)
				return selected;
		}
	}
	if (left) {
		if (A[x - 1][y] < A[x][y]) {
			auth = false;
			selected = gradientSearch(A, { x - 1, y });
			if (found)
				return selected;
		}
	}
	if (right) {
		if (A[x + 1][y] < A[x][y]) {
			auth = false;
			selected = gradientSearch(A, { x + 1, y });
			if (found)
				return selected;
		}
	}

	if (auth)
		found = true;
	return selected;

	
	
}

int main()

{

	srand(time(NULL));

	

	cout << "How many columns and rows?\n";
	int elements;
	cin >> elements;

	vector<vector<int>> A;
	A.resize(elements);
	for (int i = 0; i < elements; i++) {
		for (int j = 0; j < elements; j++) {
			cout << "A[" << i << "][" << j << "]: ";
			int asdf;
			cin >> asdf;
			A[i].push_back(asdf);
		}
	}
	

	clock_t timer;
	timer = clock();


	// Start from the top left corner, then move if there's a number lower.


	vector<int> selected = gradientSearch(A, { 0, 0 });

	cout << "Local Minimum was found at " << selected[0] << ", " << selected[1] << endl;

	cout << endl << "This graph uses X as left to right, and Y as up to down." << endl << endl; 

	for (int j = 0; j < elements; j++) {
		for (int i = 0; i < elements; i++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
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



