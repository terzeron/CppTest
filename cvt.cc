#include <iostream>
#include <locale>

int main ()
{
    typedef std::codecvt_byname<wchar_t, char, std::mbstate_t> Cvt;
    
    std::wcin.imbue (std::locale (std::locale ("C"), new Cvt ("EUC-KR@UCS")));
    std::wcout.imbue (std::locale (std::locale ("C"), new Cvt ("UTF-8")));
    std::wcout << std::wcin.rdbuf ();

    return !(std::wcin.good () && std::wcout.good ());
}
