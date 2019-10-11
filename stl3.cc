#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>


using namespace std;


int main(void)
{
    char line[1024];
    string word1, word2, word3, word4;

    ifstream file_fstrm("inputdata");

    while (file_fstrm.getline(line, sizeof(line))) {
        word1 = string(strtok(line, "\t\n"));
        word2 = string(strtok(NULL, "\t\n"));
        word3 = string(strtok(NULL, "\t\n"));
        word4 = string(strtok(NULL, "\t\n"));
        //cout << "word1='" << word1 << "', word2='" << word2 << "', word3='" << word3 << "', word4='" << word4 << "'" << endl;
    }

    file_fstrm.close();
}
