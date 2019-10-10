#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    deque < float >col1;

    for (int i = 1; i <= 6; ++i)
	col1.push_front(i * 1.1);

    for (unsigned int i = 0; i < col1.size(); ++i)
	cout << col1[i] << ' ';
    cout << endl;

    return 0;
}
