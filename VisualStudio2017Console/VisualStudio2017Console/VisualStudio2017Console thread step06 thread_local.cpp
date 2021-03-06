#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

const int g_numLoop = 10;
int g_value = 0;
std::mutex  g_m;
std::condition_variable cv;
bool g_ready1 = false;
bool g_ready2 = false;
std::string g_string;
//thread_local std::string g_string;

void WorkerThread1(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        {
            std::unique_lock<std::mutex> lock(g_m);
            cv.wait(lock, []()->bool {return g_ready2; });
            g_ready2 = false;
        }
        g_value += 1;
        char buffer[10];
        snprintf(buffer, 10, "%i,", g_value);
        g_string += buffer;

        g_ready1 = true;
        cv.notify_one();
    }
    cv.notify_one();
    {
        std::unique_lock<std::mutex> lock(g_m);
        std::cout << g_string << std::endl;
    }
}

void WorkerThread2(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        g_value += 1;
        char buffer[10];
        snprintf(buffer, 10, "%i,", g_value);
        g_string += buffer;

        g_ready2 = true;
        cv.notify_one();
        {
            std::unique_lock<std::mutex> lock(g_m);
            cv.wait(lock, []()->bool {return g_ready1; });
            g_ready1 = false;
        }
    }
    cv.notify_one();
    {
        std::unique_lock<std::mutex> lock(g_m);
        std::cout << g_string << std::endl;
    }
}

int main()
{
    std::thread worker1(WorkerThread1, 1);
    std::thread worker2(WorkerThread2, 11);

    worker1.join();
    worker2.join();
}
