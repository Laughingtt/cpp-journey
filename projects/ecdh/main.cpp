#include "iostream"
#include "ecc.h"
#include "vector"
#include "EccEncrypt.h"
#include "ctime"

using namespace std;

class Test {
private:
    ECC *ecc = new ECC();
    ECC *ecc2 = new ECC();
public:
    Test() {
        ecc->generate_point();
        ecc2->generate_point();
    }

    ~Test() {
        delete ecc;
        delete ecc2;
    }

    void test() {};

    void test_get_key() {
        cout << "=== test_get_key func ===" << endl;
        vector<mpz_class> pub = ecc->get_public_key();
        cout << "pub[0] is: " << pub[0] << endl;
        cout << "pub[1] is: " << pub[1] << endl;

        mpz_class pri = ecc->get_private_key();
        cout << "pri is: " << pri << endl;
    }


    void test_ecc_mul() {
        cout << "=== test_ecc_mul func ===" << endl;
        vector<mpz_class> P(2);
        P[0] = "55066263022277343669578718895168534326250603453777594175500187360389116729240";
        P[1] = "32670510020758816978083085130507043184471273380659243275938904335757337482424";
        vector<mpz_class> R(2);
        mpz_class k = 27;
        ecc->ecc_mul(P, k, R);
        cout << "R[0] :" << R[0] << endl;
        cout << "R[1] :" << R[1] << endl;

    }

    void test_ecc_add() {
        cout << "=== test_ecc_add func ===" << endl;
        vector<mpz_class> P(2);
        P[0] = "55066263022277343669578718895168534326250603453777594175500187360389116729240";
        P[1] = "32670510020758816978083085130507043184471273380659243275938904335757337482424";
        vector<mpz_class> Q(2);
        Q[0] = "89565891926547004231252920425935692360644145829622209833684329913297188986597";
        Q[1] = "12158399299693830322967808612713398636155367887041628176798871954788371653930";
        vector<mpz_class> R(2);
        ecc->ecc_add(P, Q, R);
        cout << "R[0] :" << R[0] << endl;
        cout << "R[1] :" << R[1] << endl;

    }

    void test_ecc_sub() {
        cout << "=== test_ecc_sub func ===" << endl;
        vector<mpz_class> P(2);
        P[0] = "55066263022277343669578718895168534326250603453777594175500187360389116729240";
        P[1] = "32670510020758816978083085130507043184471273380659243275938904335757337482424";
        vector<mpz_class> Q(2);
        Q[0] = "89565891926547004231252920425935692360644145829622209833684329913297188986597";
        Q[1] = "12158399299693830322967808612713398636155367887041628176798871954788371653930";
        vector<mpz_class> R(2);
        ecc->ecc_sub(P, Q, R);
        cout << "R[0] :" << R[0] << endl;
        cout << "R[1] :" << R[1] << endl;

    }

    void test_mod_inv() {
        mpz_class a, b, rr;
        a = "65341020041517633956166170261014086368942546761318486551877808671514674964848";
        b = "115792089237316195423570985008687907853269984665640564039457584007908834671663";
        rr = "-32617584047406127887053860912668548655625778953140441154984154756096705713545";
        mpz_class r = ECC::mod_inv(a, b);
        cout << "a :" << a << endl;
        cout << "b :" << b << endl;
        cout << "r :" << r << endl;
        if (r == rr) {
            cout << "mod_inv true" << endl;
        } else {
            cout << "mod_inv false" << endl;
        }
    }

    void test_key_exchange() {
        ECC ecc;
        ECC ecc2;
        ecc.generate_point();
        ecc2.generate_point();
        vector<mpz_class> pk1 = ecc.get_public_key();
        mpz_class sk1 = ecc.get_private_key();

        vector<mpz_class> pk2 = ecc2.get_public_key();
        mpz_class sk2 = ecc2.get_private_key();

        vector<mpz_class> s1(2), s2(2);
        vector<mpz_class> param_G(2);
        ecc.ecc_mul(pk2, sk1, s1);
        ecc2.ecc_mul(pk1, sk2, s2);

        if (s1 == s2) {
            cout << "dh s1 equal s2";
        } else {
            cout << "dh not equal";
            cout << "s1[0] is " << s1[0] << endl;
            cout << "s1[1] is " << s1[1] << endl;

            cout << "s2[0] is " << s2[0] << endl;
            cout << "s2[1] is " << s2[1] << endl;
        }

    }

    void test_encrypt() {
        EccEncrypt ecc_encrypt;
        ecc_encrypt.generate_key();
        vector<mpz_class> enc_msg = ecc_encrypt.encrypt();
        ecc_encrypt.decrypt(enc_msg);

        clock_t start = clock();
        for (int i = 0; i < 10000; ++i) {
            ecc_encrypt.encrypt();
        }
        clock_t end = clock();
        cout << "programTimes is :" << ((double) end - start) / CLOCKS_PER_SEC << endl;

    }

};


int main(int argc, char const *argv[]) {
    cout << "main function" << endl;

    ECC::test_gmp();

    Test test;
//    test.test_mod_inv();
    test.test_ecc_add();
    test.test_ecc_sub();
//    test.test_ecc_mul();
//    test.test_get_key();
//    test.test_key_exchange();
    test.test_encrypt();

    return 0;
}
