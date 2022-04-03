#include <iostream>
#include <chrono>
#include <thread>

typedef unsigned long long ull;

ull EvenSum = 0;
ull OddSum = 0;

void findEven(ull start, ull end) {
   for (ull i = start; i <= end; ++i) {
      if ((i & 1) == 0) {
         EvenSum += i;
      }
   }
}

void findOdd(ull start, ull end) {
   for (ull i = 0; i <= end; ++i) {
      if ((i & 1) == 1) {
         OddSum += i;
      }
   }
}

int main(int argc, char** argv) {
   ull start = 0, end = 1900000000;
   
   auto startTime = std::chrono::high_resolution_clock::now();

   std::thread t1(findEven, start, end);
   std::thread t2(findOdd, start, end);

   t1.join();
   t2.join();

   //findOdd(start, end);
   //findEven(start, end);
   
   auto stopTime = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

   std::cout << "OddSum : " << OddSum << std::endl;
   std::cout << "EvenSum : " << EvenSum << std::endl;
   std::cout << "Sec: " << duration.count()/1000000 << std::endl;

   return 0;
}
