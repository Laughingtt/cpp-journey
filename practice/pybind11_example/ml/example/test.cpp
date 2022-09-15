//
// Created by tian on 2022/5/9.
//

#include "iostream"
#include "ctime"

void add() {
    int r=0;
    for (int i = 0; i < 100000000; ++i) {
        r = i + r;
    }
}

int main() {
    clock_t start = clock();
    add();
    clock_t end = clock();
    double endtime = (double) (end - start) / CLOCKS_PER_SEC;
    std::cout << endtime << std::endl;

}