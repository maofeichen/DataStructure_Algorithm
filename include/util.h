#ifndef UTIL_H
#define UTIL_H 

#include <vector>

namespace algrthm{

template <typename T>
bool 
less(T& a, T& b)
{
	if(a < b)
		return true;
	else
		return false;
}

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

template <typename T>
bool 
is_sorted(std::vector<T>& v)
{
	for(auto it = v.begin()+1; it != v.end(); ++it) {
		if(less(*it, *(it-1) ) ) {
			return false;
		}
	}

	return true;
}

} // end algrthm

#endif