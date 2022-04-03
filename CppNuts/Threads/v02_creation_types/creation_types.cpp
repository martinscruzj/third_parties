#include <iostream>
#include <thread>

void fun1(int x) {
    while (x-- > 0) {
        std::cout << x << std::endl;
    }
}

class Functor {
public:
    void operator()(int x) {
        while (x-- > 0) {
            std::cout << x << std::endl;
        }
    }
};

class MyClass {
public:
    void run1(int x) {
        while (x-- > 0) {
            std::cout << x << std::endl;
        }
    }
    static void run2(int x) {
        while (x-- > 0) {
            std::cout << x << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    // Create thread using function pointer
    std::thread t1(fun1, 10);

    // Create thread using lambda function
    std::thread t2([](int x) {
        while (x-- > 0) {
            std::cout << x << std::endl;
        }
    }, 10);
    
    // Create thread using functor
    std::thread t3((Functor()), 10);
    
    // Create thread using non-static member function
    MyClass b;
    std::thread t4(&MyClass::run1, &b, 10);
    
    std::thread t5(&MyClass::run2, 10);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}
