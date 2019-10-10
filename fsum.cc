#include <iostream>
#include <fstream>
#include <vector>

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>


using namespace std;

typedef vector < long long >llong_vct_t;
typedef
 llong_vct_t::iterator llong_vitr_t;

const int
 buffer_size = 8196;
llong_vct_t value_list;


int read_and_sum(istream & fstrm, int field_num)
{
    char *delimiter = "\t";
    char *lasts;
    char *token;
    char line[buffer_size];
    long long llval;

    while (fstrm.good()) {
	fstrm.getline(line, buffer_size);
	token = strtok_r(line, delimiter, &lasts);
	if (token == NULL)
	    break;
	llval = atoll(token);
	value_list.push_back(llval);
    }

    return 0;
}


int main(int argc, char *argv[])
{
    int i;
    fstream fstrm;
    llong_vitr_t itr;
    long long data;
    double mean;
    double var = 0.0;
    long long sum = 0LL;
    int num_values = 0;
    long long min;
    long long max;

    if (argc > 1) {
	for (i = 1; i < argc; ++i) {
	    cout << argv[i] << endl;
	    fstrm.open(argv[i]);
	    if (fstrm.is_open() == false) {
		cerr << "can't open '" << argv[i] << "', for reading, "
		    << errno << ": " << strerror(errno) << endl;
		return -1;
	    }
	    read_and_sum(fstrm, 0);
	}
    } else {
	read_and_sum(cin, 0);
    }

    max = min = *value_list.begin();
    for (itr = value_list.begin(); itr != value_list.end(); ++itr) {
	data = *itr;
	sum += data;
	++num_values;
	if (data < min) {
	    min = data;
	}
	if (data > max) {
	    max = data;
	}
    }
    printf("sum:\t%lld\n", sum);
    mean = double (sum) / double (num_values);
    printf("mean:\t%f\n", mean);
    for (itr = value_list.begin(); itr != value_list.end(); ++itr) {
	data = *itr;
	var += (data - mean) * (data - mean);
    }
    printf("var:\t%f\n", var / (num_values - 1));
    printf("stdev:\t%f\n", sqrt(var / (num_values - 1)));
    printf("max:\t%lld\n", max);
    printf("min:\t%lld\n", min);

    return 0;
}
