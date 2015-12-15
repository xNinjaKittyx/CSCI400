#include "BigNaturalNumber.h"

#include <ctime>
#include <iostream>
#include <algorithm>


// ALL NUMBERS MUST BE UNSIGNED. NEGATIVE NUMBERS WILL NOT WORK.


void BigNaturalNumber::random(int n) {
	number.resize(n);
	for (int i = 0; i < n; i++) {
		number[i] = (rand() % 9) + 1;
	}

}

void makeEqualLengths(std::vector<int> &A, std::vector<int> &B) {
	int a = A.size();
	int b = B.size();
	if (a == b) {
		return;
	}
	while (A.size() < B.size()) {
		A.insert(A.begin(), 0);
	}
	while (B.size() < A.size()) {
		B.insert(B.begin(), 0);
	}
}


BigNaturalNumber complement(BigNaturalNumber num) {
	BigNaturalNumber answer;
	answer.number.resize(num.number.size());
	for (int i = 0; i < num.number.size(); i++) {
		answer.number[i] = 9 - num.number[i];
	}

	return answer;
}

BigNaturalNumber BigNaturalNumber::operator+(const BigNaturalNumber &num) {
	BigNaturalNumber answer = num;
	// This is regardless of size of either number.
	int i;

	makeEqualLengths(answer.number, number);

	for (i = 0; i < answer.number.size(); i++) {
		answer.number[i] = number[i] + answer.number[i];
	}

	for (i = answer.number.size() - 1; i > 0; i--) {
		if (answer.number[i] > 9) {
			answer.number[i] -= 10;
			answer.number[i - 1] += 1;
		}
	}
	if (answer.number[0] > 9) {
		answer.number[0] -= 10;
		answer.number.insert(answer.number.begin(), 1);
	}
	return answer;
}

BigNaturalNumber BigNaturalNumber::operator-(const BigNaturalNumber &num) {

	// This is using 9's compliment. THis means that negative numbers are not considered.
	// Trying to do 10's compliment due to losing of accuracy at higher numbers.
	// Sadly, this is not possible since doing the 10's compliment will require that
	// the number of items in teh vector be static. (using 32-bit, 128-bit, 1024-bit, whatever)

	BigNaturalNumber sum, comp, answer;
	// Grab the complement and then add them.
	comp = num;
	if (comp.number.size() > number.size()) {
		std::cout << "WARNING: NEGATIVE NUMBER" << std::endl;
	}
	makeEqualLengths(comp.number, number);

	comp = complement(comp);
	sum = *this + comp;
	// Now I have to get rid of the first digit in sum

	if (sum.number.size() != comp.number.size()) {
		answer.number.resize(sum.number.size() - 1);
		for (int i = 1; i < sum.number.size(); i++) {
			answer.number[i - 1] = sum.number[i];
		}
		BigNaturalNumber one;
		one.number.push_back(1);
		answer = answer + one;
	}

	return answer;
}

BigNaturalNumber BigNaturalNumber::operator*(const BigNaturalNumber &num) {
	// LETS ASSUME THESE ARE THE SAME SIZE?
	BigNaturalNumber newNum = num;
	makeEqualLengths(newNum.number, number);
	int n = number.size();
	int m = num.number.size();
	std::cout << n << " " << m << std::endl;
	BigNaturalNumber Z;
	Z.number.resize(1);
	if (n == 0 || m == 0) {
		Z.number[0] = 0;
		return Z;
	}

	if (n == 1) {
		Z.number.resize(m);
		for (int i = 0; i < num.number.size(); i++) {
			Z.number[i] = num.number[i] * number[0];
		}
		for (int i = Z.number.size() - 1; i > 0; i--) {
			int remainder = Z.number[i] / 10;
			Z.number[i] = Z.number[i] % 10;
			Z.number[i-1] += remainder;

		}
		int remainder = Z.number[0] / 10;
		Z.number[0] = Z.number[0] % 10;
		Z.number.insert(Z.number.begin(), remainder);
		return Z;
	}
	else if (m == 1) {
		Z.number.resize(n);
		for (int i = 0; i < number.size(); i++) {
			Z.number[i] = num.number[0] * number[i];
		}
		for (int i = Z.number.size() - 1; i > 0; i--) {
			int remainder = Z.number[i] / 10;
			Z.number[i] = Z.number[i] % 10;
			Z.number[i - 1] += remainder;

		}
		int remainder = Z.number[0] / 10;
		Z.number[0] = Z.number[0] % 10;
		Z.number.insert(Z.number.begin(), remainder);
		return Z;
	}


	int firstHalf = n / 2;
	int secondHalf = n - firstHalf;

	BigNaturalNumber X1, X0, Y1, Y0;

	for (int i = 0; i < firstHalf; i++) {
		X0.number.push_back(number[i]);
		Y0.number.push_back(num.number[i]);
	}
	for (int i = firstHalf; i < n; i++) {
		X1.number.push_back(number[i]);
		Y1.number.push_back(num.number[i]);

	}
	/*firstHalf = m / 2;
	secondHalf = m - firstHalf;
	for (int i = 0; i < firstHalf; i++) {
		Y0.number.push_back(num.number[i]);
	}
	for (int i = firstHalf; i < m; i++) {
		Y1.number.push_back(num.number[i]);

	}*/
	n = std::max(n, m);
	BigNaturalNumber p = (X0 + X1) * (Y0 + Y1);
	BigNaturalNumber x1y1 = X1 * Y1;
	BigNaturalNumber x0y0 = X0 * Y0;
	
	// X1Y1 * (pow(10, n)) + (P - X1Y1 - X0Y0) * (pow(10, n/2)) + X0Y0;
	// First shift X1Y1 n digits to the left.
	
	//BigNaturalNumber answer = p - x1y1 - x0y0; // I'm getting overflow problems here.
	//for (int i = 0; i < n; i++) {
	//	x1y1.number.push_back(0);
	//}
	//for (int i = 0; i < n / 2; i++) {
	//	answer.number.push_back(0);
	//}
	//answer = answer + x1y1 + x0y0;

	//return answer;



	// THIS IS SO COMPLICATED
	// Because we're not using long ints for our number, it makes it EXTREMELY DIFFICULT
	// So, i took the liberty to turn everything back into long ints, do the final calculation, and
	// put the pieces back into a BigNaturalNumber
	long int P = 0, X1Y1 = 0, X0Y0 = 0;
	int count = p.number.size() - 1;
	for (int i = 0; i < p.number.size(); i++) {
		P += p.number[i] * pow(10, count);
		count--;
	}
	count = x1y1.number.size() - 1;
	for (int i = 0; i < x1y1.number.size(); i++) {
		X1Y1 += x1y1.number[i] * pow(10, count);
		count--;
	}
	count = x0y0.number.size() - 1;
	for (int i = 0; i < x0y0.number.size(); i++) {
		X0Y0 += x0y0.number[i] * pow(10, count);
		count--;
	}

	long int ANSWER = X1Y1*(pow(10,n)) + ((P - X1Y1 - X0Y0) * (pow(10, n/2))) + X0Y0;
	BigNaturalNumber answer;
	int digits = log10(ANSWER) + 1;
	count = 0;
	
	for (unsigned int i = pow(10, digits); i > 0 ; i /= 10)
	{
		answer.number.push_back(ANSWER / i);
		ANSWER -= (ANSWER / i)*i;
	}

	// Then we gotta put this number into a BigNaturalNumber
	while (answer.number[0] == 0) {
		answer.number.erase(answer.number.begin());
	}

	return answer;
}