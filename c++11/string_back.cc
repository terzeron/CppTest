#include <iostream>

using namespace std;

int main(void)
{
    string str = "hello world";
    cout << "str.back()=" << str.back() << endl;

    str.back() = 'f';
    cout << "str=" << str << endl;

    return 0;
}
