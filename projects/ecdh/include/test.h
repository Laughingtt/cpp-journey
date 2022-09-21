//
// Created by tian on 2022/9/20.
//

#ifndef ECDH_TEST_H
#define ECDH_TEST_H

#include "ecc.h"
#include "vector"
#include "ecc_encrypt.h"
#include "ctime"
#include "hash.h"
#include "ecc_oblivious_transfer.h"

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

        mpz_class p0, p1;
        p0 = "99023490166718961467148584643029653267652245207820783364668071358307234645801";
        p1 = "75362751621984629832705305750958516370071248757681753180287377123479199292501";


        if (R[0] == p0 && R[1] == p1) {
            cout << "test_ecc_mul accuracy success" << endl;
        } else {
            cout << "R[0] :" << R[0] << endl;
            cout << "R[1] :" << R[1] << endl;
        }

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
        vector<mpz_class> enc_msg = ecc_encrypt.encrypt("hello");
        ecc_encrypt.decrypt(enc_msg);

        clock_t start = clock();
        for (int i = 0; i < 10000; ++i) {
            ecc_encrypt.encrypt("hello");
        }
        clock_t end = clock();
        cout << "programTimes is :" << ((double) end - start) / CLOCKS_PER_SEC << endl;

    }

    void test_hash() {
        HashString hash_string("md5");
        clock_t start = clock();
        for (int i = 0; i < 10000; ++i) {
            hash_string.run("hello");
        }
        clock_t end = clock();
        cout << "test_hash programTimes is :" << ((double) end - start) / CLOCKS_PER_SEC << endl;
//        cout << "md5 :" << hash_string.run("hello") << endl;
//        cout << "sha256 :" << Hash::sha256("hello") << endl;
//        cout << "sha512 :" << Hash::sha512("hello") << endl;
    }

    void test_hash_curve() {
        cout << "=== test_hash_curve func ===" << endl;
        vector<mpz_class> msg_point = ecc->hash_to_curve("hello");
        mpz_class p0, p1;
        p0 = "20329878786436204988385760252021328656300425018755239228739303522659023427621";
        p1 = "35028142331614638340248087792986616819121701108340890405919251062981357323303";
        if (msg_point[0] == p0 && msg_point[1] == p1) {
            cout << "test_hash_curve accuracy success" << endl;
        } else {
            cout << "hello point [0] " << msg_point[0] << endl;
            cout << "hello point [1] " << msg_point[1] << endl;
        }
    }

    void test_ot() {
        EccObliviousTransfer ecc_ot_sender = EccObliviousTransfer();
        EccObliviousTransfer ecc_ot_receiver = EccObliviousTransfer();

        unsigned int msg_length = 5;
        unsigned int choice = 3;

        vector<string> public_key_str = ecc_ot_sender.get_public_key();
//
//        // p1 send pubk to rec and p2 compute k
        vector<string> B_random_k = ecc_ot_receiver.receiver_compute_k(public_key_str, choice);
//
//        // p2 -> p1 B_random_k and get p1 secret_key_list
        vector<string> secret_key_list = ecc_ot_sender.sender_compute_secret_list(B_random_k, msg_length);
//
//        // p2 get secret_key_list
        string secret_key = ecc_ot_receiver.receiver_compute_secret_key(public_key_str);

        for (int i = 0; i < msg_length; ++i) {
            cout << "secret_key_list[choice] :" << i << " " << secret_key_list[i] << endl;
        }

        cout << "secret_key :choice " << choice << " " << secret_key << endl;
    }

};


#endif //ECDH_TEST_H
