#include "vector"
#include "iostream"

using namespace std;

vector<int> test(int size=10)
{   
    vector<int> arr;
    for (size_t i = 0; i < size; i++)
    {
        cout << i << endl;
        arr.push_back(i);
    }
    return arr;
}

int main(int argc, char const *argv[])
{

    vector<int> r = test(10);
    cout << &r[0] <<endl;
    for (size_t i = 0; i < 10; i++)
    {
        cout << r[i] << endl;
    }

    for (size_t i = 0; i < 10; i++)
    {
        cout << r[i] << endl;
    }

    for (size_t i = 0; i < 10; i++)
    {
        cout << r[i] << endl;
    }
    return 0;
}
