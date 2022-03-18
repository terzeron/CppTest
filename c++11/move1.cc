#include <iostream>
#include <vector>
#include <chrono>
#include <sys/time.h>
#include <ctime>
#include <cstring>

using namespace std;
using namespace std::chrono;

class temp {
    string s;
    int p;

public:
    temp(string d, int x) {
        s = d;
        p = x;
    }
};

int main(void)
{
    vector<temp> v1;
    vector<temp> v2;

    for (auto i = 0; i < 10000000; ++i) {
        temp t("hello", i);
        v1.push_back(t);
    }

    for (auto i = 0; i < 10000000; ++i) {
        temp t("world", i);
        v2.push_back(t);
    }

    auto t1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    cout << t1 << endl;

    //v2 = v1;
    v2 = move(v1);

    auto t2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    cout << t2 << endl;

    cout << t2 - t1 << endl;

    return 0;
}
