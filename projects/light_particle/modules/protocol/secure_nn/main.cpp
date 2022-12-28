//
// Created by tian on 2022/12/23.
//

#include "iostream"
#include "modules/io/mpc_common.h"
#include <sstream>
#include <iomanip>

using namespace std;

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

    // 输出bit位
    cout << bitset<128>(mpa) << endl;//输出128位
    cout << bitset<128>(-mpa) << endl;//输出128位

//    print_d_to_s();
}

int main() {

    cout << " Hello World" << endl;

    bit_print();
    return 0;
}