#pragma once
#include "Sequence.h"
#include "Sorts.h"
#include "Windows.h"

void Menu()
{
	int choise1;
	std::cout << "1. Sequence sorting\n" << "2. Time testing\n" << "Enter: ";
	std::cin >> choise1;
	Sleep(100);
	system("cls");

	if (choise1 == 1)
	{
		std::cout << "\n";
	}
	if (choise1 == 2)
	{
		std::cout << "\n";
	}
}