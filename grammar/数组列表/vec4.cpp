#include <iostream>
#include "test_for.h"
#include "vector_test.h"
#include "dict_test.h"

void test_01() {
    test_for(1000);
    test_char();
}

vector<int> create_vec(int n) {
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            vec.push_back(i);
        }
    }
    return vec;
}


map<string, string> create_map(int n) {
    map<string, string> map1;
    for (int i = 0; i < n; ++i) {
//        cout << to_string(i) + ":hello" << endl;
        map1[to_string(i)] = "hello:" + to_string(i);
    }
    return map1;
}

map<string, vector<int>> create_map2(int n) {
    map<string, vector<int>> map1;
    vector<int> vec = {1, 2, 3, 5, 6};
    for (int i = 0; i < n; ++i) {
        map1[to_string(i)] = vec;
    }
    return map1;
}

void print_dict2(map<string, vector<int>> &map_dict) {
    map<string, vector<int>>::iterator it;
    for (it = map_dict.begin(); it != map_dict.end(); it++) {
        cout << it->first << " " << endl;//输出key 和value值
        for (auto i:it->second) {
            cout << i << endl;
        }
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;

//    vec
    vector<int> vec = create_vec(100);
    VecT::print_vector(vec);

//    dict
    map<string, string> map1 = create_map(10);
    DicT::print_dict(map1);

//    dic2
    map<string, vector<int>> map2 = create_map2(10);
    DicT::print_dict2(map2);

}
