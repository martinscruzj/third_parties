cmake_minimum_required(VERSION 3.14)
project(MutexTryLock)
find_package(Threads REQUIRED)
add_executable(mutex_try_lock mutex_try_lock.cpp)
target_link_libraries(mutex_try_lock PRIVATE Threads::Threads)
