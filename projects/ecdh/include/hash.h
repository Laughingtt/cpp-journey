//
// Created by tian on 2022/9/20.
//

#ifndef ECDH_HASH_H
#define ECDH_HASH_H

#include "iostream"
#include "string"
#include "openssl/sha.h"
#include <openssl/md5.h>


using namespace std;

class Hash {
public:
    virtual string hash(const string &str) {
        return "std";
    }
};

class HashMd5 : public Hash {
public:
    virtual string hash(const string &str) {
        char buf[2];
        unsigned char hash[MD5_DIGEST_LENGTH];
        MD5_CTX md5;
        MD5_Init(&md5);
        MD5_Update(&md5, str.c_str(), str.size());
        MD5_Final(hash, &md5);
        string new_string;
        for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
            sprintf(buf, "%02x", hash[i]);
            new_string += buf;
        }
        return new_string;
    }
};

class HashSha256 : public Hash {
public:
    virtual string hash(const string &str) {
        char buf[2];
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str.c_str(), str.size());
        SHA256_Final(hash, &sha256);
        string new_string;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(buf, "%02x", hash[i]);
            new_string += buf;
        }
        return new_string;
    }
};

class HashSha512 : public Hash {
public:
    virtual string hash(const string &str) {
        char buf[2];
        unsigned char hash[SHA512_DIGEST_LENGTH];
        SHA512_CTX sha512;
        SHA512_Init(&sha512);
        SHA512_Update(&sha512, str.c_str(), str.size());
        SHA512_Final(hash, &sha512);
        string new_string;
        for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
            sprintf(buf, "%02x", hash[i]);
            new_string += buf;
        }
        return new_string;
    }
};


class HashString {
    Hash *hash = new Hash;
public:
    HashString(const string &method) {
        if (method == "md5") {
            // 创建匿名对象
            this->hash = &*new HashMd5;
        } else if (method == "sha256") {
            this->hash = &*new HashSha256;
        } else if (method == "sha512") {
            this->hash = &*new HashSha512;
        } else {
            std::cout << " not support method :" << method << std::endl;
        }
    }

    ~HashString() {
        delete hash;
    }

    string run(const string &s) {
        return this->hash->hash(s);
    }

};

#endif //ECDH_HASH_H
