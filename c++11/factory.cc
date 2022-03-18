#include <iostream>
#include <memory>

using namespace std;

template <typename T, typename Arg>
// lvalue와 rvalue를 모두 받으려면 Arg&&로 선언되어야 함
shared_ptr<T> factory(Arg&& arg) {
    return shared_ptr<T>(new T(std::forward<Arg>(arg)));
}

int my_func(void)
{
    return 4;
}

int main(void)
{
    
    shared_ptr<int> p1 = factory<int, int>(3);
    cout << "p1=" << p1 << endl;
    cout << "*p1=" << *p1 << endl;

    shared_ptr<int> p2 = factory<int, int>(my_func());
    cout << "p2=" << p2 << endl;
    cout << "*p2=" << *p2 << endl;

    return 0;
}
