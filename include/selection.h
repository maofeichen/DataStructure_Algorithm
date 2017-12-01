#ifndef SELECTION_H
#define SELECTION_H

#include "util.h"
#include <vector>

namespace algrthm{
// selection sort
template <typename T>
void select(std::vector<T>& v)
{
	for(unsigned int i = 0; i < v.size(); i++) {
		T min = v[i];
		unsigned minidx = i;
		for(unsigned int j = i+1; j < v.size(); j++) {
			if(less(v[j], min) ) {
				min = v[j];
				minidx = j;
			}
		}

		if(less(min, v[i]) ) {
			swap(v[minidx], v[i]);
		}
	}
}

}

#endif