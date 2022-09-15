#include "read_csv.h"



vector<string> Reader::get_header(int &rows, string headline, int &cols)
{
    vector<string> header;
    if (rows > 0)
    {
        string attributeName;
        char delim = ',';
        istringstream stringin(headline);
        while (getline(stringin, attributeName, delim))
        {
            cols++;
            header.push_back(attributeName);
        }
    }
    else
    {
        cout << "file row less 1" << endl;
    }

    cout << "header is : ";

    for (size_t i = 0; i < header.size(); i++)
    {
        cout << header[i] << " ";
    }
    cout << "" << endl;

    return header;
}

void Reader::get_header_index()
{
    cout << "init header index" << endl;
    // map<string, int> header_map;
    for (size_t i = 0; i < header.size(); i++)
    {
        this->header_map[header[i]] = i;
    }

    // 遍历打印map
    map<string, int>::iterator iter;
    iter = this->header_map.begin();
    while (iter != this->header_map.end())
    {
        cout << iter->first << " : " << iter->second << endl;
        iter++;
    }
}

vector<vector<string>> Reader::read_csv(string file_path)
{
    int cols = 0, rows = 0; //通过文件读取 获取行和列的信息。
    vector<vector<string>> strResult;
    ifstream read;
    read.open(file_path, ios::in);

    string headline;
    getline(read, headline);
    rows++; //每次readline都要加行数一次
    this->header = get_header(rows, headline, cols);
    get_header_index();

    //获取第一行信息
    string line; //从第二行以后开始存储的每一行的数据
                 //下面获取后面的信息
    while (getline(read, line))
    {
        int realcols = 0; //用来判断此行中数据是否和标题行的数据列数相同，相同才存储，否则不存储
        string attributeName;
        char delim = ',';
        istringstream stringin(line);
        vector<string> oneLineString;
        while (getline(stringin, attributeName, delim))
        {
            realcols++;
            //cout << attributeName << "  ";
            oneLineString.push_back(attributeName);
        }
        if (realcols == cols)
        { //只有和标题行数据列数相同才存储
            strResult.push_back(oneLineString);
            rows++;

        }
    }

    cout << rows << "  " << cols << endl;
    ;
    this->rows = rows - 1;
    this->cols = cols;
    return strResult;
}

// 寻找切分点
TrainData Reader::find_split_point(vector<vector<string>> strResult)
{
    vector<vector<double>> col_data(cols);
    int label_index = header_map[label_name];
    vector<int> label;
    vector<string> ids;
    for (size_t col = 0; col < cols; col++)
    {   
        if (col == 0)
        {
            for (size_t row = 0; row < rows; row++)
            {
                ids.push_back(strResult[row][col]);
            }

        }
        else if (col == label_index)
        {
            for (size_t row = 0; row < rows; row++)
            {
                label.push_back(stoi(strResult[row][col], 0));
            }
        }
        else
        {
            set<double> col_set;
            vector<double> col_value;
            for (size_t row = 0; row < rows; row++)
            {
                double value = stod(strResult[row][col], 0);
                col_set.insert(value);
                col_value.push_back(value);
            }

            this->header_split_point[col] = col_set;
            col_data.push_back(col_value);
        }
    }
    update_header();

    TrainData train_data;
    train_data.ids = ids;
    train_data.label = label;
    train_data.col_data = col_data;
    
    return train_data;
}

void Reader::update_header(){
    int label_index = header_map[label_name];
    header.erase(header.begin()); // 删除id
    header.erase(header.begin()+label_index-1); // 删除label
    for (size_t i = 0; i < header.size(); i++)
    {
        cout << "col:"<<header[i] << endl;
    }
    header_map.clear();
    get_header_index();
}

Reader::Reader(string label_name)
{
    this->label_name = label_name;
}

Reader::~Reader()
{
}
