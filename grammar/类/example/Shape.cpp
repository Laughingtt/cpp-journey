//
// Created by tian on 2021/10/22.
//

#include "Shape.h"
#include<iostream>


//Rectangle::Rectangle(int a,int b):Rectangle::R_a(a),R_b(b){}//这种初始化一般用在没有分头文件声明和具体实现，this用的多
Rectangle::Rectangle(float a,float b)
{
    this->R_a =a;
    this->R_b =b;
}

float Rectangle::GetPircumference()
{
    float R_c =0;
    R_c = 2*(this->R_a + this->R_b);
    return R_c;
}

//Circle::Circle(int a):Circle::C_a(a){}
//Circle::Circle(float a)
//{
//    this->C_a =a;
//}
//
//float Circle::GetPircumference()
//{
//    float R_c =0;
//    R_c = 2*this->C_a*3.14;
//    return R_c;
//}