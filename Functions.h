#pragma once
#include <vector>

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



void Timeing(int code)
{

}