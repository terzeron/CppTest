#include <iostream>
#include <stdexcept>

using namespace std;

void my_func() throw() {
    throw out_of_range("out of range!");
}

int main(void)
{
    try {
        my_func();
    } catch (exception& e) {
        cout << "caught in handler" << endl;
    }

    return 0;
}
