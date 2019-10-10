#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue < int, vector < int, allocator < int >>,
	less < int >>pq;
    pq.push(1);
    pq.push(2);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << endl;
    cout << pq.top() << endl;
    pq.pop();

    priority_queue < string, deque < string, allocator < string > >,
	less < string > >pqs;
    for (int i = 0; i < 10; i++) {
	pqs.push(string(i + 1, 'a'));
	//cout << pqs.top() << endl;
    }
    for (int j = 0; j < 10; j++) {
	cout << pqs.top() << endl;
	pqs.pop();
    }
    cout << endl;

    priority_queue < string, deque < string, allocator < string > >,
	greater < string > >pgqs;
    for (int k = 0; k < 10; k++) {
	pgqs.push(string(k + 1, 'a'));
	//cout << pgqs.top() << endl;
    }

    for (int m = 0; m < 10; m++) {
	cout << pgqs.top() << endl;
	pgqs.pop();
    }
    cout << endl;
}
