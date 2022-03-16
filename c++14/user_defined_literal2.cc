#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const long double km_per_mile = 1.609344L;
long double operator""_km(const long double val) {
    return val;
}
long double operator""_mi(const long double val) {
    return val * km_per_mile;
}

int main(void)
{
    cout << 36.7_km << endl;
    cout << 43.5_mi << endl;

    return 0;
}
