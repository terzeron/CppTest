#include <iostream>

using namespace std;

int main(void)
{
    // xvalue(expiring value)는 identity를 가지면서 move될 수 있음
    // ex)
    // rvalue reference를 반환하는 함수 호출이나 오버로드된 연산자 표현식
    // a[n]

    string s = "hello";
    string m = move(s);
    cout << "m=" << m << endl;
    cout << "s=" << s << endl;
    
    return 0;
}
