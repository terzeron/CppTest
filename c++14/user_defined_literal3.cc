#include <iostream>
#include <string>

using namespace std;

class Distance {
private:
    explicit Distance(long double val) : kilometers(val) {}
    friend Distance operator"" _km(long double val);
    friend Distance operator"" _mi(long double val);
    long double kilometers { 0 };
    
public:
    constexpr static long double km_per_mile = 1.609344L;
    long double get_kilometers() const {
        return kilometers;
    }
    Distance operator+(Distance other) {
        return Distance(get_kilometers() + other.get_kilometers());
    }
};
    
Distance operator""_km(long double val) {
    return Distance(val);
}
Distance operator""_mi(long double val) {
    return Distance(val * Distance::km_per_mile);
}
ostream& operator<<(ostream& os, const Distance& d) {
    os << d.get_kilometers() << "km";
    return os;
}

int main(void)
{
    Distance d = 36.0_mi + 42.0_km;
    cout << d << endl;
    
    return 0;
}
