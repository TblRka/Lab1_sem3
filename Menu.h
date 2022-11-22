#pragma once
#include "Sequence.h"
#include "Sorts.h"
#include "Windows.h"
#include "Functions.h"
#include <fstream>




void Menu()
{
	std::vector<ISorter<int>*> Sorts;
	for (int i = 0; i < 5; i++)
	{
		if (i + 1 == 1)
		{
			Sorts.push_back(new BubbleSort<int>);
		}
		if (i + 1 == 2)
		{
			Sorts.push_back(new InsertSort<int>);
		}
		if (i + 1 == 3)
		{
			Sorts.push_back(new BinInsertSort<int>);
		}
		if (i + 1 == 4)
		{
			Sorts.push_back(new HeapSort<int>);
		}
		if (i + 1 == 5)
		{
			Sorts.push_back(new QuickSort<int>);
		}
	}

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
				int choise21, creation, size;
				std::cout << "Choose datatype: \n" << "1. Int\n" << "2. Float\n" << "3. Student\n";
				std::cin >> choise21;

				std::cout << "Way to create: \n" << "1. Console import\n" << "2. Random generation\n";
				std::cin >> creation;

				std::cout << "Enter size: ";
				std::cin >> size;

				Sleep(10);
				system("cls");



				int sort, comparator;
				switch (choise21)
				{
					case 1: //int
					{
						int* arr = new int[size];
						generation(creation, arr, size);
						Sequence<int>* seq = new ArraySequence<int>(arr, size);

						std::cout << "Choose sort: \n" << "1. Bubble sort\n" << "2. Insert sort\n" << "3. Bin insert sort\n" << "4. Heap sort\n" << "5. Quick sort\n";
						std::cin >> sort;
						std::cout << "Choose comparator:\n" << "1. Increase cmp\n" << "2. Decrease cmp\n";
						std::cin >> comparator;
						Sleep(10);
						system("cls");
						if (comparator == 1) 
						{
							seq = SortHub(seq, increase, sort - 1);
						}
						else
						{
							seq = SortHub(seq, decrease, sort - 1);
						}
						std::cout << "Result: ";
						seq->Print_line();
						std::cout << "\n";
						break;
					}

					case 2: //float
					{
						double* arr = new double[size];
						generation(creation, arr, size);

						Sequence<double>* seq = new ArraySequence<double>(arr, size);

						std::cout << "Choose sort: \n" << "1. Bubble sort\n" << "2. Insert sort\n" << "3. Bin insert sort\n" << "4. Heap sort\n" << "5. Quick sort\n";
						std::cin >> sort;
						std::cout << "Choose comparator:\n" << "1. Increase cmp\n" << "2. Decrease cmp\n";
						std::cin >> comparator;
						Sleep(10);
						system("cls");

						if (comparator == 1)
						{
							seq = SortHub(seq, increase, sort - 1);
						}
						else
						{
							seq = SortHub(seq, decrease, sort - 1);
						}
						std::cout << "Result: ";
						seq->Print_line();
						std::cout << "\n";
						break;
					}
				}

				break;
		
			case 2:
				int choise22, stop, step;
				std::cout << "Choose sorts: \n" << "1. Bubble sort\n" << "2. Insert sort\n" << "3. Bin insert sort\n" << "4. Heap sort\n" << "5. Quick sort\n";
				std::cout << "Enter a number consisting of digits, selected sorts:";
				std::cin >> choise22;
				std::cout << "Enter stop point: ";
				std::cin >> stop;
				std::cout << "Enter step: ";
				std::cin >> step;
				Sleep(10);
				system("cls");

				int points = stop / step;
				float** timeing = new float* [5];
				timeing = TimesBase(points, Sorts, choise22, step);

				/* простой вывод массива
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < points; j++)
					{
						std::cout << timeing[i][j] << " ";
					}
					std::cout << "\n";
				}
				

				// вывод в файл
				std::ofstream fout;
				fout.open("input.txt");
				
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < points; j++)
					{
						std::cout << timeing[i][j] << " ";
					}
					std::cout << "\n";
				}

				fout.close();*/

				break;

		}
	}

}