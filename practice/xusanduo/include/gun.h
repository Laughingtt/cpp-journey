//
// Created by tian on 2021/10/24.
//

#ifndef XUSANDUO_BULLET_H
#define XUSANDUO_BULLET_H

#include "iostream"
#include "string"

using namespace std;

class Gun {
public:
    Gun(string name);

    void add_bullet(int nums);

    void shoot();

    void left_bullet();

private:
    string _name;
    int _bullet_nums;

};


#endif //XUSANDUO_BULLET_H



