#include <iostream>

using namespace std;

int main(void)
{
    union U {
        int a; double b;
    } u;
    cout << "&u=" << &u << endl;
    cout << "sizeof(u)=" << sizeof(u) << endl;

    void* x = &u;
    cout << "x=" << x << endl;
    cout << "sizeof(*x) is unknown" << endl;

    double* y = static_cast<double*>(x);
    cout << "y=" << y << endl;
    cout << "sizeof(*y)=" << sizeof(*y) << endl;
    
    char* z = static_cast<char*>(x);
    cout << "z=" << (void*) z << endl;
    cout << "sizeof(*z)=" << sizeof(*z) << endl;
    
    return 0;
}
