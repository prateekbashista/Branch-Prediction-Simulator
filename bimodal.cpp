#include "bimodal.h"

class BHT{
    // unordered map
    unordered_map<uint16_t, int> BHT_cache;
    //int max_size = 1024;

    public:
       int BHT_check(int,int);
       void BHT_update(int,int,int);

};

int BHT::BHT_check(int index, int code)
{
    unordered_map<uint16_t, int> :: iterator element = BHT_cache.find(index);

    if(element == BHT_cache.end())
    {
        BHT_update(index,0,code);
        return 0;

    }
    else
    {
        return element->second;
    }

    
}

void BHT::BHT_update(int index, int value, int code)
{   
    if(code == 1)
    {
        BHT_cache[index] = value;
    }
    else if(code == 2)
    {
        unordered_map<uint16_t, int> :: iterator element1 = BHT_cache.find(index);
        
        if(element1->second == 1)
        {
            BHT_cache[index] = 0;
        }
        else{
            BHT_cache[index] = 1;
        }

    }
    
}


int bimodal_func(uint16_t pc, int code)
{       
    BHT bht_obj;
    uint16_t index;
    index = pc<<4;
    index = index >> 8;
    int prediction;

    if(code == 1){
        prediction = bht_obj.BHT_check(index,code);
        return prediction;
    }
    else if(code == 2)
    {   

        bht_obj.BHT_update(index,0,2);
        
    }
    
    return -1;
}

