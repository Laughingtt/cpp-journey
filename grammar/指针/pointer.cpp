#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{   
    int t = 3;
    int * before;
    int * after = &t;
    before = after;

    cout << *before << endl;
    cout << *after << endl;

    delete before;
    delete before;
    cout << before << endl;
    cout << after << endl;
    return 0;
}
