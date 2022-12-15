#include <iostream>
#include "gun.h"
#include "soldier.h"

void gun_test() {
    Gun ak = Gun("ak47");
    ak.add_bullet(20);
    ak.shoot();
    ak.shoot();
    ak.shoot();
    ak.shoot();
}

void soldier_test(){
    Soldier xusanduo = Soldier("xusanduo");
    xusanduo.fire();
    xusanduo.add_gun_to_soldier(new Gun("ak47"));
    xusanduo.fire();
    xusanduo.add_bullet_to_gun(20);
    xusanduo.fire();
}

int main() {
   gun_test();
    // soldier_test();
    return 0;

}
