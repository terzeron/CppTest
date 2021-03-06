#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

#include <string.h>
#include <stdlib.h>


using namespace std;


typedef istream_iterator<int> istream_iterator_int;


int main(void)
{
    vector<int> v;
    istream_iterator_int start(cin);
    istream_iterator_int end;
    back_insert_iterator<vector<int>> dest(v);

    copy(start, end, dest);	// from start to end --> dest
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));

    return 0;
}
