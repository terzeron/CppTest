#include <iostream>

using namespace std;

int* test(void)
{
    int a = 3;
    int* p = &a;

    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;

    int b = move(a);

    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;
    cout << "b=" << b << endl;

    // move한다고 바로 자원이 소멸되지 않다가
    // a가 scope을 벗어나면 자원이 소멸됨
    return p;
}

int main(void)
{
    int* p = test();
    cout << "*p=" << *p << endl;
    
    return 0;
}
