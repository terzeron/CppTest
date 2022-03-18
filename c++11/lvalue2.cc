#include <iostream>

using namespace std;

static int a = 10;

int& foo() {
    cout << "in foo(), a=" << a << endl;
    a++;
    cout << "in foo(), a=" << a << endl;
    return a;
}
        

int main(void)
{
    int a = 10;
    int b = 10;
    int c = 10;

    // lvalue는 identity를 가지지만 이동시킬 수 없음(기존 자원 메모리를 소멸시킬 수 없음)
    // 대입문의 왼쪽에 올 수 있음(lvalue에 대입 가능함)
    // &연산자로 주소를 얻어올 수 있음
    // 표현식이 끝나도 값이 살아 있음
    // ex)
    // 변수나 함수의 이름
    // lvalue reference를 반환하는 함수 호출이나 오버로드된 연산자 표현식
    // 내장 대입 연산식
    // 전위증감연산식
    // *p

    int *j = &a; // a는 lvalue
    cout << "*j=" << *j << endl;

    int& f= foo() = 43; // foo()는 lvalue
    cout << "f=" << f << endl;

    int *ptr1 = &foo(); // foo()는 lvalue
    cout << "*ptr1=" << *ptr1 << endl;

    ++a; // a는 lvalue
    cout << "a=" << a << endl;

    int arr[4] { 1, 2, 3, 4 }; 
    cout << "arr[1]=" << arr[1] << endl; // arr[1]도 lvalue

    cout << "a ? b : c =" << (a ? b : c) << endl; // a ? b : c도 lvalue
    
    return 0;
}
