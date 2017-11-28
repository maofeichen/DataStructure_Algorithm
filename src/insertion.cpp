#include "insertion.h"

using namespace std;

// template <typename T>
// void 
// insert(std::vector<T>& v)
// {
// 	// not convinient
// 	// for(auto it = v.begin()+1; it != v.end(); ++it) {
// 	// 	uint64_t ofst = it - v.begin();
// 	// 	auto rit = v.rbegin() - (v.size() - 1 ) + ofst; 
// 	// 	for(; rit != v.rend(); ++rit) {
// 	// 	}
// 	// }

// 	for(int i = 1; i < v.size(); i++) {
// 		for(int j = i; j >=0; j--) {
// 			if(v[j-1] > v[j]) {
// 				swap(v[j-1], v[j]);
// 			}
// 		}
// 	}
// }

// template <typename T>
// static void 
// swap(T& a, T& b)
// {
// 	T t = a;
// 	a = b;
// 	b = t;	
// }