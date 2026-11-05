//
// Created by KIIT0001 on 30-09-2026.
//

#include "math.h"

uint32_t factorial(uint32_t n) {
    return n <= 1 ? 1 : n * factorial(n-1);
}

// calculate nPk
uint32_t pick(uint32_t n, uint32_t k) { // How many ways can I select k elements from n elements when order matters?
    return factorial(n) / factorial(n-k);  // p(n,k)=n!/(n-k)!
}

// calculate nCk
uint32_t choose(uint32_t n, uint32_t k) {   // How many ways can I select k elements from n elements when order does NOT matter?
    return (n<k) ? 0 : factorial(n) / factorial(n-k) * factorial(k); // c(n,k)=n!/((n-k)!*k!)
}
