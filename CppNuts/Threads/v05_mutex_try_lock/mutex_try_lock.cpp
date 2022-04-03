#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increaseTheCounterFor100000Time() {
    for (int i = 0; i < 100000; i++) {
        if (mtx.try_lock()) {
            ++counter;
            mtx.unlock();
        }
    }
}

int main(int argc, char** argv) {
    std::thread t1(increaseTheCounterFor100000Time);
    std::thread t2(increaseTheCounterFor100000Time);

    t1.join();
    t2.join();

    std::cout << " counter could increase upto: " << counter << std::endl;

    return 0;
}
