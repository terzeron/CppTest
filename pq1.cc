#include <iostream>
#include <queue>
#include <deque>

using namespace std;

typedef pair<string, int> pa;

class comp {
public:
    bool operator () (const pa & p1, const pa & p2) const {
        return p1.second > p2.second;
    }};

int main()
{
    priority_queue<pa, deque<pa>, comp> Q;
    pa p1("hello", 1);
    Q.push(p1);
    pa p2("java", 5);
    Q.push(p2);
    pa p3("world", 3);
    Q.push(p3);
    pa p4("terzeron", 2);
    Q.push(p4);
    pa p5("priority", 4);
    Q.push(p5);
    Q.push(make_pair("member", 0));

    while (Q.empty() == false) {
        pa x = Q.top();
        cout << x.first << " " << x.second << endl;
        Q.pop();
    }
}
