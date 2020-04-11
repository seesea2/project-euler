#include "header.h"

template <typename T>
void printout(vector<T> v, bool newline = false)
{
  for (auto a = v.begin(); a != v.end(); ++a)
    cout << *a;
  if (newline)
    cout << endl;
}