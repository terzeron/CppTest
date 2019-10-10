#include <string.h>
#include <algo.h>
#include <vector.h>
#include <stdlib.h>
#include <iostream.h>

#ifdef __PTRDIFF_TYPE__
typedef istream_iterator < int, ptrdiff_t > istream_iterator_int;
#else
typedef istream_iterator < int >istream_iterator_int;
#endif

int main(void)
{
    vector < int >v;
    istream_iterator_int start(cin);
    istream_iterator_int end;
    back_insert_iterator < vector < int >>dest(v);

    copy(start, end, dest);	// from start to end --> dest
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator < int >(cout, "\n"));

    return 0;
}
