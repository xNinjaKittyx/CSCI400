

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


void preferenceTransform
(int size, vector<int>::iterator itr1, vector<int>::iterator itr2)
{

	if (size <= 1) //If  the size is 1 or less, it is already sorted just return true.
		return;

	if (size == 2) //If size is 2, sort the two elements, and then return true.
	{
		if (*itr1 > *(itr1 + 1))
		{
			int temp;

			temp = *itr1;
			*itr1 = *(itr1 + 1);
			*(itr1 + 1) = temp;

			temp = *itr2;
			*itr2 = *(itr2 + 1);
			*(itr2 + 1) = temp;
			return;

		}

		return;
	}


	int sizeA = size / 2;			// Size of the first half  ==> A
	int sizeB = size - sizeA;	// Size of the second half ==> B

	preferenceTransform(sizeA, itr1, itr2);
	preferenceTransform(sizeB, itr1 + sizeA, itr2 + sizeA);

	vector<int> buffer1, buffer2;
	buffer1.resize(size);
	buffer2.resize(size);

	int countA = 0, countB = 0, countC = 0; // Count variables
	while (countA<sizeA && countB<sizeB)
	{
		if (*(itr1 + countA) < *(itr1 + sizeA + countB))
			// If the current element in first half, i.e. A, is smaller, 
			// it becomes the next value to go into the buffer.
		{
			buffer1[countC] = *(itr1 + countA);
			buffer2[countC] = *(itr2 + countA);

			countC++;
			countA++;

		}
		else
			// If the current element in the second half, i.e. B, is smaller, 
			// it becomes the next value to go into the buffer.
		{
			buffer1[countC] = *(itr1 + sizeA + countB);
			buffer2[countC] = *(itr2 + sizeA + countB);

			countC++;
			countB++;

		}
	}

	while (countA<sizeA)	// If vecB is all used up, place rest of vecA in vec C
	{
		buffer1[countC] = *(itr1 + countA);
		buffer2[countC] = *(itr2 + countA);

		countC++;
		countA++;
	}
	while (countB<sizeB)	// If vecA is all used up, place rest of vecB in vec C
	{
		buffer1[countC] = *(itr1 + sizeA + countB);
		buffer2[countC] = *(itr2 + sizeA + countB);

		countC++;
		countB++;
	}

	for (int i = 0; i< size; i++)
	{
		*(itr1 + i) = buffer1[i];
		*(itr2 + i) = buffer2[i];
	}
}

void preferenceTransform(vector<int>  pref1, vector<int>  pref2, vector<int>& transformed)
{
	if (pref1.size() != pref2.size())
		return;
	int size = pref1.size();

	preferenceTransform(size, pref1.begin(), pref2.begin());
	transformed.resize(size);
	for (int i = 0; i< size; i++)
	{
		//cout << pref1[i] << " , " << pref2[i] << endl;
		transformed[i] = pref2[i];
	}
}


//*************************************************************************

//
// Merge two sorted vectors function
//
int mergeTwoSortedVectors(vector<int> & vecA, vector<int> & vecB, vector<int> & vecC)
{

	//	Preconditions: (checking if the vectors are in ascending order)

	int size1 = vecA.size(), size2 = vecB.size();

	//for(int i=0; i<(size1-1); i++)	// Checking Vector A is in order
	//{
	//		if(vecA[i]>vecA[i+1])
	//		{	cout << "ERROR: The first vector is not in ascending order.\n";
	//			return;
	//		}
	//}
	//
	//for(int i=0; i<(size2-1); i++)// Checking Vector B is in order
	//{
	//		if(vecB[i]>vecB[i+1])
	//		{
	//			cout << "ERROR: The second vector is not in ascending order.\n";
	//			return;
	//		}
	//}

	//
	// Placing elements in vecC
	int countA = 0, countB = 0, countC = 0; // Count variables

	int countInversions = 0;

	while (countA<size1 && countB<size2)
	{
		if (vecA[countA]<vecB[countB])	// If the vecA element is smaller, it becomes the next vecC element
		{
			vecC[countC] = vecA[countA];
			countC++;
			countA++;
		}
		else	// If the vecB element is smaller, it becomes the next vecC element
		{
			vecC[countC] = vecB[countB];
			countC++;
			countB++;

			countInversions += (size1 - countA);
		}
	}

	while (countA<size1)	// If vecB is all used up, place rest of vecA in vec C
	{
		vecC[countC] = vecA[countA];
		countC++;
		countA++;
	}
	while (countB<size2)	// If vecA is all used up, place rest of vecB in vec C
	{
		vecC[countC] = vecB[countB];
		countC++;
		countB++;
	}

	return countInversions;

}


int mergeSort(vector<int> & vecToSort)
{
	int numOfInversions = 0;
	int temp; // Initialize temporary variables
	vector<int> vec1, vec2, vec3;

	// First: check if vectors are already sorted
	if (vecToSort.size() <= 1) //If  the size of  vecToSort is 1 or less, it is already sorted just return true.
		return 0;

	if (vecToSort.size() == 2) //If size of  vecToSort  is 2, sort the two elements, and then return true.
	{
		if (vecToSort[0]>vecToSort[1])
		{
			temp = vecToSort[1];
			vecToSort[1] = vecToSort[0];
			vecToSort[0] = temp;
			return 1;
		}
		return 0;
	}

	int size1 = vecToSort.size() / 2;	// Initialize size of new vectors
	int size2 = vecToSort.size() - size1;

	vec1.resize(size1);	// Resizing the temporary vectors
	vec2.resize(size2);

	for (int i = 0; i<size1; i++)	// Placing variables in two new vectors
		vec1[i] = vecToSort[i];
	for (int i = 0; i<size2; i++)
		vec2[i] = vecToSort[i + size1];


	numOfInversions += mergeSort(vec1); //Call mergeSort(vec1)  to sort the first vector.
	numOfInversions += mergeSort(vec2); //Call mergeSort(vec2) to sort the second vector.

	numOfInversions += mergeTwoSortedVectors(vec1, vec2, vecToSort); // Merge the two sorted vectors

	return numOfInversions;
}

int inversionCount(vector<int> &list1, vector<int> &list2) {

	int count = 0;
	vector<int> transformedList;
	transformedList.resize(list1.size());
	preferenceTransform(list1, list2, transformedList);

	count = mergeSort(transformedList);

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

		leastCount = 2147483646;

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



