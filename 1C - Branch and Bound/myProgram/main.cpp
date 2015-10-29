//Midterm Programming Test 

#include <iostream>     //inclusion of support for doing input & output 
#include <cmath>	    //inclusion of support for doing random number generation 
#include <cctype>	    //inclusion of support for character conversion
#include <vector>
using namespace std;	//declare access to standard stuff like cin, cout

vector<int> list0, list1, list2;

//Recursive exhaustive branching search for a mixture sequence 
//	C[begin] , C[begin + 1], ..., C[end] 
//derive from
//	Sequence: A[begin] , A[begin + 1], ..., A[end] and
//	Sequence: B[begin] , B[begin + 1], ..., B[end]  
//such that
//   The sum of C[begin] , C[begin + 1], ..., C[end]  equals targetSum
bool mixtureSequenceSearch(int begin, int end, int targetSum)
{
	if (begin > end) //Nothing further to incorporate
	{
		if (targetSum == 0)
			return true;
		else
			return false;
	}

	if (mixtureSequenceSearch(begin + 1, end, targetSum - list0[begin]) == true)
	{	//There is a solution if we select A[begin] into the mixture sequence 
		list2[begin] = list0[begin];
		return true;
	}
	else if (mixtureSequenceSearch(begin + 1, end, targetSum - list1[begin]) == true)
	{	//There is a solution if we select B[begin] into the mixture sequence 
		list2[begin] = list1[begin];
		return true;
	}
	else //There is no way to find a mixture sequence for that partial sum
		return false;




}


// Beginning of main function
int main()               
{
	double myRandom;
	int i,j;

	int n;

	while (true)
	{
		// 2 Lists to find an answer.
		//list0 = { 69, 38, 46, 43, 37, 34, 28, 75 };
		//list1 = { 64, 77, 55, 24, 69, 12, 22, 69 };
		//list0 = { 61, 27, 43, 54, 37, 45, 28, 64, 60, 38, 40, 43, 37, 34, 28, 75, 62, 33, 43, 60 };
		//list1 = { 75, 74, 44, 24, 58, 12, 33, 69, 64, 70, 55, 24, 69, 12, 22, 69, 69, 74, 38, 24 };
		
		list0 = { 18, 29, 31, 42, 55, 66, 71, 85, 91, 103, 114, 128, 135, 140, 155, 81, 93, 17, 24, 65, 39, 
			27, 58, 19, 130, 141, 182, 153, 104, 115, 18, 29, 31, 42, 55, 66, 71, 85, 91, 103, 114, 128, 
			135, 140, 155 };
		list1 = { 81, 93, 17, 24, 65, 39, 27, 58, 19, 130, 141, 182, 153, 104, 115, 18, 29, 31, 42, 55, 66, 
			71, 85, 91, 103, 114, 128, 135, 140, 155, 81, 93, 17, 24, 65, 39, 27, 58, 19, 130, 141, 182, 
			153, 104, 115 };


		// Number of items per list.
		n = (int) list0.size();

		// What Sum Are You Looking For?
		cout << "What sum are you looking for?" << endl;
		int sum = 99991;

		list2.resize(n);
		// Initialize the answer vector.

		if (mixtureSequenceSearch(0, n - 1, sum) == true)
		{
			cout << endl << endl
				<< "Mixture sequence with a sum of " << sum << " found: " << endl;

			for (int i = 0; i < n; i++)
				cout << "C[" << i << "]=" << list2[i] << endl;
		}
		else
		{
			cout << endl << endl
				<< "No solution found" << endl;
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