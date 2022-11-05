#pragma once
#include "Sequence.h"

template <class T> int increase(T elem1, T elem2)
{
	if (elem2 > elem1)  return 0 ;
	else  return 1 ;
}

template <class T> int decrease(T elem1, T elem2)
{
	if (elem2 < elem1) return 0;
	else  return 1;
}



template <class T> class ISorter
{
public:


	virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T, T)) = 0;	
};

template <class T> class BubbleSort : public ISorter<T>
{
public:
	BubbleSort() {};
	~BubbleSort() {};

	virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T, T)) override
	{
		int len = seq->GetLength();
		for (int i = 0; i < len - 1; i++)
		{
			for (int j = 0; j < len - 1; j++)
			{
				if (cmp(seq->Get(j), seq->Get(j + 1)) == 1)
				{
					seq->Swap(j, j + 1);
				}
			}
		}
		return seq;
	}
};

template <class T> class  HeapSort: public ISorter<T>
{
public:
	HeapSort() {};
	~HeapSort() {};

	void Heapify(Sequence<T>* seq, int n, int i, int (*cmp)(T, T))
	{
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < n && cmp(seq->Get(largest), seq->Get(l)) == 0)
		{
			largest = l;
		}
		if (r < n && cmp(seq->Get(largest), seq->Get(r)) == 0)
		{
			largest = r;
		}

		if (largest != i)
		{
			//seq->Print_line();
			seq->Swap(i, largest);
			//std::cout << i << " \n";
			//seq->Print_line();
			Heapify(seq, n, largest, cmp);
		}
	}

	virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T, T)) override
	{
		int n = seq->GetLength();
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			Heapify(seq, n, i, cmp);
		}

		for (int i = n - 1; i > 0; i--)
		{
			seq->Swap(0, i);

			Heapify(seq, i, 0, cmp);
		}
		return seq;
	}
};

template <class T> class QuickSort : public ISorter<T>
{
public:
	QuickSort() {};
	~QuickSort() {};

	void QS(Sequence<T>* seq, int left, int right, int (*cmp)(T, T))
	{
		int i = left;
		int j = right;
		int temp = seq->Get((left + right) / 2);

		while (i <= j)
		{
			while (cmp(seq->Get(i),temp) == 0) i++;
			while (cmp(temp, seq->Get(j)) == 0) j--;

			if (i <= j)
			{
				if (cmp(seq->Get(j),seq->Get(i)) == 0)
				{

					seq->Swap(i, j);

				}
				i++;
				j--;
			}
		}

		if (i < right) QS(seq, i, right, cmp);
		if (left < j) QS(seq, left, j, cmp);

	}

	virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T, T)) override
	{
		int right = seq->GetLength() - 1;
		int left = 0;
		QS(seq, left, right, cmp);
		return seq;
	}
};

template <class T> class InsertSort : public ISorter<T>
{
public:
	InsertSort() {};
	~InsertSort() {};

	virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T, T)) override
	{
		for (int i = 1; i < seq->GetLength(); i++)
		{
			int j = i - 1;
			while (j >= 0 && cmp(seq->Get(j + 1), seq->Get(j)) == 0)
			{
				seq->Swap(j + 1, j);
				j--;
			}
		}
		return seq;
	}
 };

template <class T> class BinInsertSort : public ISorter<T>
{
public:
	BinInsertSort() {};
	~BinInsertSort() {};

	int BinSearch(Sequence<T>* seq, int index1, int index2, T key, int (*cmp)(T, T))
	{
		int left = index1;
		int right = index2;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (cmp(key, seq->Get(mid)) == 0)
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

	virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T, T)) override
	{
		for (int i = 1; i < seq->GetLength(); i++)
		{
			int temp = BinSearch(seq, 0, i, seq->Get(i), cmp);
			for (int j = i - 1; j >= temp; j--)
			{
				seq->Swap(j, j + 1);
			}
		}
		return seq;
	}
};