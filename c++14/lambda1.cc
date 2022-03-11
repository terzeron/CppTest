#include <iostream>


using namespace std;


int main(void)
{
    // C++14부터 lambda에 auto type 사용
    // "function template"
    auto identity = [](auto a) { return a; };

    int three = identity(3);
    char const* hello = identity("hello");
    
    cout << three << endl;
    cout << hello << endl;

    // identity는 타입이 없지만 fpi나 fpc 등의 함수 포인터는 타입이 있음
    int (*fpi)(int) = identity;
    char (*fpc)(char) = identity;
    string (*fps)(string) = identity;

    cout << fpi(4) << endl;
    cout << fpc('w') << endl;
    cout << fps("world") << endl;

    return 0;
}
