#pragma once
#include <vector>
#include <chrono>

//template<class T> T max(T value1, T value2)
//{
//	if (value1 >= value2) { return value1 }
//	else { return value2 }
//}
template <typename T>
Sequence<T>* SortHub(Sequence<T>* seq, int (*cmp)(T, T), int sort_number)
{
	std::vector<ISorter<T>*> Sorts;
	for (int i = 0; i < 5; i++)
	{
		if (i + 1 == 1)
		{
			Sorts.push_back(new BubbleSort<T>);
		}
		if (i + 1 == 2)
		{
			Sorts.push_back(new InsertSort<T>);
		}
		if (i + 1 == 3)
		{
			Sorts.push_back(new BinInsertSort<T>);
		}
		if (i + 1 == 4)
		{
			Sorts.push_back(new HeapSort<T>);
		}
		if (i + 1 == 5)
		{
			Sorts.push_back(new QuickSort<T>);
		}
	}

	seq = Sorts[sort_number]->Sort(seq, cmp);
	return seq;
}
void elem_generation(int& elem)
{
	elem = rand();
}

void elem_generation(double& elem)
{
	elem = (double)(rand()) / RAND_MAX * 100000;
}

template <typename T> 
void generation(int creation, T* arr, int size)
{
	if (creation == 1)
	{
		for (int i = 0; i < size; i++)
		{
			T k;
			std::cin >> k;
			arr[i] = k;
		}
	}
	else
	{
		srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			T k;
			elem_generation(k);
			arr[i] = k;
		}
	}
}



template <typename T>
void Timeing(int code, std::vector<ISorter<T>*> Sorts)
{
	int i;
	while (code > 0)
	{
		i = code % 10;
		code = code / 10;





		auto start = std::chrono::high_resolution_clock::now();



		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;








	}




	
}