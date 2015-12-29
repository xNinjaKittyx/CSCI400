#include "BigNaturalNumber.h"

#include <ctime>

void BigNaturalNumber::random(int n) {
	number.resize(n);

	for (int i = 0; i < n; i++) {
		number[i] = rand() % 10;
	}

}


BigNaturalNumber BigNaturalNumber::operator+(const BigNaturalNumber &num) {
	BigNaturalNumber answer;
	// This is regardless of size of either number.
	int i;
	for (i = 0; i < num.number.size() && i < number.size(); i++) {
		answer.number.push_back(num.number[i] + number[i]);
	}
	if (i < num.number.size()) {
		while (i < num.number.size()) {
			answer.number.push_back(num.number[i]);
		}
	}
	else if (i < number.size()) {
		while (i < number.size()) {
			answer.number.push_back(number[i]);
		}
	}

	for (i = 0; i < answer.number.size() - 1; i++) {
		if (answer.number[i] > 9) {
			answer.number[i] -= 10;
			answer.number[i + 1] += 1;
		}
	}
	i = answer.number.size() - 1;
	if (answer.number[i] > 9) {
		answer.number[i] -= 10;
		answer.number.push_back(1);
	}
	return answer;
}

BigNaturalNumber BigNaturalNumber::operator*(const BigNaturalNumber &num) {
	BigNaturalNumber answer;
	answer.number.resize(num.number.size() + number.size());
	for (int i = 0; i < answer.number.size(); i++) {
		answer.number[i] = 0;
	}
	// This is assuming both numbers are the same size.


	// Multiplying two numbers.....

	for (int i = 0; i < num.number.size(); i++) {
		for (int j = 0; j < number.size(); j++) {
			answer.number[i + j] += (num.number[i] * number[j]);
		}
	}

	for (int i = 0; i < answer.number.size(); i++) {
		if (answer.number[i] > 9) {
			int remainder = answer.number[i] / 10;
			answer.number[i] = answer.number[i] % 10;
			answer.number[i + 1] += remainder;
		}
	}
	while (answer.number.back() == 0) {
		answer.number.pop_back();
	}
	return answer;
}