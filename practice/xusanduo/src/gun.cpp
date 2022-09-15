//
// Created by tian on 2021/10/24.
//

# include "gun.h"

Gun::Gun(string name) {
    this->_name = name;
    this->_bullet_nums = 0;
    cout << &_name <<endl;
    cout << &this->_name <<endl;
}

void Gun::add_bullet(int nums) {
    if (nums <= 0) {
        cout << "添加子弹失败" << endl;
        return;
    }
    this->_bullet_nums += nums;
    cout << "添加子弹成功" << endl;
    this->left_bullet();

}

void Gun::shoot() {
    if (this->_bullet_nums == 0) {
        cout << "你的枪里没有子弹" << endl;
        return;
    }
    cout << "射击成功" << endl;
    this->_bullet_nums--;
    this->left_bullet();
}

void Gun::left_bullet() {
    cout << "剩余子弹数量为:" << this->_bullet_nums << endl;
}