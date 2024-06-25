#include <iostream>
#include <thread>

void printHello(int id) {
    std::cout << "Hello from Thread " << id << std::endl;
}

int main() {
    std::thread t1(printHello, 1);
    std::thread t2(printHello, 2);

    t1.join();
    t2.join();

    return 0;
}
