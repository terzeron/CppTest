#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string str1 = "hello";
    string str2 = "world";
    vector<string> v;

    v.push_back(str1);
    cout << "str1=" << str1 << endl;
    
    v.push_back(move(str2));
    cout << "str2=" << str2 << endl;
    cout << "str2.length()=" << str2.length() << endl;

    cout << "v[0]=" << v[0] << ", v[1]=" << v[1] << endl;
    
    return 0;
}
