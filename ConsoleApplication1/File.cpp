#include "File.h"
#include <iostream>


template<typename T>
File<T>::File()
{
	max = 100;
	tab = new T[max];
	size = 0;
	first = 0;
	last = 0;
}

template<typename T>
File<T>::~File()
{
	delete[] tab;
}

template<typename T>
void File<T>::enfiler(const T& elem) {
	if (size<max) {
		tab[last] = elem;
		last = (last + 1) % max;
		size++;
	}
	else {
		//doubler la taille du tableau et augmenter max;
		int ancienMax = max;
		int j = 0;
		max = max * 2;
		T* newTab = new T[max];
		for (int i = 0; i < size; i++) {
			if ((first + i) <= ancienMax) {
				newTab[i] = tab[first + i];
			}
			else {
				newTab[i] = tab[j];
				j++;
			}
		}
		first = 0;
		last = ancienMax + 1;
		tab = newTab;
		tab[last - 1] = elem;
		size++;
	}
		
}
template<typename T>
T File<T>::defiler() {
	if (!estVide()) {
		T res = tab[first];
		first = (first + 1)%max;
		size--;
		return res;
	}
	throw "erreur file vide";
}

template<typename T>
int File<T>::taille() const {
	return size;
}

template<typename T>
bool File<T>::estVide() const
{
	return (0 == size);
}

template<typename T>
bool File<T>::estPleine() const {
	return ((size+1) == max);
}
template<typename T>
const T& File<T>::premier() {
	return tab[first];
}
template<typename T>
const T& File<T>::dernier() {
	return tab[last];
}

template<typename T>
const File<T>& File<T>::operator=(const File<T>& _file) throw(std::bad_alloc)
{
	try
	{
		File f;
		f.first = _file.first;
		f.last = _file.last;
		f.max = _file.max;
		f.size = _file.size;
		f.tab = _file.tab;
		return f;
	}
	catch (const std::bad_alloc& b)
	{
		std::cout << "bad_alloc" << std::endl;
	}
}


