#include "iostream"
// #include <time.h>
#include "gmp.h"
#include <gmpxx.h>
#include "vector"
// #include "random"
// #include <ctime> // Header file needed to use time

using namespace std;
typedef unsigned long long uint64;

vector<int> Transform(int n) {
    vector<int> m;
    for (int i = 64; i >= 0; i--) {
        m.push_back(((n >> i) & 1)); //与1做位操作，前面位数均为0
        cout << ((n >> i) & 1);      //输出二进制
    }
    cout << endl;
    return m;
}

void print_uint64(gmp_randstate_t random_state_interation, int n) {
    for (size_t i = 0; i < n; i++) {
        // 返回一个均匀分布的n位随机数，即在 0 到2^ n -1范围内（含）。 n必须小于或等于 a 中的位数unsigned long。
        uint64 a = gmp_urandomb_ui(random_state_interation, 64);
        cout << a << endl;
        Transform(a);
    }
}

void test_gmp() {
    gmp_randstate_t random_state_interation;

    // 初始化mpz_t 大整数
    mpz_t random_seed;
    mpz_init_set_str(random_seed, "123", 10);

    gmp_printf("%Zd\n", random_seed);

    // 随机状态初始化
    gmp_randinit_mt(random_state_interation);
    // 	随机状态播种
    gmp_randseed(random_state_interation, random_seed);

    print_uint64(random_state_interation, 5);

    uint64 mod_length = 312122;
    cout << mod_length << endl;
    cout << 1UL << endl;
    // 1UL代表1

    uint64 bf_size = (1UL << mod_length);
    cout << bf_size << endl;
    Transform(bf_size);
}

void test_random() {
    // Set the random generator seed before calling rand()
    srand((unsigned) time(NULL));

    for (size_t i = 0; i < 10; i++) {
        cout << rand() << endl;
    }
}

void test_bin() {
    int a = ~(2 ^ 1);
    cout << a << endl;
    Transform(a);
}

void test_gmp_num() {
    mpz_t a, b, c;
    mpz_init(a);
    mpz_init_set_str(b, "fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f", 16);
    gmp_printf("%Zd\n", b);
//
//    mpz_init_set_str(c, "16", 10);
//    gmp_printf("%Zd\n", c);
//    mpz_sub(a,b,c);
//    gmp_printf("%Zd\n", a);

    gmp_randstate_t random_state;
    // 随机状态初始化
    gmp_randinit_mt(random_state);
    mpz_urandomb(a, random_state, 256);
    cout << a << endl;

    mpz_class e, d, f;

    mpz_class ff;
    e = 1123;
    d = "-331414141432233333445453333333333322222333123";
    f = e + d;
    cout << "sum is " << f << "\n";

}

int main(int argc, char const *argv[]) {
    test_gmp_num();
    return 0;
}
