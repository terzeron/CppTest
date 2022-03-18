#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    enum class E { ONE = 1, TWO, THREE };
    enum EU { ONE = 1, TWO, THREE };

    E e = E::TWO;
    cout << "e=" << (int) e << endl;
    int two = static_cast<int>(e);
    cout << "two=" << two << endl;

    E e2 = static_cast<E>(two);
    cout << "e2=" << (int) e2 << endl;

    EU eu = static_cast<EU>(e2);
    cout << "eu=" << eu << endl;

    void* vp = &e;
    cout << "vp=" << vp << endl;
    vector<int>* p = static_cast<vector<int>*>(vp);
    cout << "p=" << p << endl;
    
    return 0;
}
