//
// Created by tian on 2022/9/19.
//

#include "ecc_encrypt.h"

#define random(x) rand()%(x)

void EccEncrypt::generate_key() {
    this->ecc->generate_point();
    public_key = ecc->get_public_key();
    private_key = ecc->get_private_key();

}

vector<string> EccEncrypt::get_public_key() {
    vector<string> public_key_str(2);
    this->ecc->mpz_to_string(public_key, public_key_str);

    return public_key_str;
}

string EccEncrypt::get_private_key() {
    string private_key_str;
    private_key_str = private_key.get_str();
    return private_key_str;
};

vector<string> EccEncrypt::encrypt(const string &msg) {

    vector<mpz_class> msg_point = ecc->hash_to_curve(msg);


    mpz_class mpz_r;
    ecc->get_random_mpz2(mpz_r.get_mpz_t(), ecc->bit_len);

    vector<mpz_class> c1(2);
    vector<mpz_class> c2(2);
    vector<string> RR(4);

    vector<mpz_class> param_g = ecc->get_param_g();
    ecc->ecc_mul(param_g, mpz_r, c1);
//
    ecc->ecc_mul(this->public_key, mpz_r, c2);
    ecc->ecc_add(msg_point, c2, c2);

    RR[0] = c1[0].get_str();
    RR[1] = c1[1].get_str();
    RR[2] = c2[0].get_str();
    RR[3] = c2[1].get_str();

    return RR;
}

string EccEncrypt::decrypt(const vector<string> &enc_v) {
    vector<mpz_class> c1(2);
    vector<mpz_class> c2(2);
    c1[0] = enc_v[0];
    c1[1] = enc_v[1];
    c2[0] = enc_v[2];
    c2[1] = enc_v[3];
    vector<mpz_class> R(2);
    vector<mpz_class> R2(2);
    string dec_res;
    ecc->ecc_mul(c1, this->private_key, R);
    ecc->ecc_sub(c2, R, R2);

//    cout << "R2[0]" << R2[0] << endl;
//    cout << "R2[1]" << R2[1] << endl;

    dec_res = R2[0].get_str();
    dec_res += R2[1].get_str();
    dec_res = ecc->hash_string->run(dec_res);

    return dec_res;

}

string EccEncrypt::encrypt_serialize(const string &msg) {
    vector<mpz_class> msg_point = ecc->hash_to_curve(msg);

    mpz_class mpz_r;
    ecc->get_random_mpz2(mpz_r.get_mpz_t(), ecc->bit_len);

    vector<mpz_class> c1(2);
    vector<mpz_class> c2(2);
    vector<string> RR(4);

    vector<mpz_class> param_g = ecc->get_param_g();
    ecc->ecc_mul(param_g, mpz_r, c1);
    //
    ecc->ecc_mul(this->public_key, mpz_r, c2);
    ecc->ecc_add(msg_point, c2, c2);

    RR[0] = c1[0].get_str();
    RR[1] = c1[1].get_str();
    RR[2] = c2[0].get_str();
    RR[3] = c2[1].get_str();

    tutorial::CurvePoint curve_point;
    curve_point.mutable_point_list()->CopyFrom({RR.begin(), RR.end()});
    string s;
    curve_point.SerializeToString(&s);

    //    cout << "s is " << s << endl;
    return s;

}

string EccEncrypt::decrypt_deserialize(const string &sen) {
    tutorial::CurvePoint rs_curve_point;
    rs_curve_point.ParseFromString(sen);

    vector<mpz_class> c1(2);
    vector<mpz_class> c2(2);

    c1[0] = rs_curve_point.point_list()[0];
    c1[1] = rs_curve_point.point_list()[1];
    c2[0] = rs_curve_point.point_list()[2];
    c2[1] = rs_curve_point.point_list()[3];
    vector<mpz_class> R(2);
    vector<mpz_class> R2(2);
    string dec_res;
    ecc->ecc_mul(c1, this->private_key, R);
    ecc->ecc_sub(c2, R, R2);

//    cout << "R2[0]" << R2[0] << endl;
//    cout << "R2[1]" << R2[1] << endl;

    dec_res = R2[0].get_str();
    dec_res += R2[1].get_str();
    dec_res = ecc->hash_string->run(dec_res);

    return dec_res;

}


string EccEncrypt::hash_to_curve(const string &msg){
    vector<mpz_class> curve_point = ecc->hash_to_curve(msg);
    string res;
    res = curve_point[0].get_str();
    res += curve_point[1].get_str();
    res = ecc->hash_string->run(res);

    return res;
}