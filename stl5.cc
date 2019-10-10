#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string a = "abcdefghijklmlopqrstuvwxyz";
    string b = "abcd";
    string c = "def";
    string d = "kdjfls";

    if (a.find(b) > 0) {
	cout << "over than 0" << endl;
    } else if (a.find(b) == 0) {
	cout << "is 0" << endl;
    } else {
	cout << a.find(b) << endl;
    }

    if (a.find(c) > 0) {
	cout << "over than 0" << endl;
    } else if (a.find(b) == 0) {
	cout << "is 0" << endl;
    } else {
	cout << a.find(b) << endl;
    }

    if (a.find(c) != string::npos) {
	cout << "is not npos" << endl;
    } else {
	cout << "is npos" << endl;
    }

    if (a.find(d) > 0) {
	cout << "over than 0" << endl;
    } else if (a.find(d) == 0) {
	cout << "is 0" << endl;
    } else {
	cout << a.find(d) << endl;
    }

    if (a.find(d) != string::npos) {
	cout << "is not npos" << endl;
    } else {
	cout << "is npos" << endl;
    }

}
