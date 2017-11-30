#ifndef UTIL_H
#define UTIL_H 

namespace algrthm{

template <typename T>
void 
swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;	
}

template <typename T>
void 
swap_inplace(T& a, T& b)
{
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}

}

#endif