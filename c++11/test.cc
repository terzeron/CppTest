#include <iostream>
#include <vector>
#include <memory>

using namespace std;

vector<int> make_big_vector()
{
	return new vector<int>[1000];
}

int main()
{
	vector<int> result = make_big_vector();
	unique_ptr<int> p(new int);
	return 0;
}
