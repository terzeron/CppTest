#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Person {
  public:
    Person() {
	fname = "";
	lname = "";
    } Person(string a, string b) {
	fname = a;
	lname = b;
    }
    ~Person() {
	fname = "";
	lname = "";
    }
    string firstname() const {
	return fname;
    } string lastname() const {
	return lname;
  } private:
     string fname;
    string lname;
};


class PersonSortCriterion {
  public:
    bool operator () (const Person & p1, const Person & p2) const {
	return (p1.lastname() < p2.lastname()) ||
	    ((p2.lastname() == p1.lastname()) &&
	     (p1.firstname() < p2.firstname()));
}};


int main()
{
    typedef set < Person, PersonSortCriterion > PersonSet;

    PersonSet coll;
    coll.insert(Person("William", "Bratton"));
    coll.insert(Person("John", "Mack"));
    coll.insert(Person("John", "Williams"));
    coll.insert(Person("Bill", "Bratton"));
    coll.insert(Person("Steve", "Cooley"));

    PersonSet::iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
	cout << pos->firstname() << " " << pos->lastname() << endl;
    }

}
