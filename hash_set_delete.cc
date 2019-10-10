#include <iostream>
#include <ext/hash_set>

using namespace std;
using namespace __gnu_cxx;

typedef hash_set<char*> chrp_hset_t;
typedef chrp_hset_t::iterator chrp_hsiter_t;

int main(void)
{
    chrp_hset_t a_hset;
    chrp_hsiter_t it;
    char* p;

    for (int i = 0; i < 100; ++i) {
	p = new char[100];
	sprintf(p, "%s%d", "hello", i);
	a_hset.insert(p);
	printf("%p %s\n", p, p);
    }
    cout << endl;

    do {
	it = a_hset.begin(); 
	if (it == a_hset.end())
	    break;
	printf("%p %s\n", *it, *it);
	p = *it;
	a_hset.erase(it);
	delete [] p;
    } while (it != a_hset.end());
}
