#pragma once
#include <new>
#include <iostream>

template<typename T>
class File
{
public:
	File();
	//File(const File&);
	~File();

	void enfiler(const T& elem);
	T defiler();

	int taille() const;
	bool estVide() const;
	bool estPleine() const;
	const T& premier();
	const T& dernier();

	const File<T>& operator = (const File<T>& _file) throw (std::bad_alloc);
	template <typename U>friend std::ostream& operator << (std::ostream& f, const File<U>& q);

private:
	int max;
	int size;
	int first, last;
	T* tab;
};

template<typename U>
inline std::ostream & operator<<(std::ostream & f, const File<U>& q)
{
	f << "taille : " << q.size << " max : " << q.max << std::endl;
	return f;
}
