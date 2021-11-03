#include "euler.h"

EulerC::EulerC()
{
    func_.insert(pair<int, fp>(1, P1));
    func_.insert(pair<int, fp>(2, P2));
    func_.insert(pair<int, fp>(3, P3));
    func_.insert(pair<int, fp>(4, P4));
    func_.insert(pair<int, fp>(5, P5));
    func_.insert(pair<int, fp>(6, P6));
    func_.insert(pair<int, fp>(7, P7));
    func_.insert(pair<int, fp>(8, P8));
    func_.insert(pair<int, fp>(9, P9));
    func_.insert(pair<int, fp>(10, P10));
    func_.insert(pair<int, fp>(11, P11));
    func_.insert(pair<int, fp>(12, P12));
    func_.insert(pair<int, fp>(13, P13));
    func_.insert(pair<int, fp>(14, P14));
    func_.insert(pair<int, fp>(15, P15));
    func_.insert(pair<int, fp>(16, P16));
    func_.insert(pair<int, fp>(17, P17));
    func_.insert(pair<int, fp>(18, P18));
    func_.insert(pair<int, fp>(19, P19));
    func_.insert(pair<int, fp>(20, P20));
    func_.insert(pair<int, fp>(21, P21));
    func_.insert(pair<int, fp>(22, P22));
    func_.insert(pair<int, fp>(23, P23));
    func_.insert(pair<int, fp>(24, P24));
    func_.insert(pair<int, fp>(25, P25));
    func_.insert(pair<int, fp>(26, P26));
    func_.insert(pair<int, fp>(27, P27));
    func_.insert(pair<int, fp>(28, P28));
    func_.insert(pair<int, fp>(29, P29));
    func_.insert(pair<int, fp>(30, P30));
    func_.insert(pair<int, fp>(31, P31));
    // func_.insert(pair<int, fp>(32, P32));
    func_.insert(pair<int, fp>(33, P33));
    // func_.insert(pair<int, fp>(34, P34));
    // func_.insert(pair<int, fp>(35, P35));
    // func_.insert(pair<int, fp>(36, P36));
    // func_.insert(pair<int, fp>(37, P37));
    // func_.insert(pair<int, fp>(38, P38));
    func_.insert(pair<int, fp>(39, P39));
    func_.insert(pair<int, fp>(48, P48));
    func_.insert(pair<int, fp>(50, P50));
    func_.insert(pair<int, fp>(52, P52));
    func_.insert(pair<int, fp>(56, P56));
    func_.insert(pair<int, fp>(67, P67));
    func_.insert(pair<int, fp>(69, P69));
    func_.insert(pair<int, fp>(112, P112));
    func_.insert(pair<int, fp>(113, P113));
    func_.insert(pair<int, fp>(223, P223));
}

fp EulerC::Func(int id)
{
    if (func_[id])
        return func_[id];
}

EulerC g_euler;
