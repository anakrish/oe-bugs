#include <iostream>
#include <exception>
#include <chrono>

#include "test_t.h"

using namespace std::chrono;

void foo() {
    auto a = high_resolution_clock::now();
}

extern "C" int test() {
    // Calling foo() leads to an abort, and oe-gdb doesn't stop.
    // This is unexpected and makes debugging hard.
    try {
        foo();
    } catch (std::exception& exc) {
        std::cerr << exc.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }
    return 0;
}
