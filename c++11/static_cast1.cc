#include <iostream>
#include <typeinfo>

using namespace std;

int main(void)
{
    struct B {
        int m = 42;
        const string hello() const
        {
            return "hello world, this is B!";
        }    
    };
    struct D : B {
        const string hello() const
        {
            return "hello world, this id D!";
        }
    };
    cout << "sizeof(B)=" << sizeof(B) << endl;
    cout << "sizeof(D)=" << sizeof(D) << endl;
    cout << endl;

    D d;
    cout << "type(d)=" << typeid(d).name() << endl;
    cout << "&d=" << &d << endl;
    cout << d.hello() << endl << endl;

    B& br = d;
    cout << "type(br)=" << typeid(br).name() << endl;
    cout << "&br=" << &br << endl;
    cout << br.hello() << endl << endl;

    // downcast
    D& d1 = static_cast<D&>(br);
    cout << "type(d1)=" << typeid(d1).name() << endl;
    cout << "&d1=" << &d1 << endl;
    cout << d1.hello() << endl << endl;

    return 0;
}
