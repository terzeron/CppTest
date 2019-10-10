#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;


class RuntimeStringCmp {
public:
    enum cmp_mode {normal, nocase};
private:
    const cmp_mode mode;
    
    static bool nocase_compare(char c1, char c2) {
	return toupper(c1) < toupper(c2);
    }
    
public:
    RuntimeStringCmp (cmp_mode m=normal) : mode(m) {
    }
    
    bool operator() (const string& s1, const string& s2) const {
	if (mode == normal) {
	    return s1 < s2;
	} else {
	    return lexicographical_compare(s1.begin(), s1.end(), 
					   s2.begin(), s2.end(),
					   nocase_compare);
	}
    }
};


typedef map<string, string, RuntimeStringCmp> StringStringMap;

void fillAndPrint(StringStringMap& coll)
{
    coll["deutcchland"] = "German";
    coll["Deutschland"] = "Germany"; 
    coll["arbeiten"] = "work";
    
    StringStringMap::iterator pos;
    cout.setf(ios::left, ios::adjustfield);
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
	cout << setw(15) << pos->first.c_str() << " " << pos->second << endl;
    }
}

int main()
{
    StringStringMap coll1;
    fillAndPrint(coll1);
    
    RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);
			       
			       StringStringMap coll2;
			       fillAndPrint(coll2);
}
				   
