#include <iostream>
#include <vector>
#include <ext/algorithm>

using namespace std;
using namespace __gnu_cxx;

int main(void)
{
    vector<int> a;
    for (int i = 0; i < 10; ++i) {
        a.push_back(i);
    }

    vector<int> b;
    b.resize(a.size() / 2);
    random_sample(a.begin(), a.end(), b.begin(), b.end());
    for (uint i = 0; i < b.size(); ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}

