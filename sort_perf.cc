#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <queue>

#include <errno.h>
#include <sys/time.h>

#include "common.h"


using namespace std;


int main(void)
{
    // start time
    struct timeval start_tv;
    struct timeval end_tv;
    gettimeofday(&start_tv, NULL);

    char buf[1024];
    char delimiter_str[] = "\t";
    char *lasts;
    string query;
    int uipcnt;
    double elapsed;

    typedef hash_map < string, int, string_hash_t > hashmap_t;
    hashmap_t a_hashmap;
    hashmap_t::iterator hm_iter;

    typedef vector < pair < string, int >>vector_t;
    vector_t a_vector;
    vector_t::iterator v_iter;

    ifstream fstrm("testfile");
    if (fstrm.is_open() == false) {
	cerr << "can't open file, " << errno << ": "
	    << strerror(errno) << endl;
	return -1;
    }

    cout << "couting UIPcnt of query..." << endl;
    while (fstrm.good()) {
	fstrm.getline(buf, sizeof(buf));
	if (fstrm.good() == false)
	    break;
	query = strtok_r(buf, delimiter_str, &lasts);

	hm_iter = a_hashmap.find(query);
	if (hm_iter != a_hashmap.end()) {
	    ++hm_iter->second;
	} else {
	    a_hashmap.insert(make_pair(query, 1));
	}
    }
    cout << "a_hashmap.size()=" << a_hashmap.size() << endl;

    gettimeofday(&end_tv, NULL);
    elapsed = double (end_tv.tv_sec - start_tv.tv_sec) +
	double (end_tv.tv_usec - start_tv.tv_usec) / 1000000;
    cout << "\t\t " << elapsed << " second(s) from start" << endl;

    cout << "making a vector from a hash map..." << endl;
    for (hm_iter = a_hashmap.begin(); hm_iter != a_hashmap.end();
	 ++hm_iter) {
	query = hm_iter->first;
	uipcnt = hm_iter->second;
	a_vector.push_back(make_pair(query, uipcnt));
    }

    gettimeofday(&end_tv, NULL);
    elapsed = double (end_tv.tv_sec - start_tv.tv_sec) +
	double (end_tv.tv_usec - start_tv.tv_usec) / 1000000;
    cout << "\t\t " << elapsed << " second(s) from start" << endl;

    cout << "sorting..." << endl;
    sort(a_vector.begin(), a_vector.end());

    gettimeofday(&end_tv, NULL);
    elapsed = double (end_tv.tv_sec - start_tv.tv_sec) +
	double (end_tv.tv_usec - start_tv.tv_usec) / 1000000;
    cout << "\t\t " << elapsed << " second(s) from start" << endl;

    cout << "a_vector.size()=" << a_vector.size() << endl;
    cout << "travesing..." << endl;
    for (v_iter = a_vector.begin(); v_iter != a_vector.end(); ++v_iter) {
	query = v_iter->first;
	uipcnt = v_iter->second;
    }

    // end time
    gettimeofday(&end_tv, NULL);
    elapsed = double (end_tv.tv_sec - start_tv.tv_sec) +
	double (end_tv.tv_usec - start_tv.tv_usec) / 1000000;
    cout << "\t\t " << elapsed << " second(s) from start" << endl;

    fstrm.close();
}
