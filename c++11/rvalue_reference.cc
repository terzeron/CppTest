#include <iostream>

using namespace std;


class X {
public:
    int p;
    X(int i): p(i) { };
};

// lvalue reference
void foo(X& x) {
    cout << "in foo(X& x)" << endl;
    cout << "x.p=" << x.p << endl;
    x.p = 50;
    cout << "after assignment" << endl;
    cout << "x.p=" << x.p << endl;
}

// rvalue reference 
void foo(X&& x) {
    cout << "in foo(X&& x)" << endl;
    cout << "x.p=" << x.p << endl;
    x.p = 70;
    cout << "after assignment" << endl;
    cout << "x.p=" << x.p << endl;
}

void foo_const(X const& x) {
    cout << "in foo_const(X const& x)" << endl;
    cout << "x.p=" << x.p << endl;
    //x.p = 70; // error
    //cout << "after assignment" << endl;
    //cout << "x.p=" << x.p << endl;
}

X foobar()
{
    X x { 3 } ;
    return x;
}
    
int main(void)
{
    X x(4);

    foo(x);
    foo(foobar());

    foo_const(x);
    foo_const(foobar());
    
    return 0;
}
