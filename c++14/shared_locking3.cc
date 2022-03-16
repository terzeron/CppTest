#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

using namespace std;


string file = "original content.";
mutex output_mutex;
shared_timed_mutex file_mutex;


void read_content(int id)
{
    string content;
    shared_lock<shared_timed_mutex> lock(file_mutex, defer_lock);
    lock.lock();
    content = file;
    lock_guard<mutex> lg(output_mutex);
    cout << "read by reader #" << id << ": " << content << endl;
}

void write_content()
{
    file = "new content.";
    lock_guard<mutex> lg(output_mutex);
    cout << "new content saved" << endl;
}

int main(void)
{
    thread reader1 { read_content, 1 };
    thread reader2 { read_content, 2 };
    thread writer { write_content };

    reader1.join();
    reader2.join();
    writer.join();
    cout << "done" << endl;
    
    reader1 = thread { read_content, 3 };
    reader1.join();

    return 0;
}
