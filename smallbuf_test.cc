#include <fstream>
#include <iostream>
#include <string.h>
#include <errno.h>


using namespace std;


const int MAX_LINE_LEN = 20;

int main(void)
{
    ifstream fstrm;
    string keyword_file = "test.txt";
    char line[MAX_LINE_LEN];

    fstrm.open(keyword_file.c_str());
    if (fstrm.is_open() == false) {
	cout << "Error: can't open keyword file '" << keyword_file
	    << "', " << errno << ": " << strerror(errno) << endl;
	return -1;
    }
    while (fstrm.eof() == false) {
	fstrm.getline(line, MAX_LINE_LEN);
	cout << "# " << line << endl;
    }
    fstrm.close();
}
