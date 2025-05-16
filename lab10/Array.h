#pragma once

#include <exception>
#include <iostream>
using namespace std;

class Compare
{
public:
	virtual int CompareElements(const void* e1, const void* e2) = 0;
};

class Compara2 : public Compare
{
public:
	int CompareElements(const void* e1, const void* e2)
	{
		int* n1 = (int*)e1;
		int* n2 = (int*)e2;

		if (*n1 == *n2)
			return 0;
		if (*n1 < *n2)
			return -1;
		return 1;
	}
};

class exceptie1 : public exception
{
	virtual const char* what() const throw()
	{
		return "Index out of range";
	}
};

template<class T>
class ArrayIterator
{
private:
	int Current;
public:
	T** element;
	ArrayIterator()
	{
		element = nullptr;
	}
	ArrayIterator& operator ++ (int value)
	{
		element++;
		return (*this);
	}
	ArrayIterator& operator -- ()
	{
		element--;
		return (*this);
	}
	ArrayIterator<T>& operator= (const ArrayIterator<T>& other)
	{
		element = other.element;
		return (*this);
	}
	bool operator!=(const ArrayIterator<T>& other)
	{
		return element != other.element;
	}

	T* GetElement()
	{
		return *element;
	}
};
template<class T>
class Array
{
private:
	T** List;
	int Capacity;
	int Size;
public:
	Array();
	~Array();
	Array(int capacity);
	Array(const Array<T>& otherArray);

	T& operator[] (int index);

	const Array<T>& operator+=(const T& newElem);
	const Array<T>& Insert(int index, const T& newElem);
	const Array<T>& Insert(int index, const Array<T> otherArray);
	const Array<T>& Delete(int index);

	void operator=(const Array<T>& otherArray);

	void Sort();
	void Sort(int(*compare)(const T&, const T&));
	void Sort(Compare* comparator);


	int BinarySearch(const T& elem);
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));
	int BinarySearch(const T& elem, Compare* comparator);

	int Find(const T& elem);
	int Find(const T& elem, int(*compare)(const T&, const T&));
	int Find(const T& elem, Compare* comparator);

	int GetSize();
	int GetCapacity();

	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();
};


template <class T>
Array<T>::Array()
{
	Size = 0;
	Capacity = 100;
	List = new T * [100];
}

template <class T>
Array<T>::~Array()
{
	for (int i = 0; i < Size; i++)
		delete List[i];
	delete[] List;

}

template <class T>
Array<T>::Array(int capacity)
{
	Capacity = capacity;
	Size = 0;
	List = new T * [capacity];
}

template <class T>
Array<T>::Array(const Array<T>& otherArray)
{
	Capacity = otherArray.Capacity;
	Size = otherArray.Size;
	List = new T * [Capacity];
	for (int i = 0; i < Size; i++)
	{
		List[i] = new T;
		(*List[i]) = (*(otherArray.List[i]));
	}
}

template<class T>
T& Array<T>::operator[] (int index)
{
	exceptie1 exceptie;
	try
	{
		if (index < 0 || index >= Size)
			throw exceptie;
		return *List[index];
	}
	catch (exception& exceptie)
	{
		cout << "Exceptie: " << exceptie.what() << '\n' << "se returneaza in loc primul element ";
		return *List[0];
	}
}

template<class T>
const Array<T>& Array<T>::operator+=(const T& newElem)
{
	if (Size >= Capacity)
	{
		T** aux;
		aux = List;
		List = new T * [Capacity + 7];
		Capacity += 7;
		for (int i = 0; i < Size; i++)
			List[i] = aux[i];
		delete[] aux;
	}
	List[Size] = new T;
	*(List[Size]) = newElem;
	Size++;
	return (*this);
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
	exceptie1 index_out_of_range;
	try
	{
		if (index < 0 || index >= Size)
			throw index_out_of_range;
	}
	catch (exception& e)
	{
		cout << "Exceptie: " << e.what() << '\n';
		return (*this);
	}

	if (Size >= Capacity)
	{
		T** aux;
		aux = List;
		List = new T * [Capacity + 7];
		Capacity += 7;
		for (int i = 0; i < Size; i++)
			List[i] = aux[i];
		delete[] aux;
	}

	for (int i = Size; i > index; i--)
	{
		List[i] = List[i - 1];
	}
	List[index] = new T;
	*List[index] = newElem;
	Size++;
	return (*this);
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	int newSize = Size + otherArray.Size;
	exceptie1 index_out_of_range;
	try
	{
		if (index < 0 || index >= Size)
			throw index_out_of_range;
	}
	catch (exception& e)
	{
		cout << "Exceptie: " << e.what() << '\n';
		return (*this);
	}

	int auxS = Size - 1;
	if (Size + otherArray.Size > Capacity)
	{
		T** aux;
		aux = List;
		List = new T * [Size + otherArray.Size];
		Capacity = Size + otherArray.Size;
		for (int i = 0; i < Size; i++)
			List[i] = aux[i];
		delete[] aux;
	}

	for (int i = Size + otherArray.Size - 1; i >= index + otherArray.Size; i--)
	{
		List[i] = List[auxS--];
	}

	for (int i = 0; i < otherArray.Size; i++)
	{
		List[index] = new T;
		*List[index] = *otherArray.List[i];
		index++;
	}
	Size = newSize;
	return (*this);
}

template<class T>
const Array<T>& Array<T>::Delete(int index)
{
	exceptie1 index_out_of_range;
	try
	{
		if (index < 0 || index >= Size)
			throw index_out_of_range;
	}
	catch (exception& e)
	{
		cout << "Exceptie: " << e.what() << '\n';
		return (*this);
	}

	delete List[index];
	for (int i = index; i < Size - 1; i++)
	{
		List[i] = List[i + 1];
	}

	Size--;
	return (*this);
}

template<class T>
void Array<T>::operator=(const Array<T>& otherArray)
{
	for (int i = 0; i < Size; i++)
		delete List[i];
	delete[]List;

	Capacity = otherArray.Capacity;
	Size = otherArray.Size;
	List = new T * [Capacity];
	for (int i = 0; i < Size; i++)
	{
		List[i] = new T;
		(*List[i]) = (*(otherArray.List[i]));
	}
}

template<class T>
void Array<T>::Sort()
{
	bool sortat = 1;
	do
	{
		sortat = 1;
		for (int i = 0; i < Size - 1; i++)
		{
			if ((*List[i]) > (*List[i + 1]))
			{
				sortat = 0;
				T* aux = List[i];
				List[i] = List[i + 1];
				List[i + 1] = aux;
			}
		}
	} while (!sortat);
}

template<class T>
void Array<T>::Sort(int(*compare)(const T&, const T&))
{
	bool sortat = 1;
	do
	{
		sortat = 1;
		for (int i = 0; i < Size - 1; i++)
		{
			if (compare((*List[i]), (*List[i + 1])) > 0)
			{
				sortat = 0;
				T* aux = List[i];
				List[i] = List[i + 1];
				List[i + 1] = aux;
			}
		}
	} while (!sortat);
}

template<class T>
void Array<T>::Sort(Compare* comparator)
{
	bool sortat = 1;
	do
	{
		sortat = 1;
		for (int i = 0; i < Size - 1; i++)
		{
			if (comparator->CompareElements(List[i], List[i + 1]) > 0)
			{
				sortat = 0;
				T* aux = List[i];
				List[i] = List[i + 1];
				List[i + 1] = aux;
			}
		}
	} while (!sortat);
}

template <class T>
int Array<T>::BinarySearch(const T& elem)
{
	Sort();
	int st = 0, dr = Size - 1;
	while (st <= dr)
	{
		int m = (st + dr) / 2;
		if ((*List[m]) == elem)
			return m;
		if ((*List[m]) > elem)
			dr = m - 1;
		else st = m + 1;
	}
	return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
	Sort(compare);
	int st = 0, dr = Size - 1;
	while (st <= dr)
	{
		int m = (st + dr) / 2;
		if (compare((*List[m]), elem) == 0)
			return m;
		if (compare((*List[m]), elem) > 0)
			dr = m - 1;
		else st = m + 1;
	}
	return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
	Sort(comparator);
	int st = 0, dr = Size - 1;
	while (st <= dr)
	{
		int m = (st + dr) / 2;
		if (comparator->CompareElements(List[m], &elem) == 0)
			return m;
		if (comparator->CompareElements(List[m], &elem) > 0)
			dr = m - 1;
		else st = m + 1;
	}
	return -1;
}

template<class T>
int Array<T>::Find(const T& elem)
{
	for (int i = 0; i < Size; i++)
		if (*List[i] == elem)
			return i;
	return -1;
}

template<class T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
	for (int i = 0; i < Size; i++)
		if (compare((*List[i]), elem) == 0)
			return i;
	return -1;
}

template<class T>
int Array<T>::Find(const T& elem, Compare* comparator)
{
	for (int i = 0; i < Size; i++)
		if (comparator->CompareElements(List[i], &elem) == 0)
			return i;
	return -1;
}

template<class T>
int Array<T>::GetCapacity()
{
	return Capacity;
}


template<class T>
int Array<T>::GetSize()
{
	return Size;
}

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
	ArrayIterator<T> it;
	it.element = &List[0];
	return it;
}

template<class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
	ArrayIterator<T> it;
	it.element = &List[Size];
	return it;
}
