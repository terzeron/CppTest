#include <iostream>

using namespace std;

int main(void)
{
    int num = 3;
    int& refNum = num; 
    //int& refNum2 = 0; // error
    const int& refNum3 = 10;

    cout << "num=" << num << endl;
    cout << "refNum=" << refNum << endl;
    cout << "refNum3=" << refNum3 << endl;

    return 0;
}
