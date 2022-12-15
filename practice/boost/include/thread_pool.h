//
// Created by tian on 2022/12/12.
//

#ifndef BOOST_THREAD_POOL_H
#define BOOST_THREAD_POOL_H
#include<vector>
#include<queue>
#include<memory>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<future>
#include<functional>
#include<stdexcept>
#include<type_traits>

class ThreadPool
        {
        public:
            ThreadPool();
            ThreadPool(int num);
            ~ThreadPool();

            template<class F, class... Args>
                    std::future<int> enqueue(F& f, Args&... args);

        private:
            std::vector <std::thread> workers; //thread array

            std::queue<std::function<void()>>tasks; //task queue

            std::mutex queue_mutex;
            std::condition_variable cond;
            bool stop;
        };

inline ThreadPool::ThreadPool()
{
}

ThreadPool::ThreadPool(int num) :stop(false)
{
    for (size_t i = 0; i < num; i++)
    {
        auto thread = [this] {
            for (;;)
            {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(this->queue_mutex);
                    this->cond.wait(lock, [this] {
                        return this->stop || !this->tasks.empty();//stop 或许任务队列不为空时唤醒。
                    }
                    );

                    if (stop && tasks.empty())
                        return;
                    task = std::move(tasks.front());
                    tasks.pop();//有点类似bfs的思路
                }

                task();
            }
        };
        workers.emplace_back(thread);

    }
}

inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    cond.notify_all();

    for (auto& worker : workers)
    {
        worker.join();
    }
}


//}

template<class F, class... Args>
        std::future<int> ThreadPool::enqueue(F& f, Args&... args)
        {
    std::function<decltype(f(args...))()> func =
            std::bind(std::forward<F>(f), std::forward<Args>(args)...); // 连接函数和参数定义，特殊函数类型，避免左右值错误

            auto task = std::make_shared< std::packaged_task<int()> >(
                    func
                    );

            std::function<void()> warpper_func = [task](){(*task)();};
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.emplace(warpper_func);
            cond.notify_one();
            return task->get_future();
        }

#endif //BOOST_THREAD_POOL_H
