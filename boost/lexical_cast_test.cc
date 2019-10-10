/*
 * ex) lexical_cast_test 1 2 a 3 4c 5
 */

#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;

int main(int argc, char* argv[])
{
    using boost::lexical_cast;
    using boost::bad_lexical_cast;

    vector<short> args;
    vector<short>::iterator args_iter;

    while (*++argv) {
	try {
	    args.push_back(lexical_cast<short>(*argv));
	} catch (bad_lexical_cast&) {
	    args.push_back(0);
	}
    }

    for (args_iter = args.begin(); args_iter != args.end(); ++args_iter) {
	cout << *args_iter << endl;
    }
    
    return 0;
}

	
