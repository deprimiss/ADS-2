// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double pow = value;
    for (uint16_t i = 1; i < n; i++)
        pow *= value;
    return pow;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1;
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
    for (uint16_t i = 0;i <= count;i++)
        e += calcItem(x, i);
    return e;
}

double sinn(double x, uint16_t count) {
    double sin = 0;
    uint16_t n = 2;
    for (uint16_t i = 1;i <= (2*count-1);i++) { 
        if ((i % 2 == 1) && (n % 2 == 1)) {
            sin += calcItem(x, i);
            n++;
        }
        else if ((i % 2 == 1) && (n % 2 == 0)) {
            sin -= calcItem(x, i);
            n++;
        }
    }
    return sin;
}

double cosn(double x, uint16_t count) {
    double cos = 1;
    uint16_t n = 1;
    for (uint16_t i = 2;i <= (2*count-2);i++) {
        if ((i % 2 == 0) && (n % 2 == 1)) {
            cos += calcItem(x, i);
            n++;
        }
        else if ((i % 2 == 0) && (n % 2 == 0)) {
            cos -= calcItem(x, i);
            n++;
        }
    }
    return cos;
}
