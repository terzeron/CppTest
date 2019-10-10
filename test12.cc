#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(void) {
    //char line[1024];
    string line;
    string word1, word2, word3, word4;
    
    ifstream file_fstrm("inputdata");
    
    while (file_fstrm.good()) {
	getline(file_fstrm, line);
	stringstream iss(line);
	iss >> noskipws >> word1 >> ws >> word2 >> ws >> word3 >> ws >> word4;
	
	cout << "word1='" << word1 << "', word2='" << word2 << "', word3='" << word3 << "', word4='" << word4 << "'" << endl;
    }
    
    file_fstrm.close();	
}
