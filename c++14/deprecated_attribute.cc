#include <iostream>

using namespace std;

[[deprecated]]
void test1(void)
{

}

[[deprecated("replaced by ...")]]
void test2(void)
{

}

int main(void)
{
    __attribute__((deprecated)) int a = 3;
    __attribute__((deprecated("deprecated for ..."))) int b = 4;
                  
    cout << a << endl;
    cout << b << endl;

    test1();
    test2();
    
    return 0;
}
