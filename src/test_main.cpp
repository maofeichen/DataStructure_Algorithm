#include "insertion.h"

#include <iostream>
#include <vector>
#include "stdlib.h"
#include "time.h"

using namespace std;

void test_insert();
void gen_rand(vector<int>& v, int n);
void printvec(vector<int>& v);

int main(int argc, char const *argv[])
{
	test_insert();
	return 0;
}

void 
test_insert()
{
	vector<int> v;
	gen_rand(v, 100);
	printvec(v);
	insert(v);
	printvec(v);
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
printvec(vector<int>& v)
{
	cout << "total random number\t" << dec << v.size() << endl;
	for(int i = 0; i < v.size(); i++) {
		cout << dec << v[i] << " ";
		if(i != 0 && i % 16 == 0)
			cout << "\n";
	}	
	cout << "\n";
}