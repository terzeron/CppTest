#include <string.h>
#include <algo.h>		// sort
#include <vector.h>
#include <stdlib.h>
#include <iostream.h>

int main(void)
{
    vector < int >v;
    int input;

    while (cin >> input) {
	v.push_back(input);
    }

    sort(v.begin(), v.end());

    for (int i = 0, n = v.size(); i < n; i++) {
	cout << v[i] << endl;
    }

    return 0;
}
