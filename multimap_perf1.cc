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
    char* lasts;
    string query;
    int uipcnt;
    double elapsed;

    typedef hash_map<string, int, string_hash_t> hashmap_t;
    hashmap_t a_hashmap;
    hashmap_t::iterator iter2;

    typedef multimap<int, string> multimap_t;
    multimap_t a_multimap;
    multimap_t::iterator iter;

    ifstream fstrm("testfile");
    if (fstrm.is_open() == false) {
	cerr << "can't open file, " << errno << ": " 
	     << strerror(errno) << endl;
	return -1;
    }

    cout << "counting UPCcnt of query..." << endl;
    while (fstrm.good()) {
	fstrm.getline(buf, sizeof (buf));
	if (fstrm.good() == false) 
	    break;
	query = strtok_r(buf, delimiter_str, &lasts);

	iter2 = a_hashmap.find(query);
	if (iter2 != a_hashmap.end()) {	
	    iter2->second += uipcnt;
	} else {
	    a_hashmap.insert(make_pair(query, uipcnt));	
	}
    }
    gettimeofday(&end_tv, NULL);
    elapsed = double(end_tv.tv_sec - start_tv.tv_sec) +
        double(end_tv.tv_usec - start_tv.tv_usec) / 1000000;
    cout << "\t\t " << elapsed << " second(s) from start" << endl;

    cout << "a_hashmap.size()=" << a_hashmap.size() << endl;

    cout << "making a multimap from a hash map..." << endl;
    for (iter2 = a_hashmap.begin(); iter2 != a_hashmap.end(); ++iter2) {
	query = iter2->first;
	uipcnt = iter2->second;
	a_multimap.insert(make_pair(uipcnt, query));
    }
    cout << "a_multimap.size()=" << a_multimap.size() << endl;

    gettimeofday(&end_tv, NULL);
    elapsed = double(end_tv.tv_sec - start_tv.tv_sec) +
        double(end_tv.tv_usec - start_tv.tv_usec) / 1000000;
    cout << "\t\t " << elapsed << " second(s) from start" << endl;

    cout << "traversing multimap..." << endl;
    for (iter = a_multimap.begin(); iter != a_multimap.end(); ++iter) {
	uipcnt = iter->first;
	query = iter->second;
    }

    // end time
    gettimeofday(&end_tv, NULL);
    elapsed = double(end_tv.tv_sec - start_tv.tv_sec) +
        double(end_tv.tv_usec - start_tv.tv_usec) / 1000000;
    cout << "\t\t " << elapsed << " second(s) from start" << endl;

    fstrm.close();
}
