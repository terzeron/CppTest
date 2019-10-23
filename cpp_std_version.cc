#include <iostream>

using namespace std;

int main()
{
#if __cplusplus == 201707
    cout << "version=c++2a " << endl;
#elif __cplusplus == 201703
    cout << "version=c++17 " << endl;
#elif __cplusplus == 201402
    cout << "version=c++14 " << endl;
#elif __cplusplus == 201103
    cout << "version=c++11 " << endl;
#elif __cplusplus == 199711
    cout << "version=c++98 " << endl;
#endif

    cout << "__cplusplus=" << __cplusplus << endl;
}
