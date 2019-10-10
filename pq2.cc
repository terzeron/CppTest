#include <iostream>
#include <queue>
#include <deque>

using namespace std;

typedef pair<int, string> pa_t;

class comp {
public:
    bool operator() (const pa_t& p1, const pa_t& p2) const {
        return p1.second > p2.second;
    }
};

int main()
{
    priority_queue<pa_t, deque<pa_t>, greater<pa_t> > Q;
    Q.push(make_pair(1, "hello"));
    Q.push(make_pair(5, "java"));
    Q.push(make_pair(2, "terzeron"));
    Q.push(make_pair(4, "priority"));
    Q.push(make_pair(0, "member"));

    while (Q.empty() == false) {
        pa_t x = Q.top();
        cout << x.first << " " << x.second << endl;
        Q.pop();
    }
}

