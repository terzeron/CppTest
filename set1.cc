#include <iostream>
#include <set>

using namespace std;

int main()
{
    typedef set<int> IntSet;
    IntSet col1;

    col1.insert(3);
    col1.insert(1);
    col1.insert(5);
    col1.insert(4);
    col1.insert(1);
    col1.insert(6);
    col1.insert(2);

    IntSet::const_iterator pos;
    for (pos = col1.begin(); pos != col1.end(); ++pos)
        cout << *pos << ' ';
    cout << endl;

    return 0;
}
