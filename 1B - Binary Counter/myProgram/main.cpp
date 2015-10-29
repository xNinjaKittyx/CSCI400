//Midterm Programming Test 

#include <iostream>     //inclusion of support for doing input & output 
#include <cmath>	    //inclusion of support for doing random number generation 
#include <cctype>	    //inclusion of support for character conversion
#include <vector>
using namespace std;	//declare access to standard stuff like cin, cout



// Beginning of main function
int main()               
{
	double myRandom;
	int i,j;

	int n;

	while (true)
	{
		// 2 Lists to find an answer.
		//vector<int> list0 = { 69, 38, 46, 43, 37, 34, 28, 75 };
		//vector<int> list1 = { 64, 77, 55, 24, 69, 12, 22, 69 };
		vector<int> list0;// = { 61, 27, 43, 54, 37, 45, 28, 64, 60, 38, 40, 43, 37, 34, 28, 75, 62, 33, 43, 60 };
		vector<int> list1;// = { 75, 74, 44, 24, 58, 12, 33, 69, 64, 70, 55, 24, 69, 12, 22, 69, 69, 74, 38, 24 };

		list0 = { 18, 29, 31, 42, 55, 66, 71, 85, 91, 103, 114, 128, 135, 140, 155, 81, 93, 17, 24, 65, 39,
			27, 58, 19, 130, 141, 182, 153, 104, 115, 18, 29, 31, 42, 55, 66, 71, 85, 91, 103, 114, 128,
			135, 140, 155 };
		list1 = { 81, 93, 17, 24, 65, 39, 27, 58, 19, 130, 141, 182, 153, 104, 115, 18, 29, 31, 42, 55, 66,
			71, 85, 91, 103, 114, 128, 135, 140, 155, 81, 93, 17, 24, 65, 39, 27, 58, 19, 130, 141, 182,
			153, 104, 115 };

		// Number of items per list.
		n = list0.size();

		// What Sum Are You Looking For?
		int sum = 4139;
		
		// Initialize the Binary Vector
		vector<int> numbers(n, 0);

		// Boolean in case sum isn't found. Or else we'll binary numbers with 2 in them.
		bool complete = false;
		while (complete == false) {

			// Raise the first number once.
			numbers[0] += 1;

			// Keep track of the total of the binary combination for this set.
			int total = 0;

			// Now go check if there's 2's in the binary.
			for (int i = 0; i < numbers.size(); i++) {
				if (numbers[i] == 2) {
					numbers[i + 1] += 1;
					numbers[i] -= 2;
				}


				// Add up all the numbers.
				if (numbers[i] == 1) {
					total += list1[i];
				}
				else if (numbers[i] == 0) {
					total += list0[i];
				}
			}
			if (total == sum) {
				cout << "The Total: " << total << " Was Found." << endl;
				for (int i = 0; i < numbers.size(); i++) {
					cout << numbers[i];

				}

				cout << endl;


				for (int i = 0; i < numbers.size(); i++) {
					if (numbers[i] == 1) {
						cout << list1[i];
					}
					else if (numbers[i] == 0) {
						cout << list0[i];
					}
					cout << endl;
				}


				break;
			}

			if (numbers[n - 1] == 1) {
				for (int i = 0; i < numbers.size(); i++) {
					if (numbers[i] == 1) {
						complete = true;
					}
					else {
						complete = false;
						break;
					}
				}
			}
		}

		


		char quit;
		cout << endl << endl
			<< "Do you want to quit?(Y or N)";
		cin >> quit;
		if (quit == 'y' || quit == 'Y')
			break;
	}
	return 0;

}