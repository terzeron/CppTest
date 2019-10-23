#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


using namespace std;


int main(void)
{
    vector<int> a;
    for (int i = 0; i < 20; ++i) {
        cout << i << " ";
        a.push_back(i);
    }
    cout << endl;

    vector<int> b;
    b.resize(a.size() / 2);

    //random_sample(a.begin(), a.end(), b.begin(), b.end());

    // mt19937 is uniform pseudo random generator
    sample(a.begin(), a.end(), b.begin(), a.size() / 2, mt19937{ random_device{}() });
    
    for (uint i = 0; i < b.size(); ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
