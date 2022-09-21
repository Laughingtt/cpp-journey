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
    virtual string hash(const string &str);
};

class HashMd5 : public Hash {
public:
    string hash(const string &str) override;
};

class HashSha256 : public Hash {
public:
    string hash(const string &str) override;
};

class HashSha512 : public Hash {
public:
    string hash(const string &str) override;
};


class HashString {
    Hash *hash = new Hash;
public:
    HashString(const string &method);

    ~HashString() {
        delete hash;
    }

    string run(const string &s);

};

#endif //ECDH_HASH_H
