#include <iostream>
#include <string>

using namespace std;

int main()
{
    wchar_t *ret;
    string a;
    string b;
    wchar_t w1[1024] = { 0, };
    wchar_t w2[1024] = { 0, };

    setlocale(LC_CTYPE, "ko_KR.eucKR");

    a = "ǳ�����ۼ�";
    b = "ǳ��";
    //memset(w1, 0, 1024);
    //memset(w2, 0, 1024);
    mbstowcs(w1, a.c_str(), 1024);
    mbstowcs(w2, b.c_str(), 1024);
    ret = wcsstr(w1, w2);
    cout << ret << endl;
    cout.flush();

    a = "�ٶ�����";
    b = "��";
    //memset(w1, 0, 1024);
    //memset(w2, 0, 1024);
    mbstowcs(w1, a.c_str(), 1024);
    mbstowcs(w2, b.c_str(), 1024);
    ret = wcsstr(w1, w2);
    cout << ret << endl;
    cout.flush();

    return 0;
}
