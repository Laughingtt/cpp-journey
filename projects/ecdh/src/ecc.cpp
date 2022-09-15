//
// Created by tian on 2022/9/14.
//

#include "ecc.h"

void ECC::get_random_mpz(mpz_t mpz_r) {
    clock_t time = clock();
    gmp_randstate_t random_state;

    // 随机状态初始化
    gmp_randinit_mt(random_state);
    // 将初始种子设置到state
    gmp_randseed_ui(random_state, time);
    // 生成一个范围为0到2^n-1（含）的均匀分布的随机整数，赋值到 r
    mpz_urandomb(mpz_r, random_state, 256);
    //        mpz_init_set_str(mpz_r, "16", 10);
    cout << "random_state is :" << mpz_r << endl;

}

void ECC::test_gmp() {
    mpz_t a, b, c;

    // 初始化a
    mpz_init(a);

    // 初始化 b, 16进制
    mpz_init_set_str(b, "fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f", 16);
    gmp_printf("b: %Zd\n", b);

    // 初始化 c ,10进制
    mpz_init_set_str(c, "16", 10);
    gmp_printf("c : %Zd\n", c);

    // a = b-c
    mpz_sub(a, b, c);
    gmp_printf("a=b-c : %Zd\n", a);

    // mpz_t -> mpz_class
    mpz_class a_class(a);
    cout << "mpz_t -> mpz_class :  " << a_class << "\n";

    // mpz_class - > mpz_t
    gmp_printf("mpz_class - > mpz_t : %Zd\n", a_class.get_mpz_t());

    mpz_t mpz_r;
    // 一定要初始化mpz
    mpz_init(mpz_r);
    ECC::get_random_mpz(mpz_r);

    cout << "random_state is :" << mpz_r << endl;

    mpz_class x, y;
    mpz_class ff;
    int e = 100;
    x = "-331414141432233333445453333333333322222333123";
    y = "-342389238";
    ff = y * y - x * x * x - e * x;
    cout << "mpz class sum is :  " << ff << "\n";

}