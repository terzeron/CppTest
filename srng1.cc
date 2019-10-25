#include <iostream>
#include <random>

using namespace std;

int main(void)
{
    subtractive_rng rng1;

    for (int i = 0; i < 10; ++i) {
        cout << rng1(10) << " ";
    }
    cout << endl;

    subtractive_rng rng2(5);
    for (int i = 0; i < 10; ++i) {
        cout << rng2(10) << " ";
    }
    cout << endl;

    return 0;
}
