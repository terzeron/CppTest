#include <iostream>
#include <cstring>
#include <set>
#include <map>

using namespace std;

struct product {
    string name;
    string description;
    double price;
};

bool operator<(const product& p1, const product& p2) {
    return p1.name < p2.name;
}
ostream& operator<<(ostream& os, const product& p1) {
    os << "{ " << p1.name << ", " << p1.description << ", " << p1.price << " }";
    return os;
}

bool operator<(const product& p1, const string& str2) {
    return p1.name < str2;
}
bool operator<(const string& str1, const product& p2) {
    return str1 < p2.name;
}

int main(void) {
    set<product> products {
                           {"car", "this is a super car", 100000.0 },
                           { "ball", "a cheap but nice-looking ball", 100.0 },
                           { "orange", "fresh orange", 50.0}
    };
    auto it1 = products.find({"car", "", 0.0});
    if (it1 != products.end()) {
        cout << *it1 << endl;
    }
    
    // only in c++14
    set<product, less<>> products2 {
        {"car", "this is a super car", 100000.0 },
            { "ball", "a cheap but nice-looking ball", 100.0 },
                { "orange", "fresh orange", 50.0}
    };
    auto it2 = products2.find("ball");
    if (it2 != products2.end()) {
        cout << *it2 << endl;
    }
    
    return 0;
}
