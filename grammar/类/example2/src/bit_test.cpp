//
// Created by tian on 2022/8/8.
//

#include "string"
#include "bitset"
#include "ctime"
#include "vector"

//def compute_possition(combine_string, param_w, param_m_log2):
//    lis= []
//    for column_idx in range(param_w):
//        lis.append(int(combine_string[column_idx * param_m_log2:(column_idx + 1) * param_m_log2], 2))
//    return lis

void compute_position(string combine_string, int param_w, int param_m_log2, int size) {

    string tmp;
    //    std::byte bytes[5];
    for (int i = 0; i < size; ++i) {
        if (i != 0 && i % param_m_log2 == 0) {
            int a = 1;
        } else {
            tmp += combine_string[i];
        }
    }
}


void string_to_int() {
    string inp = "1234";

    cout << "Input String: " << inp << endl;

    // Use std::stoi() to convert string to integer
    try {
        // Wrap up code in try-catch block if string is not validated
        int res = stoi(inp);
        cout << "Integer: " << res << endl;
    }
    catch (std::invalid_argument e) {
        cout << "Caught Invalid Argument Exception\n";
    }
}

void bitset_test() {
    //字符转化成二进制串
    bitset<8> bits = bitset<8>(10);
    bitset<8> bits2 = bitset<8>("101001");
    cout << (int) bits.to_ulong() << endl;
    bitset<8> tm = bits2 >> 1;
    cout << bits2 << endl;
    cout << tm << endl;
    cout << bits[1] << endl;
    bits[1] = (bool) "0";
    cout << "bool 0 is " << (stoi("0")) << endl;
    cout << "bool 1 is " << (stoi("1")) << endl;
    cout << bits[1] << endl;
    bitset<1> tmp;
    //二进制翻转
    for (int i = 0; i < 4; i++) {
        tmp[0] = bits[i];
        bits[i] = bits[7 - i];
        bits[7 - i] = tmp[0];
    }
    //输出
    for (int i = 0; i < 8; i++)
        cout << bits[i];

}


//将8位字符串转化为64bit
string StrToBitStr(string str) {
    bitset<64> bstr;
    for (int i = 0; i < 8; i++) {
        bitset<8> bits = bitset<8>(str[i]);
        cout << str[i] << endl;
        for (int j = 0; j < 8; j++) {
            bstr[i * 8 + j] = bits[7 - j];
        }
    }
    string s = bstr.to_string();
    //添加一个翻转操作
    reverse(begin(s), end(s));
    return s;
}

int sto_int(char s) {
    if (s == '1') {
        return 1;
    } else {
        return 0;
    }
}

string strbit_to_str(string &str) {
    int size = str.size();
    bitset<5> bstr;

    for (int i = 0; i < 16; i++) {
        bstr[i] = sto_int(str[i]);
    }

    string s = bstr.to_string();
    //添加一个翻转操作
    reverse(begin(s), end(s));
    cout << "bstr is :" << s << endl;

    return s;
}

//将64bit二进制字符串转化为字符串
string BitStrToStr(string bstr) {
    string str = "";
    int bit_l = 13;
    //每八位转化成十进制，然后将数字结果转化成字符
    int sum;
    for (int i = 0; i < bstr.size(); i += bit_l) {
        sum = 0;
        for (int j = 0; j < bit_l; j++)
            if (bstr[i + j] == '1')
                sum = sum * 2 + 1;
            else
                sum = sum * 2;
            //            str =str+char(sum);
            //        cout << "numer is " << sum << endl;
    }
    return str;

}

vector<string> find_position(vector<vector<int>> &v_list, vector<string> &matrix) {
    unsigned int sample_length = v_list.size();
    unsigned int param_w = matrix.size();
    vector<string> final_sid(sample_length);
    cout << "sample_length" << sample_length << endl;
    for (auto idx = 0; idx < sample_length; ++idx) {
        string temp;
        for (int w_idx = 0; w_idx < param_w; ++w_idx) {
            temp += matrix[w_idx][v_list[idx][w_idx]];
        }
        final_sid[idx] = temp;
        //        cout << "当前的position:" <<temp << endl;
    }
    for (int i = 0; i < final_sid.size(); ++i) {
        cout << "当前的position:" << final_sid[i] << endl;
    }
    return final_sid;

}

vector<string> insert_d_matrix(int param_m, int param_w, vector<vector<int>> &v_list) {
    string one(param_m, '1');
    vector<string> d_matrix(param_w);
    for (int i = 0; i < param_w; ++i) {
        d_matrix[i] = one;
        cout << d_matrix[i] << endl;
    }
    for (int idx = 0; idx < param_m; ++idx) {
        for (int idw = 0; idw < param_w; ++idw) {
            d_matrix[idw][v_list[idx][idw]] = '0';
        }
    }
    return d_matrix;
}

vector<int> bit_str_to_int(string s, int w, const int log2) {
    vector<int> arr;
    for (int i = 0; i < w; ++i) {
        string sub_s = s.substr(i * log2, log2);
        bitset<16> bits(sub_s);
        arr.push_back(bits.to_ulong());
        cout << bits.to_ulong() << endl;
    }
    return arr;
}


int main() {
    //    clock_t start, end;
    //    string total;
    string s = "00011111110011111111100011100000110111000011110011110011001000000111110100";
    bit_str_to_int(s, 5, 5);
    //    strbit_to_str(s);
    //    for (int i = 0; i < 100; ++i) {
    //        total += s;
    //        cout << total.size() << endl;
    //    }
    //    int size = 74;
    //    compute_position(s, 7, 10, size);
    //    bitset_test();
    //    string  bstr = StrToBitStr("generate");
    //    cout<<bstr << endl;
    //    start = clock();
    //    cout << BitStrToStr(total) << endl;
    //    end = clock();
    //    cout << "The run time is:" <<(double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

    // insert position
    //    vector<vector<int>> v_list = {{1, 3, 2},
    //                                  {1, 3, 2},
    //                                  {1, 3, 2},
    //                                  {1, 3, 2},
    //                                  {1, 3, 2}};
    //    vector<string> d_matrix = insert_d_matrix(5, 3, v_list);
    //    for (int d = 0; d < d_matrix.size(); ++d) {
    //        cout << d_matrix[d] << endl;
    //    }
    return 0;
}