#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>


using namespace std;


void print_string(string name, auto ptr)
{
    if (ptr == nullptr) {
        cout << name << ": null at " << ptr << endl;
    } else {
        cout << name << ": " << *ptr << " at " << ptr << endl;
    }
}


int main()
{
    auto sp1 = make_shared<string>("hello world");
    print_string("sp1", sp1);

    shared_ptr<string> sp2(new string("java coffee"));
    print_string("sp2", sp2);
    
    shared_ptr<string> sp3(nullptr);
    sp3 = make_shared<string>("music beat");
    print_string("sp3", sp3);

    // copy constructor, refcount++
    auto sp4(sp3);
    print_string("sp4", sp4);
    
    // assignment, refcount++
    auto sp5 = sp2;
    print_string("sp5", sp5);

    cout << "--- swap ---" << endl;
    print_string("sp1", sp1);
    print_string("sp2", sp2);
    sp1.swap(sp2);
    print_string("sp1", sp1);
    print_string("sp2", sp2);

    cout << "--- remove_copy_if ---" << endl;
    vector<shared_ptr<string>> v;
    v.push_back(make_shared<string>("springframework"));
    v.push_back(make_shared<string>("springboot"));
    v.push_back(nullptr);
    v.push_back(make_shared<string>("spring-security"));
    for (auto i : v) {
        print_string("v", i);
    }
    vector<shared_ptr<string>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<string> s) { return s != nullptr && s->compare("springboot"); });
    for (auto i : v2) {
        print_string("v2", i);
    }

    v2.clear();
    cout << "--- copy_if ---" << endl;
    copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<string> s) -> bool { shared_ptr<string> temp = dynamic_pointer_cast<string>(s); return temp.get() != nullptr; });
    for (auto i : v2) {
        print_string("v2", static_pointer_cast<string>(i));
    }

    cout << "--- comparison ---" << endl;
    auto str1 = new string("hello");
    auto str2 = new string("hello");
    shared_ptr<string> p1(str1);
    shared_ptr<string> p2(str2);
    cout << "p1 < p2: " << boolalpha << (p1 < p2) << endl;
    cout << "p1 == p2: " << boolalpha << (p1 == p2) << endl;
    // 포인터를 공유하면 동일한 값을 가짐
    shared_ptr<string> p5(p2);
    cout << "p5 == p2: " << boolalpha << (p5 == p2) << endl;
    
    return 0;
}
