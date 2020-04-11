#ifndef __PRINTOUT_H__
#define __PRINTOUT_H__

#include "header.h"

template <typename T>
void Printout(vector<T> v, bool newline = false)
{
    for (auto a = v.begin(); a != v.end(); ++a)
        cout << *a;
    if (newline)
        cout << endl;
}

#endif // __PRINTOUT_H__