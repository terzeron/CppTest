#include <iostream>
#include <iomanip>
#include <boost/format.hpp>

using namespace std;
using boost::format;
using boost::io::group;

int main()
{
    // simple, reordering
    cout << format("%1% %2% %3% %2% %1%\n") % "11" % "22" % "333"; 
    // precise, positional
    cout << format("(x,y) = (%1$+5d, %2$+5d)\n") % -23 % 35;
    // classical, no reordering
    cout << format("writing %s, x=%s: %d-th step\n") % "toto" % 40.23 % 50;
    // other style
    cout << format("(x,y) = (%+5d, %+5d)\n") % -23 % 35;
    cout << format("(x,y) = (%|+5|, %|+5|)\n") % -23 % 35;
    cout << format("(x,y) = (%|1$+5|, %|2$+5|)\n") % -23 % 35;

    // manipulator
    format fmter("_%1$+5d_ %1$d\n");
    format fmter2("_%1%_ %1%\n");
    fmter2.modify_item(1, group(showpos, setw(5)));
    cout << fmter % 101;
    cout << fmter2 % 101;

    // manipulator with arguments
    cout << format("_%1%_ %1%\n") % group(showpos, setw(5), 101);

    // absolute tabulation
    string names[2] = {"Marc-Francois Michel", "Jean"};
    string surnames[2] = {"Durand", "de Lattre de Tassigny"};
    string tel[2] = {"123 456 789", "987 654 321"};
    for (unsigned int i = 0; i < sizeof (names) / sizeof (names[0]); ++i) {
	cout << format("%1%, %2%, %|40t|%3%\n") % names[i] % surnames[i] % tel[i];
    }

    return 0;
}
