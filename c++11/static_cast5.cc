#include <iostream>

using namespace std;

int main(void)
{
    int n = static_cast<int>(3.14);

    // implicit conversion
    void* nv = &n;
    // inverse of implicit conversion
    int* ni = static_cast<int*>(nv);
    cout << "*ni=" << *ni << endl;

    return 0;
}
