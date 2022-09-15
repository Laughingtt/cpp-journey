//
// Created by tian on 2021/10/24.
//

#ifndef XUSANDUO_SOLDIER_H
#define XUSANDUO_SOLDIER_H

# include "gun.h"

using namespace std;

class Soldier {
public:
    Soldier(string name);

    ~Soldier();
    void add_gun_to_soldier(Gun *gun_obj);

    void add_bullet_to_gun(int nums);

    void fire();

private:
    string _name;
    Gun *_gun_obj;
};


#endif //XUSANDUO_SOLDIER_H
