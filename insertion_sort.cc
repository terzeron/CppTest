#include <iostream>
#include <string>


using namespace std;


typedef struct {
    string key;
    int file_id;
} element;


void insertion_sort(element arr[], int n)
{
    int i, j;
    element next;
    for (i = 1; i < n; ++i) {
	next = arr[i];
	for (j = i - 1; j >= 0 && next.key < arr[j].key; --j) {
	    cout << "." << endl;
	    arr[j + 1] = arr[j];
	}
	arr[j + 1] = next;
    }
}


int main(void)
{
    //element arr[] = { {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4} };
    //insertion_sort(arr, sizeof (arr) / sizeof (arr[0]));
    element arr[] = { {"4", 1}, {"3", 2}, {"2", 3}, {"1", 4} };
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
}
