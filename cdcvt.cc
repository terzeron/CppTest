#include <iostream>
#include <stdio.h>
#include <locale>


using namespace std;
typedef __enc_traits enc_type;
typedef codecvt<wchar_t, char, enc_type> unicode_codecvt;
typedef codecvt_base::result result;
typedef wchar_t int_type;
typedef char ext_type;
typedef	__gnu_cxx::char_traits<int_type>	int_traits;

const unicode_codecvt* cvt_p;
unicode_codecvt::state_type* state01;

int main1(void)
{
    locale loc(locale::classic(), new unicode_codecvt);
    if (!has_facet<unicode_codecvt>(loc)) {
	cerr << "don't have facet" << endl;
	return -1;
    }
    cvt_p = &use_facet<unicode_codecvt>(loc);
    state01 = new __enc_traits("UCS4", "UHC");
    state01->_M_init();
    if (state01->_M_good() == false) {
	cerr << "can't make state" << endl;
	return -1;
    }
    
    return 0;
}

int main2(void)
{
    const ext_type* e_lit = "œò šœ „œ";
    const ext_type* e_lit2 = "½Ã³Á¹° Ã³Á¹ ³Á"; 
    const ext_type* efrom_next;
    int_type* i_arr = new int_type[1024];
    int_type* ito_next;
    result r1;
    const unicode_codecvt* cvt_p;

    int size = strlen(e_lit);
    int size2 = strlen(e_lit2);

    r1 = cvt_p->in(*state01, e_lit, e_lit + size, efrom_next,
		   i_arr, i_arr + size, ito_next);
    if (r1 != codecvt_base::ok) 
	return -1;
    for (int i = 0; i < size; ++i) {
	if (i_arr[i] == 0x20000000) {
	    printf("\n");
	} else {
	    printf("0x%08X\n", i_arr[i]);
	}
    }
    cout << "ok" << endl;
    
    r1 = cvt_p->in(*state01, e_lit2, e_lit2 + size2, efrom_next,
		   i_arr, i_arr + size2, ito_next);
    if (r1 != codecvt_base::ok) 
	return -1;
    for (int i = 0; i < size2; ++i) {
	if (i_arr[i] == 0x20000000) {
	    printf("\n");
	} else {
	    printf("0x%08X\n", i_arr[i]);
	}
    }
    cout << "ok" << endl;

    return 0;
}


int main(void)
{
    main1();
    main2();
    
    return 0;
}
