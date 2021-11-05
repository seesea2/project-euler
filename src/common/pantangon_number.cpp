#include "number.h"

uint64_t PantagonNum(const uint64_t n)
{
    return n * (3 * n - 1) / 2;
}
