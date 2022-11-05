#include "Sequence.h"
#include "Sorts.h"
#include "Menu.h"
#include "Functions.h"


void qs(int* s_arr, int first, int last)
{
	int i = first, j = last, x = s_arr[(first + last) / 2];

	do {
		while (s_arr[i] < x) i++;
		while (s_arr[j] > x) j--;

		if (i <= j) {
			if (s_arr[i] > s_arr[j])
			{
				std::swap(s_arr[i], s_arr[j]);
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		qs(s_arr, i, last);
	if (first < j)
		qs(s_arr, first, j);
}

int bin_search(int* arr, int first, int last, int key)
{
	int left = first;
	int right = last;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > key)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	//int arr[5] = {9, 1, 1, 11, 48};
	//int arr[5] = { 0, 1, 1, 0, 48};
	int* arr = new int[5];
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		int k;
		k = rand();
		arr[i] = k;
	}
	//int arr[5] = { 1, 2, 3, 7, 10};
	//int p = bin_search(arr, 0, 4, 9);
	//std::cout << p << "\n";
	//Sequence<int>* seq1 = new ListSequence<int>(arr, 5);
	//seq1->Print_line();

	//qs(arr, 0, 4);
	
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


	/*
	Sequence<int>* seq = new ArraySequence<int>(arr, 5);
	seq->Print_line();
	Sequence<int>* seq1 = SortHub(seq, increase, 1);
	seq1->Print_line();*/
	/*
	seq = Sorts[0]->Sort(seq, increase);
	seq->Print_line();
	seq = Sorts[2]->Sort(seq, decrease);
	seq->Print_line();*/

	Menu();
	return 0;
}
