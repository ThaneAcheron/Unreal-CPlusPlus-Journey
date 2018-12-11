// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int val = 1; 
int val2 = 2; 
int *valPointer = &val;
int & valRef = val;

void printVals() {

	std::cout << "Values: \n";
	std::cout << "Val: " << val << " Val2: " << val2 << " Val Pointer: " << *valPointer << " Val Reference: " << valRef << "\n";

	std::cout << "Addresses: \n";
	std::cout << "Val: " << &val << " Val2: " << &val2 << " Val Pointer: " << valPointer << " Val Reference: " << &valRef << "\n";
}

int main()
{
    std::cout << "Pointers!\n"; 
	printVals(); 

	//Repoint a pointer 
	valPointer = &val;
	printVals();
	//Rewrite value at pointer 
	*valPointer = 3;
	printVals();
	//Rewrite value at reference 
	valRef = 4;

	printVals();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
