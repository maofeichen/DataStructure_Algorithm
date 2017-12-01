#include "insertion.h"
#include "selection.h"
#include "util.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void 
printvec(vector<int>& v)
{
	cout << "total random number\t" << dec << v.size() << endl;
	for(unsigned int i = 0; i < v.size(); i++) {
		cout << dec << v[i] << " ";
		if(i != 0 && i % 16 == 0)
			cout << "\n";
	}	
	cout << "\n";
}

void 
gen_rand(vector<int>& v, int n)
{
	srand (time(NULL));
	for(int i = 0; i < n; i++) {
		int b = rand() % 1000 + 1;
		v.push_back(b);
	}
}

void 
test_sort()
{
	clock_t start;
	double duration;

	vector<int> v;
	gen_rand(v, 20000);
	// printvec(v);

	vector<int> v1(v);
	vector<int> v2(v);

	// test insertion
	start = clock();
	algrthm::insert(v1);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	cout << "total time sort:\t" << dec << duration << " s" << endl;

	if(algrthm::is_sorted(v1) ) {
		cout << "vector is sorted" << endl;
	} else {
		cout << "vector is not sorted" << endl;
	}

	// test selection 
	start = clock();
	algrthm::select(v2);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	cout << "total time sort:\t" << dec << duration << " s" << endl;

	if(algrthm::is_sorted(v2) ) {
		cout << "vector is sorted" << endl;
	} else {
		cout << "vector is not sorted" << endl;
	}
	// printvec(v);
}

int main(int argc, char const *argv[])
{
	test_sort();
	return 0;
}
