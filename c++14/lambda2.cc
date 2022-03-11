#include <iostream>

using namespace std;

int main(void)
{
    int x = 4;
    auto y = [&r = x, x = x+1]()->int {
                 // r = 4, x = 5
                 r += 2;
                 // r = 6
                 return x+2;
                 // return 7
             }();
    cout << x << endl;
    cout << y << endl;
}
