#include <iostream>
#include <memory>
#include <string>

using namespace std;


int main(void)
{
    unique_ptr<int> int_ptr1 = make_unique<int>();
    cout << *int_ptr1 << endl;
    unique_ptr<int> int_ptr2 = make_unique<int>(34);
    cout << *int_ptr2 << endl;

    unique_ptr<string> str_ptr1 = make_unique<string>();
    cout << '\"' << *str_ptr1 << '\"' << endl;
    unique_ptr<string> str_ptr2 = make_unique<string>("hello");
    cout << '\"' << *str_ptr2 << '\"' << endl;

    auto up = make_unique<int[]>(5);
    for (int i = 0; i < 5; ++i) {
        cout << up[i] << endl;
    }

    return 0;
}
