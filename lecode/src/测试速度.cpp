//
// Created by tian on 2022/7/12.
//


#include "iostream"
#include "string"
#include "ctime"
#include "vector"

using namespace std;

class Test {
public:
    int test_string() {
        vector<string> str_lis(8000, "2");
        vector<string> res;


        for (int i = 0; i < 609*13; ++i) {
            string str;
//            str.push_back();
            if (i%13==0){
                res.push_back(str);
            }else{
                str.push_back(i);
            }
        }

        return 0;

    }
};


int main() {
    Test s = Test();
    clock_t start = clock();
    int r = s.test_string();
    clock_t end = clock();
    double endtime = (double) (end - start) / CLOCKS_PER_SEC;
    std::cout << endtime << std::endl;
    cout << r << endl;
}