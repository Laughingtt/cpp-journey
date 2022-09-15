#include "iostream"

using namespace std;

int *test01()
{
    int a = 1;
    cout << &a << endl;
    return &a;
}

int test02()
{
    int a = 1;
    cout << &a << endl;
    return a;
}

void test_int()
{
    // 函数局部变量不可以当作指针传出，函数执行完之后内存会释放掉，所以返回局部变量的指针之后该内存区数据会消失，
    int *c = test01();
    cout << *c << endl;
    cout << *c << endl;
    cout << *c << endl;
    cout << *c << endl;
    cout << c << endl;
    cout << c << endl;
}

void test02_()
{
    int r = test02();
    cout << &r << endl;
    cout << &r << endl;
    cout << &r << endl;
    //  函数直接返回值的时候，会对返回值进行拷贝，释放掉原来的内存区域
    //     0x7ffedfed438c
    // 0x7ffedfed43bc
    // 0x7ffedfed43bc
    // 0x7ffedfed43bc
}

int *test03()
{
    int *a = new int(1);
    cout << a << endl;
    return a;
}

void test03_()
{
    int *r = test03();
    cout << *r << endl;
    cout << *r << endl;
    cout << *r << endl;
    delete r;
    r = nullptr;
    // 删除堆区的指针之后还可以打印使用，delete只是告诉系统这块区域的内存不再使用了，
    // 但还存在，如果有其他程序使用了这段内存，那会引发系统的奔溃，所以delte之后指针置为空；
    cout << *r << endl;
    cout << *r << endl;
    cout << r << endl;
}

int *test04(int num)
{
    int *arr = new int[num];
    for (size_t i = 0; i < num; i++)
    {
        arr[i] = i;
    }
    return arr;
}

void test04_()
{
    int *arr = test04(10);
    cout << arr << endl;
    for (size_t i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
    arr = nullptr;

    for (size_t i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

}
int main(int argc, char const *argv[])
{
    test04_();
}
