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
    virtual ~Hash() = default;

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
    explicit HashString(const string &method);

    HashString();

    ~HashString() {
        delete hash;
    }

    string run(const string &s);

};

#endif //ECDH_HASH_H
