#include <iostream>
#include <iomanip>

using namespace std;

template<typename T> constexpr T pi = T(3.141592653589732385);
// variable template을 이용하여 상수 파라미터의 사용을 단순화함
template<typename T> T area_of_circle_with_radius(T r) {
    return pi<T> * r * r;
}

int main(void)
{
    cout << setprecision(25);
    cout << area_of_circle_with_radius(1) << endl;
    cout << area_of_circle_with_radius((float) 1.10000000000000000002l) << endl;
    cout << area_of_circle_with_radius((double) 1.10000000000000000002l) << endl;
    cout << area_of_circle_with_radius((long double) 1.10000000000000000002L) << endl;
    cout << area_of_circle_with_radius(1.10000000000000000002f) << endl;
    cout << area_of_circle_with_radius(1.10000000000000000002) << endl;
    cout << area_of_circle_with_radius(1.10000000000000000002l) << endl;

    return 0;
}
