#include <iostream>
#include <thread>

using namespace std;


void workerFunction() {
    //cout << "Worker thread is sleeping for 2 seconds" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    //cout << "Worker thread is done." << endl;
}

int main() {
    thread workerThread(workerFunction);

    //workerThread.detach();
    workerThread.join();

    cout << "Main thread is done." << endl;

    //this_thread::sleep_for(chrono::seconds(3));

    return 0;
}
