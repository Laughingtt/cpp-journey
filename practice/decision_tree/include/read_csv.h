#ifndef READ_CSV_H
#define READ_CSV_H

#include "vector"
#include "string"
#include <iostream>
#include <fstream>
#include <sstream>
#include "map"
#include "set"

using namespace std;

struct TrainData
{
    vector<string> ids;
    vector<int> label;
    vector<vector<double>> col_data;
};

class Reader
{
private:
    /* data */
    void get_header_index();
    void update_header();

public:
    Reader(string label_name);
    ~Reader();

    int rows;
    int cols;
    string label_name;
    vector<string> columns;
    vector<string> header;
    map<string, int> header_map;
    map<int, set<double>> header_split_point;

    vector<vector<string>> read_csv(string file_path);
    static vector<string> get_header(int &rows, string headline, int &cols);
    TrainData find_split_point(vector<vector<string>> strResult);
};

#endif