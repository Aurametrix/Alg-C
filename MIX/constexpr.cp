#include <array>
#include <iostream>
#include <cstdint>

constexpr uint64_t fibonacci(uint64_t n) {
    uint64_t F0{0};
    uint64_t F1{1};
    uint64_t F{};

    if(n <= 1) {
        return n;
    } else {
        for(uint64_t i = 2; i <= n; ++i) {
            F = F0 + F1;
            F0 = F1;
            F1 = F;
        }
        return F;
    }
}

const uint64_t NN = 50;
constexpr std::array<uint64_t, NN> fill_array() {
    std::array<uint64_t, NN> v{0};
    for(uint64_t i = 0; i < NN; ++i) {
        v[i] = fibonacci(i);
    }
    return v;
}

int main() {
    constexpr std::array<uint64_t, NN> v = fill_array();
    std::cout << v[9] << '\n';
    std::cout << v[10] << '\n';    
}
