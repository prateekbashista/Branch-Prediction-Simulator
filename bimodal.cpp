#include "bimodal.h"

class BHT{
    // unordered map
    private:
        unordered_map<uint16_t, int> BHT_cache;
    //max_size = 1024 Utilising the 10 bits of pc

    public:
       int BHT_check(uint16_t,int);
       void BHT_update(uint16_t,int,int);

};

int BHT::BHT_check(uint16_t index, int code)
{
    unordered_map<uint16_t, int> :: iterator element = BHT_cache.find(index);
    //cout<<" In BHT Check ";
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

void BHT::BHT_update(uint16_t index, int value, int code)
{   
    if(code == 1)
    {
        //cout<<" In BHT Update Code 1 ";
        BHT_cache[index] = value;

        // cout<<"Check Begin";
        // for (auto& pair : BHT_cache) {
        //     std::cout << pair.first << " : " << pair.second << "\n";
        // }
        // cout<<"Check End";

    }
    else if(code == 2)
    {
        unordered_map<uint16_t, int> :: const_iterator element1 = BHT_cache.find(index);

        if( element1 != BHT_cache.end())
        {
        if(element1->second == 1 )
        {
            BHT_cache[index] = 0;
        }
        else if (element1->second == 0 )
        {
            BHT_cache[index] = 1;
        }
        }
        else{
            cout<<" In BHT Update - Element Not Found ";
        }

        //BHT_cache.at(index) = 1;

    }
    
}

BHT bht_obj;

int bimodal_func(uint16_t pc, int code)
{       
    
    uint16_t index;
    index = pc & 4092;
    
    int prediction;
    cout<<" "<<"Index: "<<index;
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

