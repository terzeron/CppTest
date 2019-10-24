#include <iostream>
#include <locale>
#include <cwchar>
#include <cstring>

#include "unicode/unistr.h"
#include "unicode/normlzr.h"
#include "unicode/unorm.h"
#include "unicode/bytestream.h"


using namespace std;
using namespace icu;


int decompose(const char* text, wchar_t* wcs_buf, unsigned int buf_size)
{
    // UTF-8 to UCS4
    UnicodeString str = UnicodeString::fromUTF8(StringPiece(text));

    // UCS4 to NFD
    UnicodeString result;
    UErrorCode status = U_ZERO_ERROR;
    Normalizer::normalize(str, UNORM_NFD, 0, result, status);
    if (U_FAILURE(status)) {
        cerr << "can't decompose a UTF8 string, " 
             << status << ": " << u_errorName(status) << endl;
        return -1;
    }

    result.toUTF32((UChar32*) wcs_buf, buf_size, status);

    return 0;
}


int compose(wchar_t* wcs, unsigned int wcs_len, char* buf, unsigned int buf_size)
{
    // UCS4 to NFC
    UnicodeString str = UnicodeString::fromUTF32((UChar32*) wcs, wcs_len);

    UnicodeString result;
    UErrorCode status = U_ZERO_ERROR;
    Normalizer::normalize(str, UNORM_NFC, 0, result, status);
    if (U_FAILURE(status)) {
        cerr << "can't compose a UTF8 string, "
             << status << ": " << u_errorName(status) << endl;
        return -1;
    }

    string temp;
    StringByteSink<string> sink(&temp);
    result.toUTF8(sink);
    strcpy(buf, temp.c_str());

    return 0;
}


int main(void)
{
    const char* text = "한글";
    wchar_t wcs_buf[1024];
    char new_text[1024];

    decompose(text, wcs_buf, sizeof (wcs_buf));
    for (unsigned int i = 0; wcs_buf[i] != 0; ++i) {
        cout << "wcs_buf[" << i << "]=0x" << hex << (int) wcs_buf[i] << endl;
    }
    cout << endl;

    int wcs_len = wcslen(wcs_buf);
    compose(wcs_buf, wcs_len, new_text, sizeof (new_text)); 
    cout << new_text << endl;
    
    return 0;
}
