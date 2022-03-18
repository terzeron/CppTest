#include <iostream>

using namespace std;

int main(void)
{
    // prvalue(pure rvalue)는 대입문의 오른쪽에 위치하며 주소가 없음
    // (문자열을 제외한) 리터럴
    // reference가 아닌 값을 반환하는 함수 호출이나 오버로드된 연산자 표현식
    // ex)
    // 후위증감연산식
    // 내장 연산식 (산술, 로직, 비교, &var) 
    
    int a = 10;
    int b = 20;

    a++;
    a+b;

    if (a < b) {

    }
    
    return 0;
}
