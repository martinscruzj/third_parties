#include <iostream>
#include <thread>

void run(int count) {
    using namespace std::literals::chrono_literals;
    while (count-- > 0) {
        std::cout << "CppNuts" << std::endl;
    }
    std::this_thread::sleep_for(5s);
}

int main(int argc, char** argv) {
    std::thread t1(run, 10);
    std::cout << "main()" << std::endl;
    t1.join();
    if (t1.joinable()) {
        t1.join();
    }
    std::cout << "main() after" << std::endl;
    return 0;
}
