//
// Created by tian on 2022/7/12.
//

#ifndef PYBIND_EXAMPLE_PET_H
#define PYBIND_EXAMPLE_PET_H


class Pet {
public:
    void setName(const std::string name_) { name = name_; }

    const std::string getName() const { return name; }

    std::string name;
};


#endif //PYBIND_EXAMPLE_PET_H
