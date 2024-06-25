#include <iostream>
#include <coroutine>
#include <chrono>
#include <vector>
#include <thread>

struct Task {
    struct promise_type {
        Task get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };
};

Task asyncWork(int id) {
    std::cout << "Start task " << id << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));  // 임의의 대기 시간
    std::cout << "End task " << id << "\n";
    co_return;
}

int main() {
    std::vector<std::jthread> threads;

    for (int i = 0; i < 10; i++) {
        threads.emplace_back([i] { asyncWork(i); });
    }

    for (auto &thread : threads) {
        thread.join();
    }

    return 0;
}
