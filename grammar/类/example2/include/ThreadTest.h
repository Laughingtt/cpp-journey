//
// Created by tian on 2022/8/8.
//

#ifndef LEARNING_THREADTEST_H
#define LEARNING_THREADTEST_H

#include "iostream"
#include "thread"

using namespace std;

class ThreadTest {
public:
    static void proc(int a) {
        cout << "我是子线程,传入参数为" << a << endl;
        cout << "子线程中显示子线程id为" << this_thread::get_id() << endl;
    }

    void test() {
        cout << "我是主线程" << endl;
        int a = 9;
        thread th1(proc, a);//第一个参数为函数名，第二个参数为该函数的第一个参数，如果该函数接收多个参数就依次写在后面。此时线程开始执行。
        thread th2(proc, a);//第一个参数为函数名，第二个参数为该函数的第一个参数，如果该函数接收多个参数就依次写在后面。此时线程开始执行。
        cout << "主线程中显示子线程id为" << th2.get_id() << endl;
        th1.join();//此时主线程被阻塞直至子线程执行结束。
        th2.join();//此时主线程被阻塞直至子线程执行结束。
    }

};


#endif //LEARNING_THREADTEST_H
