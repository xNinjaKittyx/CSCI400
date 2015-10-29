

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

int main() {
	struct twoints {
		int work;
		int time;
	};
	vector<twoints> groups = { { 6, 4 }, { 7, 5 }, { 5, 2 }, { 7, 3 }, { 8, 6 }, 
	{ 2, 1 }, { 11, 10 }, { 9, 7 }, { 13, 8 }, { 11, 9 }, { 4, 3 }, { 5, 3 }, { 2, 1 }, { 7, 5 }, { 10, 8 }
	};


	// Selection Sort for twoints.

	for (int z = 0; z < groups.size() - 1; z++) {
		int max = z;
		for (int y = z + 1; y < groups.size(); y++) {
			double first = ((double)groups[max].work / (double)groups[max].time);
			double second = ((double)groups[y].work / (double)groups[y].time);
			if (first < second) {
				max = y;
			}
		}
		if (max != z) {
			iter_swap(groups.begin() + z, groups.begin() + max);
		}
	}
	

	// Calculate weighted Sum
	int weightedSum = 0;
	int currentTime = 0;
	for (int i = 0; i < groups.size(); i++) {
		currentTime += groups[i].time;
		weightedSum += (currentTime * (groups[i].work));

	}


	// Display Results

	cout << "Lowest Sum is " << weightedSum << endl;

	for (int i = 0; i < groups.size(); i++) {
		cout << i << "\t";
	}

	cout << endl;

	for (int i = 0; i < groups.size(); i++) {
		cout << groups[i].work << "\t";
	}

	cout << endl;

	for (int i = 0; i < groups.size(); i++) {
		cout << groups[i].time << "\t";
	}
	
	cout << endl;

	for (int i = 0; i < groups.size(); i++) {
		cout << (float)groups[i].work / (float)groups[i].time << "\t";
	}

	cout << endl;

	char a;
	cin >> a;

	return 0;
}


