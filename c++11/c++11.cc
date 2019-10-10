//
// g++ c++11.cc -Wall -std=c++0x
//

// 한글

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    //
    // lambda expression
    //
    char s[]="Hello World!";
    int Uppercase = 0; //modified by the lambda
    for_each(s, s + sizeof(s), [&Uppercase] (char c) {
            if (isupper(c))
                Uppercase++;
        });
    cout << Uppercase<<" uppercase letters in: " << s << endl;

    // 
    // automatic type declaration
    //
    auto x=0; //x has type int because 0 is int
    auto c='a'; //char
    auto d=0.5; //double
    auto national_debt=14400000000000LL; //long long

    // decltype
    const vector<int> vi;
    typedef decltype (vi.begin()) CIT;
    CIT another_const_iterator;
 
    // 
    // Uniform Intialization Syntax
    //
    std::string s1("hello");
    int m = int(); //default initialization
    std::string s2 = "hello";
    int x1 = 5;

    int arr[4] = { 0, 1, 2, 3 };
    struct tm today = { 0 };

    struct S {
        int x;
        S(): x(0) { } 
    };

    class C {
        int a;
        int b;
    public:
        C(int i, int j) {
            a = i;
            b = j;
        };
    };
    C c1 { 0, 0 }; // C++11 only
    //C c1(0, 0);
    
    int* a = new int[3] { 1, 2, 0 }; // C++11 only

    class X {
        int a[4];
    public:
        X() : a { 1, 2, 3, 4 } { } // C++11
    };
}


void func(const vector<int> &vi)
{
    //vector<int>::const_iterator ci = vi.begin();
    auto ci = vi.begin();
}
