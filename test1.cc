#include <iostream>
#include <string.h>


using namespace std;


int main()
{
    char *p = new char[10];

    strcpy(p, "123456789");
    cout << p << endl;

    delete[] p;
    cout << p << endl;

    ++p;
    delete[] p;
    cout << p << endl;
    
    return 0;
}
