#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <class T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
	return ;
};

template <class T>
T min(T &a, T &b)
{
	return a < b ? a : b;
}

template <class T>
T max(T &a, T &b)
{
	return a > b ? a : b;
}

#endif