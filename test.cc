#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(void) {
	char line[1024];
	string word1, word2, word3, word4;

	ifstream file_fstrm("inputdata");
#if 1
	while (file_fstrm.good()) {
#if 1
	    file_fstrm.getline(line, 1024, '\t');
	    word1 = string(line);	
	    file_fstrm.getline(line, 1024, '\t');
	    word2 = string(line);
	    file_fstrm.getline(line, 1024, '\t');
	    word3 = string(line);
	    file_fstrm.getline(line, 1024, '\n');
	    word4 = string(line);
#else
	    file_fstrm.get(line, 1024, '\t');
	    word1 = string(line);	
	    file_fstrm.get(line, 1024, '\t');
	    word2 = string(line);
	    file_fstrm.get(line, 1024, '\t');
	    word3 = string(line);
	    file_fstrm.get(line, 1024, '\n');
	    word4 = string(line);
#endif 
	    cout << "word1='" << word1 << "', word2='" << word2 << "', word3='" << word3 << "', word4='" << word4 << "'" << endl;
	}
#else
	while (file_fstrm.getline(line, sizeof (line))) {
	    word1 = string(strtok(line, "\t\n"));
	    word2 = string(strtok(NULL, "\t\n"));
	    word3 = string(strtok(NULL, "\t\n"));
	    word4 = string(strtok(NULL, "\t\n"));
	    //cout << "word1='" << word1 << "', word2='" << word2 << "', word3='" << word3 << "', word4='" << word4 << "'" << endl;
	}
#endif


	file_fstrm.close();	
}
