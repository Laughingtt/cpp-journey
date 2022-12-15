#include <iostream>
#include "thread/thread_pool.h"
#include "thread/parallel.h"

using namespace yacl;

constexpr static size_t
        kThreadPoolSize = 8;

class Timer {
public:
    Timer() { begin_point_ = std::chrono::steady_clock::now(); }

    double GetElapsedTimeInMs() const {
        auto end_point = std::chrono::steady_clock::now();
        double span = std::chrono::duration_cast<std::chrono::microseconds>(
                end_point - begin_point_)
                .count();
        return span / 1000000.0;
    }

private:
    std::chrono::steady_clock::time_point begin_point_;
};


void test01() {
    Timer timer;
    ThreadPool thread_pool_ = ThreadPool(kThreadPoolSize);

    std::future<void> futures[kThreadPoolSize];
    for (auto &future : futures) {
        future = thread_pool_.Submit(
                []() {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    std::cout << "aaa is " << std::endl;
                });
    }

    std::cout << "time is " << timer.GetElapsedTimeInMs() << std::endl;

    for (auto &future : futures) {
        future.wait();
    }
    std::cout << "time is " << timer.GetElapsedTimeInMs() << std::endl;
//    EXPECT_GE(timer.GetElapsedTimeInMs(), 100);
//    EXPECT_LT(timer.GetElapsedTimeInMs(), 200);
}

void test02() {
    ThreadPool thread_pool_ = ThreadPool(kThreadPoolSize);
    auto func1 = [](int a) { return a; };
    auto func2 = [](int a, long b) -> int { return a + b; };
    auto func3 = [](int a, int b, const uint32_t &c) -> int { return a + b + c; };

    std::vector<std::future<int>> futures;
    for (int i = 0; i < 600; i += 6) {
        futures.push_back(thread_pool_.Submit(func1, i));
        futures.push_back(thread_pool_.Submit(func2, i + 1, i + 2));
        futures.push_back(thread_pool_.Submit(func3, i + 3, i + 4, i + 5));
    }

    // get all
    int sum = 0;
    for (auto &feature : futures) {
        sum += feature.get();
    }
    std::cout << "sum is " << sum << std::endl;
}

#include <numeric>
#include "string"
#include "openssl/sha.h"
#include <openssl/md5.h>

using namespace std;

class Hash {
public:
    virtual ~Hash() = default;

    virtual string hash(const string &str);
};

string Hash::hash(const string &str) {
    return {};
}

class HashMd5 : public Hash {
public:
    string hash(const string &str) override;
};

string HashMd5::hash(const string &str) {
    char buf[2];
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5, str.c_str(), str.size());
    MD5_Final(hash, &md5);
    string new_string;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(buf, "%02x", hash[i]);
        new_string += buf;
    }
    return new_string;
}


void test03() {
    struct Param {
        int num_threads;
        int data_size;
        int grain_size;
    };
    Timer timer;
    HashMd5 hmd5;

    Param param = {8, 10000000, 100000};

    init_num_threads();
    set_num_threads(param.num_threads);

    std::vector<string> data(param.data_size);
    std::iota(data.begin(), data.end(), 0);

    parallel_for(0, data.size(), param.grain_size,
                 [&data, &hmd5](int64_t beg, int64_t end) {
                     for (int64_t i = beg; i < end; ++i) {
                         data[i] = hmd5.hash(to_string(i));
                     }
                 });

//    for (auto & i : data) {
//        std::cout << " == " << i << std::endl;
//    }
    std::cout << "single thread time is :" << timer.GetElapsedTimeInMs() << " s" << std::endl;
}

void test04() {
    Timer timer;
    HashMd5 hmd5;
    std::cout << "hello world hash" << hmd5.hash("hello world") << std::endl;
    std::vector<string> data(10000000);
    auto func = [&data, &hmd5]() {
        unsigned int size = data.size();
        for (int i = 0; i < size; ++i) {
            data[i] = hmd5.hash(to_string(i));
        }
    };
    func();
//    for (size_t i = 0; i < data.size(); ++i) {
//        std::cout << " == " << data[i] << std::endl;
//    }
    std::cout << "single thread time is :" << timer.GetElapsedTimeInMs() << " s" << std::endl;

}

void test05() {
    struct Param {
        int num_threads;
        int data_size;
        int grain_size;
    };
    Timer timer;
    HashMd5 hmd5;

    Param param = {8, 100000, 1000};

    init_num_threads();
    set_num_threads(param.num_threads);

    std::vector<int64_t> data(param.data_size);
    std::iota(data.begin(), data.end(), 0);
    int expect_sum = std::accumulate(data.begin(), data.end(), 0);

    int total_sum = parallel_reduce<int64_t>(
            0, data.size(), param.grain_size,
            [&data](int64_t beg, int64_t end) {
                int partial_sum = data[beg];
                for (int64_t i = beg + 1; i < end; ++i) {
                    partial_sum += data[i];
                }
                return partial_sum;
            },
            [](int a, int b) { return a + b; });

    std::cout << expect_sum << "==" << total_sum << std::endl;
    std::cout << "single thread time is :" << timer.GetElapsedTimeInMs() << " s" << std::endl;

}

int main() {
    std::cout << "Hello, Start !" << std::endl;

//    test01();
//    test02();
//    test03();
//    test04();
    test05();
    return 0;
}
