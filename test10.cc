#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(void)
{
    char line[1024];
    string word1, word2, word3, word4;

    ifstream file_fstrm("inputdata");
    while (file_fstrm.good()) {
	file_fstrm.get(line, 1024, '\t');
	word1 = string(line);
	file_fstrm.get(line, 1024, '\t');
	word2 = string(line);
	file_fstrm.get(line, 1024, '\t');
	word3 = string(line);
	file_fstrm.get(line, 1024, '\n');
	word4 = string(line);

	//cout << "word1='" << word1 << "', word2='" << word2 << "', word3='" << word3 << "', word4='" << word4 << "'" << endl;
    }

    file_fstrm.close();
}
