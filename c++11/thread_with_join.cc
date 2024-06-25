#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void workerFunction(int id) {
    this_thread::sleep_for(chrono::seconds(2));
}

int main() {
    const int numThreads = 10;
    vector<thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(thread(workerFunction, i + 1));
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    cout << "Main thread is done." << endl;

    return 0;
}
