#include "insertion.h"

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
test_insert()
{
	clock_t start;
	double duration;
	vector<int> v;

	gen_rand(v, 10000);
	// printvec(v);

	start = clock();
	algrthm::insert(v);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	cout << "total time sort:\t" << dec << duration << " s" << endl;

	// printvec(v);
}

int main(int argc, char const *argv[])
{
	test_insert();
	return 0;
}
