#include <iostream>
#include <coroutine>
#include <vector>

template<typename T>
struct Generator {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        T value;
        std::suspend_always yield_value(T v) { value = v; return {}; }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        Generator get_return_object() { return Generator{handle_type::from_promise(*this)}; }
        void return_void() {}
        void unhandled_exception() {}
    };

    handle_type coro;

    Generator(handle_type h) : coro(h) {}
    ~Generator() { if (coro) coro.destroy(); }

    bool next() { coro.resume(); return !coro.done(); }
    T getValue() { return coro.promise().value; }
};

Generator<int> simpleYieldFunction() {
    for (int i = 0; i < 5; ++i) {
        co_yield i;
    }
}

int main() {
    auto gen = simpleYieldFunction();
    while (gen.next()) {
        std::cout << gen.getValue() << std::endl;
    }
    return 0;
}
