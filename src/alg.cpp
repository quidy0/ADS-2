// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
	double s = value;
	if (n == 0) {
		return 1;
	}
	for (uint16_t i = 1; i < n; ++i) {
		s = s * s;
	}
	return s;
}

uint64_t fact(uint16_t n) {
	uint16_t ret = 1;
	for (uint16_t i = 1; i <= n; ++i) {
		ret = i * ret;
	}
	return ret;
}

double calcItem(double x, uint16_t n) {
	double result = 1.0;

	for (uint16_t i = 1; i <= n; i++) {
		result *= x / i;
	}
	return result;
}

double expn(double x, uint16_t count) {
	double sum = 0.0;

	for (uint16_t i = 0; i < count; i++) {
		sum += calcItem(x, i);
	}
	return sum;
}

double sinn(double x, uint16_t count) {
	double result = 0;
	for (int i = 0; i < count; i++) {
		result += pown(-1, i) * pown(x, 2 * i + 1) / fact(2 * i + 1);
	}
	return result;
}

double cosn(double x, uint16_t count) {
	double result = 1;
	int sign = -1;
	double fact = 1;
	double power = 2;

	for (int i = 1; i < count; i++) {
		fact *= power * (power - 1);
		result += sign * pown(x, power) / fact;
		power += 2;
		sign *= -1;
	}

	return result;
}
