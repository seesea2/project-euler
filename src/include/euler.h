#ifndef __EULER_H__
#define __EULER_H__

#include "header.h"
#include "1_99.h"
#include "100_199.h"
#include "200_299.h"
#include "300_399.h"
#include "400_499.h"
#include "500_599.h"

typedef bool (*fp)();
class EulerC
{
public:
    EulerC();
    fp Func(int id);

private:
    map<int, fp> func_;
};

extern EulerC g_euler;

#endif // __EULER_H__