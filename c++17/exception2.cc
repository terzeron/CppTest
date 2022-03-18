#include <iostream>
#include <stdexcept>

using namespace std;

void my_func1() noexcept(true) {
    throw out_of_range("out of range in my_func1!");
}

void my_func2() throw() {
    throw out_of_range("out of range in my_func2!");
}

/*
void my_func3() throw(int) {
}
*/

//void (*my_func)() = my_func3;
void (*my_func)() noexcept(false) = *my_func1;

int main(void)
{
    printf("my_func1=%p\n", my_func1);
    printf("my_func2=%p\n", my_func2);
    printf("my_func=%p\n", my_func);
    
    try {
        my_func();
    } catch (exception& e) {
        cout << "caught in handler" << endl;
    }

    return 0;
}
