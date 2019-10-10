#include <iostream>
#include "boost/regex.hpp"


using namespace std;
using namespace boost;


const regex e("\\A(\\d{3,4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})\\z");
const string machine_format = "\\1\\2\\3\\4";
const string human_format = "\\1-\\2-\\3-\\4";


bool validate_card_format(const string& s)
{
    static const regex e("(\\d{4}[- ]){3}\\d{4}");
    return regex_match(s, e);
}


string machine_readable_card_number(const string s)
{
    return regex_replace(s, e, machine_format, match_default | format_sed);
}


string human_readable_card_number(const string s)
{
    return regex_replace(s, e, human_format, match_default | format_sed);
}



int main(void)
{
    cout << validate_card_format("1111-2222-3333-4444") << endl;
    cout << validate_card_format("1111 2222 3333 4444") << endl;
    
    cout << machine_readable_card_number("1111-2222-3333-4444") << endl;
    cout << machine_readable_card_number("1111 2222 3333 4444") << endl;

    cout << human_readable_card_number("1111-2222-3333-4444") << endl;
    cout << human_readable_card_number("1111 2222 3333 4444") << endl;
}
