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
    for (uint16_t i = 1; i <= n; i++)
        res *= i;
    return res;
}

double calcItem(double x, uint16_t n) {
    return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
    double e = 0;
    for (uint16_t i = 0; i <= count; i++)
        e += calcItem(x, i);
    return e;
}

double sinn(double x, uint16_t count) {
    double sin = 0;
    for (uint16_t i = 1; i <= count; i++) {
            sin += pown(-1, i + 1)*calcItem(x, 2 * i - 1);
        }
    return sin;
}

double cosn(double x, uint16_t count) {
    double cos = 1;
    for (uint16_t i = 2; i <= count; i++) {
            cos += pown(-1, i)*calcItem(x, i * 2 - 2);
    }
    return cos;
}
