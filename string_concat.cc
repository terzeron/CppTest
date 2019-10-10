#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
inline string to_string (const T& t)
{
	stringstream ss;
	ss << t;
	return ss.str();
}

int main(void)
{
	stringstream ss;
	string a = "";

	for (int i = 0; i < 1000; i++) {
		a += string(" java") + to_string(i);
	}
	cout << a << endl;
}
