#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list < int >col1;
    vector < int >col2;

    for (int i = 1; i <= 9; ++i)
	col1.push_back(i);

    copy(col1.begin(), col1.end(), col2.begin());	// segmentation fault

    return 0;
}
