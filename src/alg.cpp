// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    for (uint16_t i = 1; i < n; i++)
        value *= value;
    return value;
}

uint64_t fact(uint16_t n) {
    uint16_t res = 1;
    for (uint16_t i = 1;i <= n;i++)
        res *= i;
    return res;
}

double calcItem(double x, uint16_t n) {
    double it = 0;
    it = (pown(x, n) / fact(n));
    return it;
}

double expn(double x, uint16_t count) {
    double e = 0;
    for (uint16_t i = 0;i < count;i++)
        e += calcItem(x, i);
    return e;
}

double sinn(double x, uint16_t count) {
    double sin = 0;
    uint16_t n = 1;
    for (uint16_t i = 1;i <= count;i++) { 
        if ((i % 2 == 1) && (n % 2 == 1)) {
            sin += calcItem(x, i);
            n++;
        }
        if ((i % 2 == 1) && (n % 2 == 0)) {
            sin -= calcItem(x, i);
            n++;
        }
    }
    return sin;
}

double cosn(double x, uint16_t count) {
    double cos = 0;
    uint16_t n = 1;
    for (uint16_t i = 0;i < count;i++) {
        if ((i % 2 == 0) && (n % 2 == 1)) {
            cos += calcItem(x, i);
            n++;
        }
        if ((i % 2 == 0) && (n % 2 == 0)) {
            cos -= calcItem(x, i);
            n++;
        }
    }
    return cos;
}
