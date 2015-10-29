

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
	

	vector<int> order = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
	};
	vector<int>::iterator start = order.begin();
	vector<int>::iterator end = order.end();
	vector<int>::iterator it;

	vector<twoints> answer = { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }
	};

	int lowestSum = 1000000;
	int iteration = 0;
	while (next_permutation(start, end)) {


		// This is a exhaustive search with a greedy criteria. The criteria is "Highest work/time ratio first."
		
		float next;
		bool a = true;
		for (it = start; it != end; it++) {
			if (it == start)
				next = ((float)groups[*it].work / (float)groups[*it].time);
			else {
				if (next < ((float)groups[*it].work / (float)groups[*it].time)) {
					a = false;
					break;
				}
				else
					next = ((float)groups[*it].work / (float)groups[*it].time);
			}

		}
		if (a) {
			int i = 0;
			for (it = start; it != end; it++) {
				answer[i] = groups[*it];
				i++;
			}
		}
		

	}

	int weightedSum = 0;
	int currentTime = 0;
	for (int i = 0; i < answer.size(); i++) {
		currentTime += answer[i].time;
		weightedSum += (currentTime * (answer[i].work));

	}
	lowestSum = weightedSum;

	cout << "Lowest Sum is " << lowestSum << endl;

	for (int i = 0; i < answer.size(); i++) {
		cout << i << "\t";
	}

	cout << endl;

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].work << "\t";
	}

	cout << endl;

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].time << "\t";
	}

	cout << endl;

	char a;
	cin >> a;

	return 0;
}


