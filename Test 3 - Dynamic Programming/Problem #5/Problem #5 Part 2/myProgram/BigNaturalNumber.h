#pragma once
#ifndef bullet
#define bullet

#include <vector>

class BigNaturalNumber {
public:
	
	BigNaturalNumber operator+(const BigNaturalNumber &num);
	BigNaturalNumber operator-(const BigNaturalNumber &num);
	BigNaturalNumber operator*(const BigNaturalNumber &num);
	void random(int n); // Resize Vector to size n, and randomly generate a long number
	std::vector<int> number;

private:


};

#endif