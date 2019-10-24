#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>

//#define VERBOSE

#define MAXLINE 2048
#define TOKENIZER "\t"
#define RTOKENIZER "^"
#define MAXQUERY 128

using namespace std;

typedef struct _basis_data {
    int segment_num;
    double mean;
    int yester_uipcnt;
    double std_dev;
    double past_abuse_discount;
    int mean_rank;
} basis_data_t;

typedef pair<int, string> int_str_pa_t;
typedef pair<double, string> double_str_pa_t;
typedef pair<string, string> str_str_pa_t;
typedef pair<string, int> str_int_pa_t;
typedef pair<string, double> str_double_pa_t;

typedef priority_queue<int_str_pa_t, deque<int_str_pa_t>, 
    greater<int_str_pa_t> > int_str_minheap_t;
typedef priority_queue<int_str_pa_t, deque<int_str_pa_t>, 
    less<int_str_pa_t> > int_str_maxheap_t;
typedef priority_queue<double_str_pa_t, deque<double_str_pa_t>,
    greater<double_str_pa_t> > double_str_minheap_t;
typedef priority_queue<double_str_pa_t, deque<double_str_pa_t>,
    less<double_str_pa_t> > double_str_maxheap_t;

typedef vector<str_double_pa_t*> str_dbl_pa_vector_t;
typedef str_dbl_pa_vector_t::iterator str_dbl_pa_iter_t;

typedef unordered_map<string, basis_data_t> str_basis_map_t;
typedef str_basis_map_t::iterator str_basis_iter_t;
typedef unordered_map<string, int> str_int_map_t;
typedef str_int_map_t::iterator str_int_iter_t;
typedef unordered_map<string, string> str_str_map_t;
typedef str_str_map_t::iterator str_str_iter_t;
typedef unordered_map<string, double> str_double_map_t;
typedef str_double_map_t::iterator str_double_iter_t;
typedef unordered_map<string, int_str_pa_t> str_pa_map_t;
typedef str_pa_map_t::iterator str_pa_iter_t;
typedef unordered_map<string, bool> str_bool_map_t;
typedef str_bool_map_t::iterator str_bool_iter_t;

typedef unordered_set<string> str_set_t;
typedef str_set_t::iterator str_set_iter_t;

// query statistics
typedef struct _query_stat {
    string reprquery;
    int uipcnt;
    int qc;
    int auipcnt;
    int aqc;
    int luipcnt;
    int lqc;
} query_stat_t;
typedef unordered_map<string, query_stat_t> str_stat_map_t;
typedef str_stat_map_t::iterator str_stat_iter_t;

// query prediction indexes
typedef struct _query_pred {
    // prediction
    double past_abuse_discount;
    double current_abuse_discount;
    double live_discount;
    double prediction;
    // score
    double mean;
    double std_dev;
    // others
    int pred_rank;
    int mean_rank;
    int segment_num;
    int uipcnt_rank;
    double rank_velocity;
} query_pred_t;
typedef unordered_map<string, query_pred_t> str_pred_map_t;
typedef str_pred_map_t::iterator str_pred_iter_t;

typedef struct _cnts_all {
    int uipcnt;
    int qc;
    int auipcnt;
    int aqc;
    int luipcnt;
    int lqc;
} cnts_all_t;
typedef unordered_map<string, cnts_all_t> str_cntsall_map_t;
typedef str_cntsall_map_t::iterator str_cntsall_iter_t;

typedef struct _cnts {
    int qc;
    int uipcnt;
    int aqc;
    int auipcnt;
} cnts_t;
typedef map<string, cnts_t, less<string> > str_cnts_map_t;
typedef str_cnts_map_t::iterator str_cnts_iter_t;

typedef struct _cnts_24h {
    int qc[24];
    int uipcnt[24];
    int aqc[24];
    int auipcnt[24];
    int total_qc;
    int total_uipcnt;
    int total_aqc;
    int total_auipcnt;
} cnts_24h_t;
typedef unordered_map<string, cnts_24h_t> str_cnts24h_map_t;
typedef str_cnts24h_map_t::iterator str_cnts24h_iter_t;

typedef struct _triple {
    string query;
    int file_num;
    cnts_t cnts;
} triple_t;
typedef struct _triple_cmp {
    bool operator()(const triple_t& a, const triple_t& b) {
        return a.query > b.query;
    }
} triple_cmp_t;
typedef priority_queue<triple_t, deque<triple_t>, 
    triple_cmp_t > triple_minheap_t;

// default values for configuration
const string default_result_dir = "/maple/result";
const int default_display_size = 10;

#endif // _COMMON_H_
