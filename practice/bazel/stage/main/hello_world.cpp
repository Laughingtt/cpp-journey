//
// Created by tian on 2022/10/17.
//

#include "iostream"

using namespace std;

std::string get_greet(const std::string &who) {
    return "Hello " + who;
}

int main() {
    cout << "hello world" << endl;
    cout << "hello world" << endl;
    cout << get_greet("tianjian") << endl;
    return 1;
}