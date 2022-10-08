//
// Created by tian on 2022/9/20.
//

#ifndef ECDH_TEST_GMP_H
#define ECDH_TEST_GMP_H

#include "gmp.h"
#include "gmpxx.h"

class TestGmp {
public:
    static void test_gmp() {
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
        int bit_len = 256;
        ECC::get_random_mpz(mpz_r, bit_len);

        cout << "random_state is :" << mpz_r << endl;

        mpz_class x, y;
        mpz_class ff;
        int e = 100;
        x = "-331414141432233333445453333333333322222333123";
        y = "-342389238";
        ff = y * y - x * x * x - e * x;
        cout << "mpz class sum is :  " << ff << "\n";

        mpz_class r, n, d;
        n = "-11291920192";
        d = "363634";
        mpz_mod(r.get_mpz_t(), n.get_mpz_t(), d.get_mpz_t());
        cout << "mpz_mod(r,n,d) " << r << endl;
        cout << "n%d" << n % d << endl;


    }
};

#endif //ECDH_TEST_GMP_H
