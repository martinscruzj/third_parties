#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int myAmount = 0;
std::timed_mutex m;

void increment(int i) {
    using namespace std::literals::chrono_literals;
    auto now = std::chrono::steady_clock::now();
//    if (m.try_lock_for(1s)) {
    if (m.try_lock_until(now + 1s)) {
        ++myAmount;
        std::this_thread::sleep_for(2s);
        cout << "Thread " << i << " Entered" << endl;
        m.unlock();
    } else {
        cout << "Thread " << i << " Couldn't Enter" << endl;
    }
}

int main(int argc, char** argv)
{
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);

    t1.join();
    t2.join();
    cout << myAmount << endl;
    return 0;
}
