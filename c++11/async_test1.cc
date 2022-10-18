#include <future>
#include <thread>
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    future<long long> f = async([](int a, int b) { return (long long) pow(a, b); }, 2, 9);
    cout << f.get() << endl;
    return 0;
}
