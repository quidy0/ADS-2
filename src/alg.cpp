// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double r = value;
    if (n == 0) {
        return 1;
    }
    for (uint16_t i = 1; i < n; i++) {
        r = r * value;
    }
    return r;
}

uint64_t fact(uint16_t n) {
    uint64_t r = 1;
    for (uint16_t i = 1; i <= n; i++) {
        r = i * r;
    }
    return r;
}

double calcItem(double x, uint16_t n) {
    double r = (pown(x, n) / fact(n));
    return r;
}

double expn(double x, uint16_t count) {
    double r = 1;
    for (uint16_t i = 1; i <= count; i++) {
        r += calcItem(x, i);
    }
    return r;
}

double sinn(double x, uint16_t count) {
    double r = 0;
    bool flag = false;
    for (uint16_t i = 1; i < 2 * count; i += 2) {
        if (flag) {
            r -= calcItem(x, i);
            flag = false;
        } else {
            r += calcItem(x, i);
            flag = true;
        }
    }
    return r;
}

double cosn(double x, uint16_t count) {
    double r = 1;
    bool flag = true;
    for (uint16_t i = 2; i < 2 * count; i += 2) {
        if (flag) {
            r -= calcItem(x, i);
            flag = false;
        } else {
            r += calcItem(x, i);
            flag = true;
        }
    }
    return r;
}
