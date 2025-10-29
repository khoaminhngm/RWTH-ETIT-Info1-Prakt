//============================================================================
// Name        : Fibonacci.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

int fibonacci(int n) {
	double phi = (1 + sqrt(5))/2;
	double psi = (1 - sqrt(5))/2;

	double fib;

	fib = (pow(phi, n) - pow(psi, n)) / sqrt(5);

	if(n == 0){
		return 0;
	};
	if(n == 1){
		return 1;
	};
	return fibonacci(n - 1) + fibonacci(n - 2);
};

int main() {

	// Timer Start für Geschwindigkeitstest
	auto start = chrono::high_resolution_clock::now();

	// Main
	int fib;

	cout << "Fibonaccizahlen für n = [0,42]: \n";

	for (int i = 0; i < 42; i++) {
		fib = fibonacci(i);
		cout << fib << endl;
	}

	// Timer - End
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	cout << duration.count() << " ms" << endl;

	return 0;
}
