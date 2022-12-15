#include <iostream>
#include <boost/version.hpp>
#include "boost/lambda/lambda.hpp"
#include <boost/any.hpp>
//#include <boost/thread.hpp>
#include "thread"
#include "thread_pool.h"

using namespace std;
using namespace boost::lambda;     // boost lambda库
using namespace boost;     // boost库



void test01() {
    // 匿名表达式
    auto func = (cout << _1 << " " << _2);

    func(1, "abcd");
}

void test02() {
    any n = 10;
    any f = 1.23f;
    any s = string("abcd");

    cout << any_cast<int>(n) << endl;
    cout << any_cast<float>(f) << endl;
    cout << any_cast<string &>(s) << endl;
}

void thread_function() {
    std::cout << "thread function\n";
}

void thread_function2(std::string s) {
    std::cout << "thread function ";
    std::cout << "message is = " << s << std::endl;
}

void test03() {
    std::thread t(&thread_function);   // t starts running
    std::thread t2(&thread_function2, "hello world");   // t starts running
    std::cout << "main thread\n";
    t.join();   // main thread waits for the thread t to finish
    t2.join();   // main thread waits for the thread t to finish
}

void test_pool() {
    ThreadPool pool(4);
    std::vector<std::future<int>> results;

    for (size_t i = 0; i < 8; i++) {
        auto tp = [i] {
            std::cout << "hello " << i << std::endl;
            // std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "world " << i << std::endl;
            return i * i;

        };
        results.emplace_back(
                pool.enqueue((tp))
        );

    }


    for (auto &&result : results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;

}

int main() {
    cout << "Hello, World!" << endl;
    cout << "Boost版本：" << BOOST_VERSION << endl;

//    test01();
//    test02();
//    test03();
    test_pool();
    return 0;
}