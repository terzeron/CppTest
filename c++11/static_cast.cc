#include <iostream>
#include <typeinfo>

using namespace std;

int main(void)
{
    struct B { int i; };
    struct D : B { };
    cout << "sizeof(B)=" << sizeof(B) << endl;
    cout << "sizeof(D)=" << sizeof(D) << endl;

    D d;
    cout << "type(d)=" << typeid(d).name() << endl;
    cout << "&d=" << &d << endl;

    B& br = d;
    cout << "type(br)=" << typeid(br).name() << endl;
    cout << "&br=" << &br << endl;

    D& d1 = static_cast<D&>(br);
    cout << "type(d1)=" << typeid(d1).name() << endl;
    cout << "&d1=" << &d1 << endl;

    return 0;
}
