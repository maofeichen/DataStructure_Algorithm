#ifndef INSERTION_H
#define INSERTION_H

#include "util.h"
#include <vector>

namespace algrthm{

// insertion sort
template <typename T>
void insert(std::vector<T>& v)
{
	// not convinient
	// for(auto it = v.begin()+1; it != v.end(); ++it) {
	// 	uint64_t ofst = it - v.begin();
	// 	auto rit = v.rbegin() - (v.size() - 1 ) + ofst; 
	// 	for(; rit != v.rend(); ++rit) {
	// 	}
	// }

	for(auto i = 1; i < v.size(); i++) {
		for(auto j = i; j > 0; j--) {
			if(v[j-1] > v[j]) {
				swap(v[j-1], v[j]);
				// swap_inplace(v[j-1], v[j]);
			} else{
				break;
			}
		}
	}
}

} // end namespace
#endif