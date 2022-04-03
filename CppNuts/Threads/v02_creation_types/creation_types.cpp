#include <iostream>
#include <thread>

void fun(int x) {
    while (x-- > 0) {
        std::cout << x << std::endl;
    }
}

int main(int argc, char** argv) {
    std::thread t(fun, 10);
    t.join();
    return 0;
}
