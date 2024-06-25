#include <iostream>
#include <coroutine>

using namespace std;

struct task {
    struct promise_type {
        task get_return_object() { return {}; }
        suspend_never initial_suspend() { return {}; }
        suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };
};

task simple_coroutine() {
    cout << "inside coroutine!" << endl;
    co_return;
    cout << "end of coroutine" << endl;
}

int main() {
    cout << "main start" << endl;
    simple_coroutine();
    cout << "main end" << endl;
    return 0;
}
