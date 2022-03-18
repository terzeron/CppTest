#include <iostream>

using namespace std;

template <typename T>
void my_swap1(T& a, T& b)
{
    // copy operator에 의존하면
    // lhs를 가리키고 있던 기존 리소스를 소멸시키고
    // 리소스를 임시로 복제한 버전이 생성되고
    // lhs가 새로운 버전을 가리키고
    // 임시로 생성한 리소스는 소멸됨
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void my_swap2(T& a, T& b)
{
    // move operator에 의존하면
    // lhs와 rhs를 맞바꿈
    T tmp = move(a);
    a = move(b);
    b = move(tmp);
}

int main(void)
{
    int a = 3;
    int b = 4;
    
    my_swap1(a, b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    my_swap2(a, b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    
    return 0;
}
