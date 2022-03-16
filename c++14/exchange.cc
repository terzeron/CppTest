#include <iostream>
#include <utility>

using namespace std;

int main(void)
{
    int i = 3;
    int j = 5;

    cout << "i=" << i << endl;
    cout << "j=" << j << endl;
    cout << "return of exchange=" << exchange(j, i) << endl;
    cout << "i=" << i << endl;
    cout << "j=" << j << endl;
    
    return 0;
}
