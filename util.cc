/**
 * \file util.cc
 * \brief utility function definitions
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <sstream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>

#include "common.h"

using namespace std;


int escape_xml(const char* s, char* d, int n)
{
    int len;
    const char* str;
    int i;

    if (s == NULL)
        return -1;

    for (i = 0; i < n && *s != '\0'; ++i, ++s) {
        switch (*s) {
        case '&':
            str = "&amp;";
            len = strlen(str);
            if (i + len >= n)
                return -1;
            strncpy(d + i, str, n - i - 1);
            i += len - 1;
            break;
        case '"':
            str = "&quot;";
            len = strlen(str);
            if (i + len >= n)
                return -1;
            strncpy(d + i, str,  n - i - 1);
            i += len - 1;
            break;
        case '\'':
            str = "&apos;";
            len = strlen(str);
            if (i + len >= n)
                return -1;
            strncpy(d + i, str, n - i - 1);
            i += len - 1;
            break;
        case '<':
            str = "&lt;";
            len = strlen(str);
            if (i + len >= n)
                return -1;
            strncpy(d + i, str, n - i - 1);
            i += len - 1;
            break;
        case '>':
            str = "&gt;";
            len = strlen(str);
            if (i + len >= n)
                return -1;
            strncpy(d + i, str, n - i - 1);
            i += len - 1;
            break;
        default:
            d[i] = *s;
            break;
        }
    }

    d[i] = '\0';
    
    return 0;
}


int escape_url(const char* s, char* d)
{
    int i;

    if (s == NULL) 
        return -1;

    for (i = 0; *s != '\0'; ++i, ++s) {
        if (*s == ' ') {
            d[i] = '+';
        } else if (*s == '.') {
            d[i] = *s;
        } else if (isalpha(*s) || isdigit(*s)) {
            d[i] = *s;
        } else {
            sprintf(d + i, "%%%2X", *s & 0xFF);
            i += 2;
        }
    }
    d[i] = '\0';

    return 0;
}


int replace_str(char* d, const char* s, const char* str1, const char* str2)
{
    int i;

    if (s == NULL || str1 == NULL || str2 == NULL)
        return -1;

    for (i = 0; *s != '\0'; ++i, ++s) {
        if (!strncmp(s, str1, strlen(str1))) {
            strncpy(d + i, str2, strlen(str2));
            i += strlen(str2) - 1;
            s += strlen(str1) - 1;
        } else {
            d[i] = *s;
        }
    }
    d[i] = '\0';

    return 0;
}


int trim_whitespace(char* s)
{
    char* p = s;
    char q[MAXLINE];
    int i;
    int j;

    if (p == NULL)
        return -1;

    // skip whitespace prefix
    while (*p != '\0' && isspace(*p))
        ++p;

    // copy characters to temporary buffer
    for (i = 0; *p != '\0'; ++i, ++p) 
        q[i] = *p;
    q[i] = '\0';

    // remove whitespace suffix
    for (i = strlen(q) - 1; i >= 0 && isspace(q[i]); --i) {
        q[i] = '\0';
    }

    // copy characters in temporary buffer to original region
    // with replacing whitespace characters to one space character
    for (i = 0, j = 0; q[j] != '\0';) {
        if (isspace(q[j])) {
            s[i++] = ' ';
            while (isspace(q[j])) 
                ++j;
        } else 
            s[i++] = q[j++];
    }
    s[i] = '\0';

    return 0;
}


void remove_whitespace(char* s)
{
    char* p = s;
    char* q = p;

#ifdef VERBOSE0
    printf("remove_whitespace(s='%s')\n", s);
#endif // VERBOSE0

    if (p == NULL)
        return;

    while (1) {
#ifdef VERBOSE0
        printf("before *p=%02x'?', *q=%02x'%c'\n", ((int) p) & 0xFF, 
               ((int) q) & 0xFF, *q);
#endif // VERBOSE0
        while (isspace(*p)) 
            ++p;
        if (q < p) {
#ifdef VERBOSE0
            printf("copy *p='%c' --> *q='%c'\n", *p, *q); 
#endif // VERBOSE0
            *q = *p;
        }
        if (*q == '\0')
            break;
        ++p;
        ++q;
    }
#ifdef VERBOSE0
    printf("s='%s'\n", s);
#endif // VERBOSE0
}


void remove_whitespace(const string& str, string& result)
{
    char buf[MAXLINE];

    strcpy(buf, str.c_str());
    remove_whitespace(buf);
    result = string(buf);
}


void tolower(char* str)
{
    while (*str) {
        if (isupper((int) *str))
            *str = tolower((int) *str);
        ++str;
    }
}


bool is_digit_string(const char *s)
{
#ifdef VERBOSE00
    cout << "is_digit_string(s=" << string(s) << ")" << endl;
    cout.flush();
#endif // VERBOSE0
    
    if (s == NULL)
        return false;

    bool ret = false;
    unsigned int len = strlen(s);
    unsigned int count = 0;

    for (unsigned int i = 0; i < len; ++i) {
        if (isdigit(s[i])) {
            ++count;
        }
    }

    if (count == len && count > 0) {
        ret = true;
    }
    
    return ret;
}


bool is_digit_string(const string& s)
{
#ifdef VERBOSE0
    cout << "is_digit_string(s=" << s << ")" << endl;
    cout.flush();
#endif // VERBOSE0

    bool ret = false;
    const char *p = s.c_str();
    unsigned int len = strlen(p);
    unsigned int count = 0;

    for (unsigned int i = 0; i < len; ++i) {
        if (isdigit(p[i])) {
            ++count;
        }
    }
    
    if (count == len && count > 0) {
        ret = true;
    }    
    return ret;
}


bool is_date_string(const char* s)
{
#ifdef VERBOSE0
    cout << "is_date_string(s=" << s << ")" << endl;
    cout.flush();
#endif // VERBOSE0
    int len;
    int max_mday[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int year;
    int month;
    int mday;
    int hour;
    int minute;
    int second;

    len = strlen(s);
    if (len % 2 == 1 || len < 4 || len > 14 || is_digit_string(s) == false)
        return false;
    
    year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + 
        (s[2] - '0') * 10 + (s[3] - '0');
    if (year == 0)
        return false;
    if (len >= 6) {
        month = (s[4] - '0') * 10 + (s[5] - '0');
        if (month == 0 || month > 12) 
            return false;
        if (len >= 8) {
            mday = (s[6] - '0') * 10 + (s[7] - '0');
            if (mday == 0 || mday > max_mday[month - 1]) 
                return false;
            if (len >= 10) {
                hour = (s[8] - '0') * 10 + (s[9] - '0');
                if (hour > 23) 
                    return false;
                if (len >= 12) {
                    minute = (s[10] - '0') * 10 + (s[11] - '0');
                    if (minute > 59)
                        return false;
                    if (len == 14) {
                        second = (s[12] - '0') * 10 + (s[13] - '0');
                        if (second > 59)
                            return false;
                    }
                }
            }
        }
    }

    return true;
}


bool is_date_string(const string& s)
{
    return is_date_string(s.c_str());
}


time_t get_ts_from_HHMISS(const string& time_str)
{
    int hour;
    int min;
    int sec;

    if (time_str.length() != 6 ||
        is_digit_string(time_str) == false ||
        sscanf(time_str.c_str(), "%02d%02d%02d", &hour, &min, &sec) < 3 ||
        hour < 0 || hour > 23 || min < 0 || min > 59 || sec < 0 || sec > 59) {
#ifdef VERBOSE0
        cerr << "can't parse six digit string" << endl;
#endif // VERBOSE0
        return -1;
    }

    return (time_t) (hour * 60 + min) * 60 + sec;
}


time_t get_ts_from_HHMISS(const char* time_str)
{
    int hour;
    int min;
    int sec;

    if (time_str == NULL ||
        strlen(time_str) != 6 ||
        is_digit_string(time_str) == false ||
        sscanf(time_str, "%02d%02d%02d", &hour, &min, &sec) < 3 ||
        hour < 0 || hour > 23 || min < 0 || min > 59 || sec < 0 || sec > 59) {
#ifdef VERBOSE0
        cerr << "can't parse six digit string" << endl;
#endif // VERBOSE0
        return -1;
    }

    return (time_t) (hour * 60 + min) * 60 + sec;
}


time_t get_current_HHMISS_ts(void)
{
    time_t t;
    struct tm* tm_p;
    
    if (time(&t) < 0) {
#ifdef VERBOSE0
        cerr << "can't get current timestamp, " << errno << ": "
             << strerror(errno) << endl;
#endif // VERBOSE0
        return -1;
    }
    
    tm_p = localtime(&t);
    if (tm_p == NULL) {
#ifdef VERBOSE0
        cerr << "can't get localtime info from current timestamp, "
             << errno << ": " << strerror(errno) << endl;
#endif // VERBOSE0
        return -1;
    }
    
    return (time_t) (tm_p->tm_hour * 60 + tm_p->tm_min) * 60 + tm_p->tm_sec;
}


string get_HHMISS_from_ts(const time_t ts)
{
    int hour;
    int minute;
    int second;
    char buf[80] = { 0, };

    if (ts < 0 || ts >= 86400)
        return "";

    hour = ts / 3600;
    minute = (ts / 60) % 60;
    second = ts % 60;

    snprintf(buf, sizeof (buf), "%02d%02d%02d", hour, minute, second);
    return string(buf);
}


bool is_in_time_intvl(const time_t start_time, const time_t end_time, time_t t)
{
    bool ret = false;

    if (start_time <= end_time) {
        if (start_time <= t && t < end_time) {
            ret = true;
        }
    } else {
        if ((start_time <= t && t < 86400) ||
            (0 <= t && t < end_time)) {
            ret = true;
        } 
    }
    
    return ret;
}


int get_hour_from_ts(const time_t ts)
{
    return ts / 3600;
}


int get_minute_from_ts(const time_t ts)
{
    return (ts / 60) % 60;
}


int get_second_from_ts(const time_t ts)
{
    return ts % 60;
}


