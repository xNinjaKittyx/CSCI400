

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.



#include <iostream>		//inclusion of support for doing input & output
#include <iterator>     // std::ostream_iterator
#include <vector>		//inclusion of support for doing input & output
#include <algorithm>	//inclusion of support for doing input & output
#include <ctime>
#include <time.h>
#include <fstream>
using namespace std;	//declare access to standard stuff like cin, cout



int inversionCount(vector<int> &list1, vector<int> &list2) {

	int count = 0;

	for (int i = 0; i < list1.size(); i++) {
		for (int j = i; j < list1.size(); j++) {
			if ((list1[i] < list1[j] && list2[i] > list2[j]) || 
				(list1[i] > list1[j] && list2[i] < list2[j])) {
				count++;
			}

		}
	}

	return count;

}

void generatePreferenceList(int n, vector<int> &list) {
	list.resize(n);
	for (int i = 0; i < list.size(); i++) {
		list[i] = i + 1;
	}

	random_shuffle(list.begin(), list.end());
}
// Beginning of main function

int main()

{

	srand(time(NULL));

	int n = 4000;
	int m = 5;


	vector<vector<int>> DBList;


	clock_t timer;

	

	int leastCount = 2000000;
	int count;
	int pair;
	DBList.resize(m);
	for (int i = 0; i < DBList.size(); i++) {
		generatePreferenceList(n, DBList[i]);
	}

	cout << DBList.size() << endl;
	cout << DBList[0].size() << endl;

	cout << "Generated DB List" << endl;

	ofstream myfile;
	myfile.open("output.txt");

	timer = clock();
	clock_t temptime = clock();
	for (int i = 0; i < DBList.size(); i++) {

		leastCount = 2147483647;

		for (int j = 0; j < DBList.size(); j++) {
			
			
			count = inversionCount(DBList[i], DBList[j]);
			if ((count < leastCount) && (i != j)) {
				leastCount = count;
				pair = j;
			}


		}
		cout << "The Most Similar Person To Member #" << i << " Is Member #" << pair << endl;
		cout << "THe Number of Inversions is: " << leastCount << endl;

		/*cout << "Person # " << i << " is the following" << endl;
		cout << "{ ";
		for (int k = 0; k < DBList[i].size(); k++) {
			cout << DBList[i][k] << " ";
			
		}
		cout << " }" << endl;

		cout << "Person # " << pair << " is the following" << endl;
		cout << "{ ";
		for (int k = 0; k < DBList[pair].size(); k++) {
			cout << DBList[pair][k] << " ";

		}
		cout << " }" << endl;*/

		clock_t now = clock() - temptime;
		temptime = clock();
		cout << "This took " << (((float)now) / CLOCKS_PER_SEC) << " seconds" << endl;
	}

	myfile.close();
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



