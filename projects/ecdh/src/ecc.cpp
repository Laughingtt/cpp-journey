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

vector<mpz_class> ECC::get_public_key() {
    return this->public_key;
}

mpz_class ECC::get_private_key() {
    //        cout << "get_private_key " << this->private_key << endl;
    return this->private_key;
}

vector<mpz_class> ECC::get_param_g() {
    return this->param_G;
}

void ECC::generate_point(mpz_class sk) {
    while (sk == 0) {
        ECC::get_random_mpz(sk.get_mpz_t());
        cout << "sk is :" << sk << endl;
    }

    this->private_key = sk;

    bool is_on_cur = is_on_curve(this->param_G);

    cout << "is on curve " << to_string(is_on_cur) << endl;

    ecc_mul(param_G, sk, this->public_key);

    cout << "this->public_key " << this->public_key[0] << " " << this->public_key[1] << endl;
    cout << "this->private_key " << this->private_key << endl;

}

ECC::ECC() {
    // set mpz value
    param_p = "115792089237316195423570985008687907853269984665640564039457584007908834671663";
    param_G[0] = "55066263022277343669578718895168534326250603453777594175500187360389116729240";
    param_G[1] = "32670510020758816978083085130507043184471273380659243275938904335757337482424";
    param_n = "115792089237316195423570985008687907852837564279074904382605163141518161494337";

    cout << "======ecc" << this->name << "init param is :======" << endl;
    cout << "param_a : " << param_a << endl;
    cout << "param_b : " << param_b << endl;
    cout << "param_p : " << param_p << endl;
    cout << "param_G[0] : " << param_G[0] << endl;
    cout << "param_G[1] : " << param_G[1] << endl;
    cout << "param_n : " << param_n << endl;
    cout << "param_h : " << param_h << endl;
    cout << "==================================================" << endl;

}

void ECC::ecc_mul(const vector<mpz_class> &P,const mpz_class &k, vector<mpz_class> &R) {
    // R = k * P
    mpz_class mod_value;
    mpz_mod(mod_value.get_mpz_t(), k.get_mpz_t(), this->param_n.get_mpz_t());
    if (mod_value == 0) {
        return;
    }

    if (k < 0) {
        // k * point = -k * (-point)
        vector<mpz_class> neg_P = ecc_neg(P);
        mpz_class neg_k = -k;
        ecc_mul(neg_P, neg_k, R);
        return;
    }
    const mpz_class two = 2;
    mpz_class tem_k = k;
    vector<mpz_class> Q(2);
    vector<mpz_class> Q_tmp(2);
    Q_tmp[0] = P[0];
    Q_tmp[1] = P[1];
    while (tem_k > 0) {
        mpz_mod(mod_value.get_mpz_t(), k.get_mpz_t(), two.get_mpz_t());
        if (mod_value == 1) {
            ecc_add(Q, Q_tmp, Q);
        }
        ecc_add(Q_tmp, Q_tmp, Q_tmp);
        //            cout << "k  " << k << "  Q_tmp " << Q_tmp[0] << "  " << Q_tmp[1] << endl;
        tem_k = tem_k / two;
    }
    R[0] = Q[0];
    R[1] = Q[1];

}

void ECC::ecc_add(const vector<mpz_class> &P,const vector<mpz_class> &Q, vector<mpz_class> &R) {
    if (P[0] == 0 && P[1] == 0) {
        R[0] = Q[0];
        R[1] = Q[1];
        return;
    }
    if (Q[0] == 0 && Q[1] == 0) {
        R[0] = P[0];
        R[1] = P[1];
        return;
    }
//    is_on_curve(P);
//    is_on_curve(Q);

    mpz_class x1 = P[0];
    mpz_class y1 = P[1];
    mpz_class x2 = Q[0];
    mpz_class y2 = Q[1];
    mpz_class m;
    mpz_class mod_inv_number;

    if (x1 == x2) {
        mpz_class y1_2 = 2 * y1;
        mod_inv2(y1_2, this->param_p, mod_inv_number);
        m = (3 * x1 * x1 + this->param_a) * mod_inv_number;
//        m = (3 * x1 * x1 + this->param_a) * mod_inv2(2 * y1, this->param_p);
    } else {
        mpz_class x2_x1 = x2 - x1;
        mod_inv2(x2_x1, this->param_p, mod_inv_number);
        m = (y2 - y1) * mod_inv_number;
//        m = (y2 - y1) * mod_inv2(x2 - x1, this->param_p);
    }
    mpz_class x3 = m * m - x1 - x2;
    mpz_class y3 = m * (x1 - x3) - y1;
    mpz_mod(R[0].get_mpz_t(), x3.get_mpz_t(), this->param_p.get_mpz_t());
    mpz_mod(R[1].get_mpz_t(), y3.get_mpz_t(), this->param_p.get_mpz_t());

}

void ECC::ecc_sub(const vector<mpz_class> &P,const vector<mpz_class> &Q, vector<mpz_class> &R) {
    vector<mpz_class> neg_Q = ecc_neg(Q);
    ecc_add(P, neg_Q, R);
}


mpz_class ECC::positive_mod(mpz_class &numer, mpz_class &p) {
    // 使得取模后的数为正
//    mpz_class r_numer = numer % p;
//    if (r_numer < 0) {
//        r_numer = r_numer + p;
//    }
    mpz_class r_numer;
    mpz_mod(r_numer.get_mpz_t(), numer.get_mpz_t(), p.get_mpz_t());

    return r_numer;
}

mpz_class ECC::mod_inv(mpz_class u, mpz_class v) {
    mpz_class x = 1;
    mpz_class y = 0;
    mpz_class temp;
    mpz_class k;
    while (v != 0) {
        k = u / v;
        mpz_mod(temp.get_mpz_t(), u.get_mpz_t(), v.get_mpz_t());

        u = v;
        v = temp;

        temp = x - k * y;
        x = y;
        y = temp;
    }
    return x;
}

void ECC::mod_inv(mpz_class u, mpz_class v, mpz_class &n) {
    mpz_class x = 1;
    mpz_class y = 0;
    mpz_class temp;
    mpz_class k;
    while (v != 0) {
        k = u / v;
        mpz_mod(temp.get_mpz_t(), u.get_mpz_t(), v.get_mpz_t());

        u = v;
        v = temp;

        temp = x - k * y;
        x = y;
        y = temp;
    }
    n = x;
}

mpz_class ECC::power_method(mpz_class a, mpz_class b, mpz_class c) {
    mpz_class ans = 1;
    a = a % c;
    while (b > 0) //取出的b==0时也就代表取二进制位取完了，循环也就结束
    {
        if (b % 2 == 1) //根据二进制位是否是1决定要不要乘进去
            ans = (ans * a) % c;
        b = b / 2;   //b就是x_i，存储每一个二进制位
        a = (a * a) % c;//更新a的值,a就代表每一项
    }
    return ans;
}

mpz_class ECC::mod_inv2(mpz_class u, mpz_class v) {

//    return power_method(u, v - 2, v);
    mpz_class pow_num;
    mpz_class v_2 = v - 2;
    mpz_powm(pow_num.get_mpz_t(), u.get_mpz_t(), v_2.get_mpz_t(), v.get_mpz_t());
    return pow_num;
}

void ECC::mod_inv2(const mpz_class &u,const mpz_class &v, mpz_class &n) {

    mpz_class v_2 = v - 2;
    mpz_powm(n.get_mpz_t(), u.get_mpz_t(), v_2.get_mpz_t(), v.get_mpz_t());
}

mpz_class ECC::mod_inv3(mpz_class u, mpz_class v) {

    if (u == 1) {
        return 1;
    }
    if (u == 0) {
        return 0;
    }
    return -(v / u) * mod_inv3(v % u, v) % v;
}


vector<mpz_class> ECC::ecc_neg(const vector<mpz_class> &P) {
    // y - > -y
    vector<mpz_class> neg_P(2);
    neg_P[0] = P[0];
    mpz_class neg_p_1 = -P[1];
    mpz_mod(neg_P[1].get_mpz_t(), neg_p_1.get_mpz_t(), this->param_p.get_mpz_t());

    return neg_P;
}

bool ECC::is_on_curve(const vector<mpz_class> &P) {

    mpz_class x = P[0];
    mpz_class y = P[1];
    mpz_class curve_res;
    mpz_class cal_res = (y * y - x * x * x - this->param_b);
    mpz_mod(curve_res.get_mpz_t(), cal_res.get_mpz_t(), this->param_p.get_mpz_t());

    //        cout << "curve_res  " << curve_res << endl;
    if (curve_res == 0) {
        return true;
    }
    //        cout << "curve_res P[0]" << P[0] << endl;
    //        cout << "curve_res P[1]" << P[1] << endl;
    return false;
}

bool ECC::x_is_on_curve(const mpz_class &x) {
    mpz_class t;
    mpz_class cal_res = x * x * x + this->param_a * x * x + this->param_b;
    mpz_mod(t.get_mpz_t(), cal_res.get_mpz_t(), this->param_p.get_mpz_t());

    // 如果 t^((p - 1) / 2) is 0 or 1，则t是 quadratic residue
    //    t = power_method(t, (this->param_p - 1) / 2, this->param_p);

    mpz_class exp = (this->param_p - 1) / 2;
    mpz_powm(t.get_mpz_t(), t.get_mpz_t(), exp.get_mpz_t(), this->param_p.get_mpz_t());
    if (t == 0 | t == 1) {
        return true;
    } else {
        return false;
    }
}

mpz_class ECC::find_y_give_x(const mpz_class &x) {
    // 得到x之后，计算y，仅适用于 p % 4 = 3的情况, which is the case for secp256k1
    mpz_class t;
    mpz_class cal_res = x * x * x + this->param_a * x * x + this->param_b;
    mpz_class c1 = (this->param_p + 1) / 4;
    mpz_mod(t.get_mpz_t(), cal_res.get_mpz_t(), this->param_p.get_mpz_t());
//    mpz_class y = power_method(t, c1, this->param_p);

    mpz_powm(t.get_mpz_t(), t.get_mpz_t(), c1.get_mpz_t(), this->param_p.get_mpz_t());
    return t;
}

vector<mpz_class> ECC::hash_to_curve(const string &msg) {
    string hex_string = hash_string->run(msg);
    mpz_class msg_num_x = mpz_class(hex_string, 16);

//    cout << "hex_string " << hex_string << endl;
//    cout << "msg_num " << msg_num_x << endl;

    // find x
    while (!x_is_on_curve(msg_num_x)) {
        msg_num_x += 1;
    }

    // find y
    mpz_class msg_num_y = find_y_give_x(msg_num_x);

    // point
    vector<mpz_class> msg_point(2);
    msg_point[0] = msg_num_x;
    msg_point[1] = msg_num_y;

    return msg_point;
}

void ECC::mpz_to_string(vector<mpz_class> &vec1, vector<string> &vec2) {
    for (int i = 0; i < vec1.size(); ++i) {
        string tmp = vec1[i].get_str();
        vec2[i] = tmp;
    }
}

void ECC::string_to_mpz(vector<string> &vec1, vector<mpz_class> &vec2) {
    for (int i = 0; i < vec1.size(); ++i) {
        string tmp = vec1[i];
        vec2[i] = tmp;
    }
}
