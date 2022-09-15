//
// Created by tian on 2021/10/24.
//

#include "soldier.h"

Soldier::Soldier(string name) {
    this->_name = name;
    this->_gun_obj = nullptr;
}

void Soldier::add_gun_to_soldier(Gun *gun_obj) {
    this->_gun_obj = gun_obj;
}

void Soldier::add_bullet_to_gun(int nums) {
    if (this->_gun_obj == nullptr) {
        cout << "子弹装填失败，请先佩戴枪支" << endl;
        return;
    }else{
        cout << "hello" <<endl;
    };
    this->_gun_obj->add_bullet(nums);
}

void Soldier::fire() {
    if (this->_gun_obj == nullptr) {
        cout << "开火失败，请先佩戴枪支" << endl;
        return;
    }
    this->_gun_obj->shoot();
}

Soldier::~Soldier() {
    this->_gun_obj = nullptr;
    delete this->_gun_obj;

}