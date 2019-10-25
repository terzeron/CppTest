#include <iostream>
#include <string.h>
#include <arpa/inet.h>
#include <locale>
#include <ext/codecvt_specializations.h>


using namespace std;


typedef encoding_state state_type;
typedef codecvt<wchar_t, char, state_type> unicode_codecvt;


int main(void)
{
    locale loc(locale::classic(), new unicode_codecvt);
    if (!has_facet<unicode_codecvt>(loc)) {
        cerr << "don't havve facet" << endl;
        return -1;
    }
    const unicode_codecvt* cvt = &use_facet<unicode_codecvt>(loc);
    unicode_codecvt::state_type state01("UCS4", "UTF8");

    const char* text = "한글";
    const char* efrom_next;
    wchar_t* i_arr = new wchar_t[1024];
    wchar_t* ito_next;
    codecvt_base::result r1;
    
    size_t size = strlen(text);
    r1 = cvt->in(state01, text, text + size, efrom_next,
                 i_arr, i_arr + size, ito_next);
    if (r1 != codecvt_base::ok)
        return -1;
    
    for (int i = 0; i_arr[i] != 0x00000000 ; ++i) {
        if (i_arr[i] == 0x20000000) {
            cout << endl;
        } else {
            cout << "0x" << hex << htonl(i_arr[i]) << dec << endl;
        }
    }
    cout << endl;

    return 0;
}
