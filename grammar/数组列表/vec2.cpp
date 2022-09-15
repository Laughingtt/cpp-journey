#include "vector"
#include "iostream"

using namespace std;

int* test(int *vec,int size=10)
{   
    
    for (size_t i = 0; i < size; i++)
    {
        cout << vec[i] << endl;
        vec[i] = vec[i]+2;
    }
    return vec;
}

int main(int argc, char const *argv[])
{
    vector<int> vec(10, 0);
    cout << &vec[0] <<endl;
    int* r = test(&vec[0],10);
    cout << &r[0] <<endl;
    for (size_t i = 0; i < 10; i++)
    {
        cout << r[i] << endl;
    }
    return 0;
}
