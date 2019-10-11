#include <iostream>
#include <fstream>
#include <sstream>

#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <getopt.h>
#include <time.h>

#include "common.h"
#include "util.h"

using namespace std;

const string default_input_dir = "/maple/basis_min_test";
const string default_output_dir = "/maple/basis_daily";


void print_usage(string program_name)
{
    cout << "Usage: " << program_name << " [-h] [-d <date_str>] "
         << "-i <basis_min_dir>" << endl;
    cout << "\t\t\t-o <basis_daily_dir> <tab_name>" << endl << endl;;
    cout << "-h\t\t\t\tThis help message" << endl << endl;
    cout << "-d <date_str>\t\t\tDate in 8 digit string" << endl;
    cout << "--date=<date_str>" << endl << endl;
    cout << "-i <basis_daily_dir>\t\tInput(daily) file directory" << endl;
    cout << "--input=<basis_daily_dir>" << endl << endl;
    cout << "-o <basis_daily_dir>\t\tOutput(weekly) file directory" <<
        endl;
    cout << "--output=<basis_daily_dir>" << endl << endl;
    cout << endl;
}


int main(int argc, char *argv[])
{
#ifdef VERBOSE
    cout << "main()" << endl;
    cout.flush();
#endif				// VERBOSE

    string basis_min_dir;
    string basis_min_file_path;
    char *filename;
    char line[MAXLINE];
    char *token;
    char *lasts;
    char delimiter_str[] = TOKENIZER;
    DIR *dir_p;
    struct dirent *dirent_p;
    str_cnts_map_t query_cnts_map;
    str_cnts_iter_t query_cnts_iter;
    string query;
    cnts_t cnts;
    int c;
    int option_index = 0;
    const struct option long_options[] = {
        {"date", 1, 0, 0},
        {"inputdir", 1, 0, 0},
        {"outputdir", 1, 0, 0},
        {"help", 0, 0, 0},
    };
    string date_str = "";
    string input_dir = default_input_dir;
    string output_dir = default_output_dir;
    string tab_name = "";

    while (1) {
        c = getopt_long(argc, argv, "d:i:o:h", long_options,
                        &option_index);
        if (c == -1)
            break;
        switch (c) {
        case 'd':
            date_str = optarg;
            break;

        case 'i':
            input_dir = optarg;
            break;

        case 'o':
            output_dir = optarg;
            break;

        case 'h':
        default:
            print_usage(argv[0]);
            return -1;
        }
    }
#ifdef VERBOSE
    cout << "optind=" << optind << ", argc=" << argc << endl;
#endif				// VERBOSE
    if (optind + 1 != argc || input_dir == "" || output_dir == "") {
        print_usage(argv[0]);
        return -1;
    }
    tab_name = argv[optind];
    if (date_str == "") {
        // yesterday
        char buf[80];
        time_t t;
        struct tm *tm_p;
        if (time(&t) < 0) {
            cerr << "can't get current timestamp, " << errno << ": "
                 << strerror(errno) << endl;
            return -1;
        }
        t = ((t - 86400) / 86400) * 86400;
        if ((tm_p = localtime(&t)) == NULL) {
            cerr << "can't get local time information, " << errno << ": "
                 << strerror(errno) << endl;
            return -1;
        }
        if (strftime(buf, sizeof(buf), "%Y%m%d", tm_p) == 0) {
            cerr << "can't get date string from time information, "
                 << errno << ": " << strerror(errno) << endl;
            return -1;
        }
        date_str = buf;
    }
    if (date_str.length() != 8 || is_date_string(date_str) == false) {
        print_usage(argv[0]);
        cout << "* invalid date string" << endl << endl;
        return -1;
    }

    int total_qc = 0;
    int total_uipcnt = 0;
    ofstream daily_fstrm;
    int hour;
    int filename_hour;
    string hour_str = "";

    basis_min_dir = input_dir + "/" + tab_name;
    dir_p = opendir(basis_min_dir.c_str());
    if (dir_p == NULL) {
        cerr << "can't open directory '" << basis_min_dir << "', "
             << errno << ": " << strerror(errno) << endl;
        return -1;
    }
    for (hour = 0; hour < 24; ++hour) {
        stringstream ss;
        if (hour < 10) {
            ss << "0";
            ss << hour;
        } else {
            ss << hour;
        }
        ss >> hour_str;
        string basis_daily_file_path =
            output_dir + "/" + tab_name + "/" + date_str + hour_str;
#ifdef VERBOSE
        cout << "main()...basis_daily_file_path='" << basis_daily_file_path
             << "'" << endl;
#endif				// VERBOSE
        daily_fstrm.open(basis_daily_file_path.c_str());

        while ((dirent_p = readdir(dir_p)) != NULL) {
            filename = dirent_p->d_name;
            if (strlen(filename) != 14
                || is_digit_string(filename) == false
                || strncmp(filename, date_str.c_str(), 8)) {
                continue;
            }
            filename_hour = (filename[8] - '0') * 10 + (filename[9] - '0');
            if (filename_hour != hour)
                continue;

            basis_min_file_path = basis_min_dir + "/" + filename;
#ifdef VERBOSE
            cout << "main()...basis_min_file_path='" << basis_min_file_path
                 << "'" << endl;
#endif				// VERBOSE
            ifstream basis_min_fstrm(basis_min_file_path.c_str());
            if (basis_min_fstrm.is_open() == false) {
                cerr << "can't open basis-min file '" << filename
                     << "', " << errno << ": " << strerror(errno) << endl;
                continue;
            }
            while (basis_min_fstrm.good() == true) {
                basis_min_fstrm.getline(line, sizeof(line));

                // timestamp
                token = strtok_r(line, delimiter_str, &lasts);
                if (token == NULL)
                    continue;
                // query
                token = strtok_r(NULL, delimiter_str, &lasts);
                if (token == NULL)
                    continue;
                query = token;
                // sm
                token = strtok_r(NULL, delimiter_str, &lasts);
                if (token == NULL)
                    continue;
                if (!((!strncmp(token, "tab_", 4) ||
                       !strncmp(token, "top_", 4)) &&
                      (!strncmp(&token[4], "hty", 3) ||
                       !strncmp(&token[4], "sug", 3) ||
                       !strncmp(&token[4], "pat", 3) ||
                       !strncmp(&token[4], "lve", 3)))) {
                    continue;
                }
                // qc
                token = strtok_r(NULL, delimiter_str, &lasts);
                if (token == NULL)
                    continue;
                cnts.qc = atoi(token);
                // uipcnt
                token = strtok_r(NULL, delimiter_str, &lasts);
                if (token == NULL)
                    continue;
                cnts.uipcnt = atoi(token);

                query_cnts_iter = query_cnts_map.find(query);
                if (query_cnts_iter != query_cnts_map.end()) {
                    query_cnts_iter->second.qc += cnts.qc;
                    query_cnts_iter->second.uipcnt += cnts.uipcnt;
                } else {
                    query_cnts_map.insert(make_pair(query, cnts));
                }
            }			// while (basis_min_fstrm
            basis_min_fstrm.close();
        }			// while (dirent_p = readdir
        rewinddir(dir_p);

        for (query_cnts_iter = query_cnts_map.begin();
             query_cnts_iter != query_cnts_map.end(); ++query_cnts_iter) {
            query = query_cnts_iter->first;
            cnts = query_cnts_iter->second;

            daily_fstrm << query << '\t' << cnts.qc << '\t'
                        << cnts.uipcnt << endl;
#ifdef VERBOSE0
            cout << query << '\t' << query_hour << '\t' << cnts.qc << '\t'
                 << cnts.uipcnt << endl;
#endif				// VERBOSE0
            total_qc += cnts.qc;
            total_uipcnt += cnts.uipcnt;
        }
        daily_fstrm.close();
    }				// for (hour = 0

#ifdef VERBOSE
    cout << "total_qc=" << total_qc << endl;
    cout << "total_uipcnt=" << total_uipcnt << endl;
#endif				// VERBOSE

    return 0;
}
