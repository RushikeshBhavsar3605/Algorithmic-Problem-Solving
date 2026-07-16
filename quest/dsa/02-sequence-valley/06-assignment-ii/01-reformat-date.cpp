#include "template.hpp"

/* Approach 1 (Naive):
class Solution {
  public:
    string reformatDate(string date) {
        umap<string, string> days = {{"1st", "01"},  {"2nd", "02"},  {"3rd", "03"},  {"4th", "04"},  {"5th", "05"},
                                     {"6th", "06"},  {"7th", "07"},  {"8th", "08"},  {"9th", "09"},  {"10th", "10"},
                                     {"11th", "11"}, {"12th", "12"}, {"13th", "13"}, {"14th", "14"}, {"15th", "15"},
                                     {"16th", "16"}, {"17th", "17"}, {"18th", "18"}, {"19th", "19"}, {"20th", "20"},
                                     {"21st", "21"}, {"22nd", "22"}, {"23rd", "23"}, {"24th", "24"}, {"25th", "25"},
                                     {"26th", "26"}, {"27th", "27"}, {"28th", "28"}, {"29th", "29"}, {"30th", "30"},
                                     {"31st", "31"}};
        umap<string, string> months = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
                                       {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
                                       {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};

        stringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;

        return string(year + '-' + months[month] + '-' + days[day]);
    }
};
*/

/* Approach 2 (Optimal): */
class Solution {
  public:
    string reformatDate(string date) {
        umap<string, string> month = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
                                      {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
                                      {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};

        string day, mon, year;
        stringstream(date) >> day >> mon >> year;

        day = day.substr(0, sz(day) - 2);
        if (sz(day) == 1)
            day = "0" + day;

        return year + "-" + month[mon] + "-" + day;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.reformatDate("20th Oct 2052");
    print(res);
    res = obj.reformatDate("6th Jun 1933");
    print(res);
    res = obj.reformatDate("26th May 1960");
    print(res);
    return 0;
}

/*
Problem: Reformat Date
*/