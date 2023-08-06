#ifndef GSHARE_H
#define GSHARE_H


#include "Feeder.h"
#include "bimodal.h"
#include "bc2.h"
#include <unordered_map>


// enum STATE{
//     N = 0,
//     n = 1,
//     t = 2,
//     T = 3
// };

enum BHR_Values : uint16_t
{
    NNN = 0,
    NNT = 1,
    NTN = 2,
    NTT = 3,
    TNN = 4,
    TNT = 5,
    TTN = 6,
    TTT = 7
};

int gshare_predict(uint16_t, int);


#endif