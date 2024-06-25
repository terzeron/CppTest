#include <iostream>
#include <thread>
#include <vector>
#include <barrier>

int main() {
    const int num_threads = 5;
    std::barrier barrier(num_threads, []() {
                                          std::cout << "All threads reached the barrier!\n";
                                      });

    auto worker = [&barrier](int id) {
                      std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));
                      std::cout << "Thread " << id << " reached the barrier.\n";
                      barrier.arrive_and_wait();
                      std::cout << "Thread " << id << " passed the barrier.\n";
                  };

    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(worker, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
