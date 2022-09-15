#ifndef DECISION_H
#define DECISION_H

#include "read_csv.h"

using namespace std;

class DecisionTree
{
private:
    /* data */
    int n_trees;

public:
    DecisionTree(/* args */);
    ~DecisionTree();

    void init_param();
    void fit();
    void predict();
};

#endif