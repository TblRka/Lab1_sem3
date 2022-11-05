#pragma once
#include "Sequence.h"
#include "Sorts.h"
#include "Windows.h"

void Timeing(int code)
{

}

void Menu()
{
	int choise1 = 0;
	while (choise1 != 3)
	{
		std::cout << "1. Sequence sorting\n" << "2. Time testing\n" << "3. Escape\n" << "Enter: ";
		std::cin >> choise1;

		Sleep(10);
		system("cls");

		switch (choise1)
		{
			case 1:
				int choise21;
				std::cout << "Choose datatype: \n" << "1. Int\n" << "2. Float\n" << "3. Student\n";
				std::cin >> choise21;

				Sleep(10);
				system("cls");

				break;
		
			case 2:
				int choise22;
				std::cout << "Choose sorts: \n" << "1. Bubble sort\n" << "2. Insert sort\n" << "3. Bin insert sort\n" << "4. Heap sort\n" << "5. Quick sort\n";
				std::cout << "Enter a number consisting of digits, selected sorts:";
				std::cin >> choise22;

				Sleep(10);
				system("cls");

				Timeing(choise22);

				break;

		}
	}

}