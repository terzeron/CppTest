#include <string.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <iostream>


using namespace std;


int main(void)
{
    vector<int> v;
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
