#ifndef BC2_H
#define BC2_H


#include "Feeder.h"
#include "bimodal.h"
#include <unordered_map>


enum STATE{
    N = 0,
    n = 1,
    t = 2,
    T = 3
};

int bc2_predict(uint16_t, int);

#endif