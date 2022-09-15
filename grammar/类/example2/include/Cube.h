//
// Created by tian on 2022/7/26.
//

#ifndef LEARNING_CUBE_H
#define LEARNING_CUBE_H


class Cube {
private:
    int length;
    int width;
    int high;
public:
    void set(int _length, int _width, int _high);

    int get_tiji();

    bool check_equal(Cube c);
};


#endif //LEARNING_CUBE_H
