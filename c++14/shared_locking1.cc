#include <iostream>
#include <shared_mutex>

using namespace std;

int main(void)
{
    shared_timed_mutex m;
    shared_lock<shared_timed_mutex> lk(m, defer_lock);

    lk.lock();
    cout << "in shared lock" << endl;
    lk.unlock();

    return 0;
}
