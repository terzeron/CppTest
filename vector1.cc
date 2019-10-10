#include <iostream>
#include <vector>

using namespace std;

int
main ()
{
	vector < int >col1;

	for (int i = 1; i <= 6; ++i)
		col1.push_back (i);

	for (unsigned int i = 0; i < col1.size (); ++i)
		cout << col1[i] << ' ';

	cout << endl;

	return 0;
}
