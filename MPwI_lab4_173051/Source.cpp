#include <iostream>
#include <stdio.h>    
#include <stdlib.h>     
#include <time.h> 
#include "Vector.h"

void menu()
{
	std::cout << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Print frequency matrix" << std::endl;
	std::cout << "2. Print generated vectors" << std::endl;
	std::cout << "3. Exit" << std::endl;
}

void handleUserActions()
{
	int choice;

	Vector vectors;
	vectors.generateVectors();

	while (true)
	{
		menu();

		std::cin >> choice;

		switch (choice)
		{
		case 1:

			vectors.printFrequencyMatrix();
			break;

		case 2:
			vectors.printGeneratedVectors();
			break;

		case 3:
			std::cout << "EXIT\n";
			return;
		}
	}
}

int main()
{
	handleUserActions();
	return 0;
}