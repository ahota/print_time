#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include <print_time.hpp>

#define TEST_LEN 1000000

int main(int argc, char **argv)
{
    // use std::cout by default
    print_time(500);

    // or use a user-specified stream for output
    print_time(1000, std::cout);
    print_time(10000, std::cerr);

    // or use a user-created stream
    std::ostream mystream(std::cout.rdbuf());
    print_time(61000, mystream);

    print_time(6610000);

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> vec;
    vec.resize(TEST_LEN);
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> rng(0, TEST_LEN);

    for(int &e : vec) {
        e = rng(gen);
    }
    std::sort(vec.begin(), vec.end());

    auto end = std::chrono::high_resolution_clock::now();

    // use an std::chrono::duration to print performance times
    print_time(end - start);
    return 0;
}
