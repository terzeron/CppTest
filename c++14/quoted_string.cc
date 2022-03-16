#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(void)
{
    {
        stringstream ss;
        string original = "foolish me";
        string round_trip;
        
        ss << original;
        // tokenized within a word
        ss >> round_trip;
        cout << original << endl;
        cout << round_trip << endl;
    }

    {
        stringstream ss;
        string original = "foolish me";
        string round_trip;
        ss << quoted(original);
        ss >> quoted(round_trip);
        cout << original << endl;
        cout << round_trip << endl;
    }

    cout << quoted("She said \"Hi!\"") << endl;

    return 0;
}
