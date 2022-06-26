#ifndef _CALC_H
#define _CALC_H

#include "cstdlib"

using namespace std;

bool Rand(int x);

bool Rand(int x){//百分数随机
    return rand()%100<x;
}

#endif