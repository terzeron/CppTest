#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n = static_cast<int>(3.14);
    cout << "n=" << n << endl;
    vector<int> v = static_cast<vector<int>>(10);
    cout << "v.size()=" << v.size() << endl;
    
    return 0;
}
