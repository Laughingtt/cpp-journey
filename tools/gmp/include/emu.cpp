#include <iostream>
#include "emu.h"
using namespace std;


void test(){
    Side s = Side::Right;
    Side w = Side::Right;
    cout << (s == Side::Left) << endl; //编译错误，无法直接比较不同枚举类
    cout << (0 == (int)s) << endl;
}

void test02(Side *arr){
    arr[0] = Side::Right;
}

int main()
{
    Side *arr;
    test02(arr);
    cout << (int)arr[0] << endl;
    return 0;
}