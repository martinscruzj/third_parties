#include <iostream>
#include <thread>

void run(int count) {
    using namespace std::literals::chrono_literals;
    while (count-- > 0) {
        std::cout << count << " CppNuts" << std::endl;
    }
    //std::this_thread::sleep_for(5s);
    std::cout << "thread finished" << std::endl;
}

int main(int argc, char** argv) {
    using namespace std::literals::chrono_literals;
    std::thread t1(run, 10);
    std::cout << "main()" << std::endl;
    t1.detach();
    if (t1.joinable()) {
        t1.detach();
    }
    std::cout << "main() after" << std::endl;
    //std::this_thread::sleep_for(5s);
    return 0;
}
