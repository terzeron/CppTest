#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int main(void)
{
    ifstream fstrm;
    char buf[8192];

    fstrm.open("q2.txt");
    while (!fstrm.eof()) {
	fstrm.getline(buf, 8192);
	printf("'%s'", buf);
	buf[5] = '\0';
	printf("\t'%s'\t", &buf[1]);
	buf[4] = '\0';
	printf("\t'%s'\t", &buf[1]);
	buf[3] = '\0';
	printf("\t'%s'\t", &buf[1]);
	buf[2] = '\0';
	printf("\t'%s'\n", &buf[1]);
    }
    fstrm.close();
    return 0;
}
