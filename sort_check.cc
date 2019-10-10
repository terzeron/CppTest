#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[])
{
    char buf[1024];
    string query;
    string previous_query;

    ifstream fstrm(argv[1]);

    while (fstrm.good()) {
	fstrm.getline(buf, sizeof (buf) - 1);
	query = buf;
	if (query.compare(previous_query) < 0) {
	    cerr << "query='" << query << "', previous_query='" 
		 << previous_query << "'" << endl;
	}

	previous_query = query;
    }
    fstrm.close();
    return 0;
}
