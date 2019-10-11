#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void)
{
    list<int> col1;
    list<int>::iterator pos;

    for (int i = 20; i <= 40; ++i)
        col1.push_back(i);


    pos = find(col1.begin(), col1.end(), 3);

    reverse(pos, col1.end());

    list<int>::iterator pos25, pos35;
    pos25 = find(col1.begin(), col1.end(), 25);
    pos35 = find(col1.begin(), col1.end(), 35);

    cout << "max: " << *max_element(pos25, pos35) << endl;

    cout << "max: " << *max_element(pos25, ++pos35) << endl;

    return 0;
}
