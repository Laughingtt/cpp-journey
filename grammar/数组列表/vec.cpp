#include "vector"
#include "iostream"

using namespace std;

vector<int> test(vector<int> &vec)
{   
    vector<int> vec2;
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
        vec2.push_back(vec[i]);
    }
    return vec;
}

int main(int argc, char const *argv[])
{
    // 创建 10个1
    vector<int> vec(10, 1);
    cout << &vec[0] <<endl;
    vector<int> r = test(vec);
    vec.clear();
    // r.clear(); 删除此块值区间的所有指向地址时，才会清理对应的内存
    // 容器当作引用传入时，引用指针可以直接操作对应的内存区别，如果在函数内新生成vector会直接加入堆区返回vector
    cout << &r[0] <<endl;
    for (size_t i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
    cout << "===" <<endl;
    for (size_t i = 0; i < r.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}
