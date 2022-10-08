//
// Created by tian on 2022/9/21.
//

#include "ecc_oblivious_transfer.h"

string EccObliviousTransfer::receiver_compute_secret_key(vector<string> &A_public_key) {
    vector<mpz_class> A_public_key_vec(2);
    ECC::string_to_mpz(A_public_key, A_public_key_vec);

    ecc->ecc_mul(A_public_key_vec, ecc->get_private_key(), A_public_key_vec);
    string secret_key = A_public_key_vec[0].get_str();
    return secret_key;
}

vector<string> EccObliviousTransfer::sender_compute_secret_list(vector<string> receiver_k, unsigned int msg_length) {
    vector<string> secret_key_list(msg_length);
    for (int j = 0; j < msg_length; ++j) {
        string secret_key = sender_compute_secret_key(receiver_k, j);
        secret_key_list[j] = secret_key;
    }
    return secret_key_list;
}

string EccObliviousTransfer::sender_compute_secret_key(vector<string> &B_random_k, unsigned int i) {
    vector<mpz_class> B_random_k_vec(2);
    ECC::string_to_mpz(B_random_k, B_random_k_vec);

    // a * k
    ecc->ecc_mul(B_random_k_vec, ecc->get_private_key(), B_random_k_vec);

    vector<mpz_class> A_public_key = ecc->get_public_key();
    ecc->ecc_mul(A_public_key, ecc->get_private_key(), A_public_key);
    ecc->ecc_mul(A_public_key, i, A_public_key);

    ecc->ecc_sub(B_random_k_vec, A_public_key, A_public_key);

    return A_public_key[0].get_str();

}

vector<string> EccObliviousTransfer::receiver_compute_k(vector<string> A_public_key, unsigned int i) {

    vector<mpz_class> A_public_key_vec(2);
    ECC::string_to_mpz(A_public_key, A_public_key_vec);

    ecc->ecc_mul(A_public_key_vec, i, A_public_key_vec);
    vector<mpz_class> B_public_key = ecc->get_public_key();
    ecc->ecc_add(A_public_key_vec, B_public_key, A_public_key_vec);

    ECC::mpz_to_string(A_public_key_vec, A_public_key);
    return A_public_key;
}

vector<string> EccObliviousTransfer::get_public_key() {
    vector<mpz_class> public_key = ecc->get_public_key();
    vector<string> public_key_str(2);
    ECC::mpz_to_string(public_key, public_key_str);
    return public_key_str;
}
