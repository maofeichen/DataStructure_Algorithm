// insertion sort

#ifndef INSERTION_H
#define INSERTION_H

#include <vector>

// insertion sort
template <typename T>
void insert(std::vector<T>& v); 

template <typename T>
static void swap(T& a, T& b);
#endif