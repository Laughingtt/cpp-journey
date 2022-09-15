//
// Created by tian on 2022/4/11.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    /**
     * @param words: the words
     * @param S: the string
     * @return: the string with least number of tags
     */
    string boldWords(vector<string> &words, string &S) {
        // Write your code here
        string res;

        cout << S << endl;
    }
};


int main() {
    Solution s;
    vector<string> words = {"ab", "bc"};
    string S = "aabcd";
    s.boldWords(words, S);
    return 0;
}