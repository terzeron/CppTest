#include <iostream>
#include <vector>
#include <memory>
#include <string.h>

using namespace std;


vector<int>* make_big_vector()
{
	return new vector<int>[1000];
}


int main()
{
	vector<int>* result = make_big_vector();
    cout << result << endl;
	unique_ptr<int> p(new int);
    cout << *p << endl;
    
	return 0;
}
