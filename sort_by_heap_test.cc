#include <iostream>

#include "common.h"

using namespace std;


int main(void)
{
    string run[4][5] = {
	{"a", "a", "a", "b", "c"},
	{"a", "a", "a", "a", "b"},
	{"b", "a", "a", "b", "c"},
	{"a", "a", "a", "b", "c"},
    };
    int pos[4] = { 0, 0, 0, 0 };
    triple_minheap_t query_num_heap;
    triple_t triple;
    int num;
    string query;

    for (int i = 0; i < 4; ++i) {
	query = run[i][pos[i]++];
	cout << query << ", num=" << i << ", pos=" << (pos[i] - 1) << endl;
	triple.query = query;
	triple.file_num = i;
	query_num_heap.push(triple);
    }
    cout << endl;

    for (int i = 0; query_num_heap.empty() == false; ++i) {
	triple = query_num_heap.top();
	query = triple.query;
	num = triple.file_num;
	query_num_heap.pop();
	cout << query << ", num=" << num << endl;

	if (pos[num] < 5) {
	    triple.query = run[num][pos[num]++];
	    query_num_heap.push(triple);
	}
    }

    return 0;
}
