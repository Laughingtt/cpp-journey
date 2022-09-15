//
// Created by tian on 2022/6/30.
//

#include "iostream"
#include "string"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        vector<string> res;
        map<string, int> name_dict;
        for (int i = 0; i < list1.size(); ++i) {
            for (int j = 0; j < list2.size(); ++j) {
                if (list1[i] == list2[j]) {
                    name_dict[list1[i]] = i + j;
                }
            }
        }
        string min_count_name = "null";
        map<string, int>::iterator iter;
        for (iter = name_dict.begin(); iter != name_dict.end(); ++iter) {
            cout << iter->first << " " << iter->second << endl;
            if (min_count_name == "null") {
                min_count_name = iter->first;
            } else {
                if (iter->second < name_dict[min_count_name]) {
                    min_count_name = iter->first;
                }
            }
        }
        for (iter = name_dict.begin(); iter != name_dict.end(); ++iter) {
            if (iter->second == name_dict[min_count_name]) {
                res.push_back(iter->first);
            }
        }

        return res;
    }
};


int main() {
    Solution s;
    vector<string> lis1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> lis2 = {"Piatti", "The Grill at Torrey Pines", "Tapioca Express", "Shogun"};
    vector<string> r = s.findRestaurant(lis1, lis2);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }
    return 0;
}