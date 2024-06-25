#include <iostream>
#include <coroutine>

using namespace std;

struct task {
    struct promise_type {
        task get_return_object() { return task(handle_type::from_promise(*this)); }
        suspend_always initial_suspend() { return {}; }
        suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };
    using handle_type = coroutine_handle<promise_type>;
    handle_type coro;

    task(handle_type h) : coro(h) {}
    ~task() { if (coro) coro.destroy(); }
    void resume() { if (!coro.done()) coro.resume(); }
};

task simple_coroutine() {
    cout << "Before suspension" << endl;
    co_await suspend_always{};
    cout << "After suspension" << endl;
    co_return;
}

int main() {
    auto t = simple_coroutine();
    cout << "Coroutine created but not yet resumed." << endl;
    t.resume();
    cout << "Coroutine resumed and completed." << endl;

    return 0;
}
