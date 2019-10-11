#include <iostream>
#include <string>
#include <map>

using namespace std;

class cmp {
public:
    bool operator () (const string & s1, const string & s2) const {
        return lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
                                       s2.end());
    }};

typedef map<string, int> str1_map_t;
typedef map<string, int, less<string>> str2_map_t;
typedef map<string, int, cmp> str3_map_t;

int main(void)
{
    str1_map_t map1;
    str2_map_t map2;
    str3_map_t map3;

    string str[] = { "ba", "a", "aa", "aaa", "aahg", "b", "aa", "a" };

    for (unsigned int i = 0; i < sizeof(str) / sizeof(str[0]); ++i) {
        map1.insert(make_pair(str[i], 1));
        map2.insert(make_pair(str[i], 1));
        map3.insert(make_pair(str[i], 1));
    }

    str1_map_t::iterator iter1;
    str2_map_t::iterator iter2;
    str3_map_t::iterator iter3;

    for (iter1 = map1.begin(); iter1 != map1.end(); ++iter1) {
        cout << iter1->first << endl;
    }
    cout << endl;

    for (iter2 = map1.begin(); iter2 != map1.end(); ++iter2) {
        cout << iter2->first << endl;
    }
    cout << endl;
    for (iter3 = map1.begin(); iter3 != map1.end(); ++iter3) {
        cout << iter3->first << endl;
    }


    return 0;
}
