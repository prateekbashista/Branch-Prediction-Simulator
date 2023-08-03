#ifndef BIMODAL_H
#define BIMODAL_H


#include "Feeder.h"
#include <unordered_map>

class BHT{
    // unordered map
    unordered_map<uint16_t, int> BHT_cache;
    //max_size = 1024 Utilising the 10 bits of pc

    public:
       int BHT_check(int,int);
       void BHT_update(int,int,int);

};

int bimodal_func(uint16_t, int);

#endif