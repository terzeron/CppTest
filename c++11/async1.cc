#include <iostream>
#include <future>
#include <thread>

int main() {
    // Start tasks asynchronously using lambda functions
    auto future1 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return 42;
    });

    auto future2 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 99;
    });

    // Retrieve results
    int result1 = future1.get();
    int result2 = future2.get();

    std::cout << "Result from task1: " << result1 << std::endl;
    std::cout << "Result from task2: " << result2 << std::endl;

    return 0;
}
