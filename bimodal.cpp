#include "bimodal.h"

class BHT{
    // unordered map
    unordered_map<uint16_t, int> BHT_cache;
    int max_size = 1024;

    public:
       int BHT_store(int, int);
       void BHT_update(int,int);
       void BHT_size(int);

};

int BHT::BHT_store(int index, int value)
{
    unordered_map<uint16_t, int> :: iterator element = BHT_cache.find(index);

    if(element == BHT_cache.end())
    {
        BHT_update(index,value);
        return 0;

    }
    else
    {
        element->second  = 1;
    }

    
}

void BHT::BHT_update(int index, int value)
{
    BHT_cache[index] = value;
}


int bimodal_func(uint16_t pc)
{       

    uint16_t index;
    index = pc<<4;
    index = index >> 8;

    


}

