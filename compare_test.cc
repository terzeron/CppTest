#include <iostream>

using namespace std;

int main(void)
{
    int ret;
    locale("C");
    string str[] = { "´Ú", "«‰" };

    for (unsigned int i = 0; i < sizeof(str) / sizeof(string); ++i) {
	for (unsigned int j = 0; j < sizeof(str) / sizeof(string); ++j) {
	    cout << "first='" << str[i] << "', second='" << str[j] << "' ";
	    if (str[i] < str[j])
		cout << "< ";
	    else if (str[i] > str[j])
		cout << "> ";
	    else
		cout << "== ";
	    ret = str[i].compare(str[j]);
	    if (ret < 0)
		cout << "< ";
	    else if (ret > 0)
		cout << "> ";
	    else
		cout << "== ";
	    ret = lexicographical_compare(str[i].begin(), str[i].end(),
					  str[j].begin(), str[j].end());
	    if (ret)
		cout << "< ";
	    else
		cout << ">= ";
	    cout << endl;
	}
    }
    return 0;
}
