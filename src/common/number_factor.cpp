#include "number.h"

// factors exluding 1 and kNum itself
set<uint64_t> GetFactors(const uint64_t kNum)
{
  set<uint64_t> result;
  if (kNum <= 3)
    return result;

  // factor range: [a,b)
  uint64_t a = 2;
  uint64_t b = kNum - 1;
  uint64_t temp1, temp2;
  do
  {
    temp1 = kNum / a;
    if (temp1 == double(kNum) / a)
    {
      result.insert(a);
      if (a != temp1)
        result.insert(temp1);
      a = a + 1;
      temp1 = temp1 - 1;
    }

    temp2 = kNum / b;
    if (temp2 == double(kNum) / b)
    {
      result.insert(temp2);
      if (temp2 != b)
        result.insert(b);

      b = b - 1;
    }

    a = max(a, temp2 + 1);
    b = min(b, temp1);

    if (a > b)
      break;
  } while (1);

  return result;
}