//
// Created by tian on 2021/10/22.
//

#ifndef INC_1022_SHAPE_H
#define INC_1022_SHAPE_H


class Shape {

public:
    virtual float GetPircumference() = 0;


};

class Rectangle : public Shape {

private:
    float R_a;
    float R_b;
public:
    Rectangle(float a, float b);

    float GetPircumference() override;

};

//class Circle : public Shape {
//
//private:
//    float C_a;
//public:
//    Circle(float a);
//
//    float GetPircumference();
//
//};

#endif //INC_1022_SHAPE_H
