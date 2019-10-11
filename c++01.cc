#include <iostream>

using namespace std;

int main()
{
    const float fac = 2.54;
    float x, in, cm;
    char ch = 0;

    cout << "\nenter length: ";

    cin >> x;
    cin >> ch;

    if (ch == 'i') {
	in = x;
	cm = x * fac;
    } else if (ch == 'c') {
	in = x / fac;
	cm = x;
    } else
	in = cm = 0;

    cout << in << " in = " << cm << " cm\n";

    cout << "Hello World!\n";

}
