#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v0 { 1, 2, 3 };
    cout << "v0.size()=" << v0.size() << endl;
    // move lvalue to xvalue
    // 신규 타입이 rvalue reference라면(여기서는 vector&&)
    // static_cast가 glvalue, class prvalue, array prvalue, lvalue의 값을
    // 같은 객체를 참조하는 xvalue로 변환함
    vector<int> v2 = static_cast<vector<int>&&>(v0);
    cout << "v0.size()=" << v0.size() << endl;
    cout << "v2.size()=" << v2.size() << endl;

    return 0;
}
