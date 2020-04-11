// Lexicographic permutations
/*
  A permutation is an ordered arrangement of objects. 
  For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
  If all of the permutations are listed numerically or alphabetically, 
  we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

  012   021   102   120   201   210

  What is the millionth lexicographic permutation of the 
  digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

  Answer:
	2783915460
*/

#include "1_99.h"

bool P24()
{
  try
  {
    int target = 1000000 - 1;
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<uint64_t> factorials;
    for (int i = 0; i <= 9; ++i)
      factorials.push_back(factorial(i));

    string result;
    for (int i = 9; i >= 0; --i)
    {
      int divide = target / factorials[i];
      target -= divide * factorials[i];
      for (size_t d = divide; d < digits.size(); ++d)
      {
        result += (to_string(digits[d]));
        digits.erase(digits.begin() + d);
        break;
      }

      if (target == 0)
      {
        for (size_t d = 0; d < digits.size(); ++d)
          result += (to_string(digits[d]));
        break;
      }
    }
    cout << result << endl;
    return true;
  }
  catch (...)
  {
    return false;
  }
}
