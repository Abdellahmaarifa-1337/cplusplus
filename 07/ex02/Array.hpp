#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template<class T>
class Array 
{
	public:
	T *arr;
	unsigned int length;
	Array(){
		length = 0;
		arr =  new T[0];
		std::cout << "Default constructor called\n";
	};

	Array(unsigned int n)
	{
		length = n;
		arr = new T[n];
		unsigned int i = 0;
		while (i < n)
		{
			arr[i] = T();
			i++;
		}
	};

	Array (Array &arrcp)
	{
		arr = new T[arrcp.length];
		length = arrcp.length;
		unsigned int i = 0;
		while (i < length)
		{
			arr[i] = arrcp[i];
			i++;
		}
	};

	Array &operator=(Array &arrcp)
	{
		delete[] arr;
		arr = new T[arrcp.length];
		length = arrcp.length;
		unsigned int i = 0;
		while (i < length)
		{
			arr[i] = arrcp[i];
			i++;
		}
		return *this;
	};
	~Array(){
		delete[] arr;
	}

	T& operator[](unsigned int index)
	{
		if (index >= length)
		{
			throw OutOfRang();
		}
		return arr[index];
	};
	
	unsigned int size() const
	{
		return length;
	};

	class OutOfRang : public std::exception {
		const char* what() const throw(){return "ouf of range!";};
	};

};
#endif