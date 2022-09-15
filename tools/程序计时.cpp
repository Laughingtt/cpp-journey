#include <iostream>
#include <ctime>


using namespace std;

double sum_count(int count_n)
{
    double s = 0;
    for (size_t i = 0; i < count_n; i++)
    {
        if (i%3==1)
        {
            s=s+(i+1)/i;
        }else{
            s+=0;
        }
        
    }
    return s;
}

int main(int argc, char const *argv[])
{
    clock_t start = clock();
    int a = 10000000;
    double r = sum_count(a);
    clock_t end  = clock();
    double programTimes = ((double) end -start) / CLOCKS_PER_SEC;

    cout << "result is :" << r << endl;
    cout << "programTimes is :" << programTimes << endl;

    return 0;
}
