#include <iostream>

#pragma once

#include <vector>
#include <string>
//#include <cstdint>
#include <sstream>
#include <iomanip>

using namespace std;

const static int FLOAT_PRECISION_DEFAULT = 16;

typedef unsigned __int128 uint128_t;
typedef __int128 int128_t;
typedef uint128_t mpc_t;
typedef uint8_t small_mpc_t;
typedef int128_t signed_mpc_t;
typedef uint8_t bit_t;
//
//typedef uint64_t mpc_t;
//typedef uint8_t small_mpc_t;
//typedef int64_t signed_mpc_t;
//typedef uint8_t bit_t;

template<typename T>
mpc_t FloatToMpcType(T a, int precision) {
    return ((mpc_t) (
            (((signed_mpc_t) (a)) << precision) +
            (signed_mpc_t) (((a) - (signed_mpc_t) (a)) * (1L << precision))));
}

template<typename T>
double MpcTypeToFloat(T a, int precision) {
    return ((double((signed_mpc_t) (a))) / (1L << precision));
}

void print_d_to_s() {
    double d = 3.1415926535897932384;
    std::string str = std::to_string(d);
    std::cout << str << std::endl; // 3.141593

    std::stringstream ss;
    ss << std::setprecision(15) << d;
    str = ss.str();
    std::cout << str << std::endl; //3.14159265358979
}

void bit_print() {
    int precision = 40;

    double a = 3.14, b = 5.12;
    mpc_t mpa = FloatToMpcType(a, precision);
    mpc_t mpb = FloatToMpcType(b, precision);

    double doa = MpcTypeToFloat(mpa, precision);
    double dob = MpcTypeToFloat(mpb, precision);

    double res = doa / dob;

    std::cout << "plain div is :" << double(a) / double(b) << std::endl;
    std::cout << "std to_string 保留6位小数" << std::to_string(res) << std::endl;
    std::stringstream ss;
    ss << std::setprecision(20) << res;
    std::cout << "std stringstream 保留16位小数" << ss.str() << std::endl;

//    print_d_to_s();
}

void create_rand() {
    int size = 3;
    vector<mpc_t> A(size, 0), B(size, 0), R1(size, 0);
    for (int i = 0; i < size; ++i) {
        A[i] = (rand() % 10000);
        R1[i] = (rand() % 10000);
        B[i] = A[i] * R1[i];
//        cout << A[i] << " " << R1[i] << " " << B[i] << endl;
    }
}

void convert_double_to_literal_str(const vector<int> &a, vector<string> &b) {
    b.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        b[i] = std::to_string(a[i]);
}

void int_to_str() {
    vector<int> R1 = {1, 2, 3, 4, 5};
    vector<string> literalR1;
    literalR1.resize(R1.size()); // 若没有分配地址则会出现段错误
    for (int i = 0; i < R1.size(); i++) {
        literalR1[i] = std::to_string(R1[i]);
        std::cout << "transfer str  " << std::to_string(R1[i]) << std::endl;

    }
//    convert_double_to_literal_str(R1,literalR1);
    cout << literalR1[0] << endl;

}

int create_random() {
    srand((int) time(0));
    int r = rand() % 20000 - 10000;
    if (r == 0) {
        r = rand() % 10000 + 1;
    }
    return r;
}

int main() {
    long r = create_random();
    cout << r << endl;
    return 0;
}
