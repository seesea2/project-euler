#include "number.h"

uint64_t factorial(const int num)
{
  uint64_t rslt = 1;
  for (auto i = num; i > 0; --i)
  {
    rslt *= i;
  }
  return rslt;
}