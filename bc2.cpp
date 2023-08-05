#include "bc2.h"

class BC2_BHT{
    // unordered map
        unordered_map<uint16_t, int> BHT_cache;
    //max_size = 1024 Utilising the 10 bits of pc
    public:
       int BHT_check(uint16_t,int);
       void BHT_update(uint16_t,int,int);

};

BC2_BHT BHT;

int BC2_BHT::BHT_check(uint16_t index, int code)
{
    unordered_map<uint16_t, int> :: iterator element = BHT_cache.find(index);

    if(element == BHT_cache.end())
    {
        BHT_update(index,N,code);
        cout<<" "<<" Prelim Prediction:"<<"N"<<" ";
        return N;

    }
    else
    {   
        if(element->second == 0)
        {
            cout<<" "<<"Prelim Prediction:"<<"N"<<" ";
        }
        else if(element->second == 1)
        {
            cout<<" "<<"Prelim Prediction:"<<"n"<<" ";
        }
        else if(element->second == 2)
        {
            cout<<" "<<"Prelim Prediction:"<<"t"<<" ";
        }
        else if(element->second == 3)
        {
            cout<<" "<<"Prelim Prediction:"<<"T"<<" ";
        }
        return element->second;
        
    }
}


void BC2_BHT::BHT_update(uint16_t index, int value, int code)
{   
    if(code == 1)
    {
        //cout<<" In BHT Update Code 1 ";
        BHT_cache[index] = value;

    }
    else if(code == 2)
    {
        unordered_map<uint16_t, int> :: const_iterator element1 = BHT_cache.find(index);

        if( element1 != BHT_cache.end())
        {
        if(element1->second == N )
        {
            BHT_cache[index] = n;
        }
        else if (element1->second == n )
        {
            BHT_cache[index] = t;
        }
        else if (element1->second == t )
        {
            BHT_cache[index] = T;
        }
        }
        else{
            cout<<" In BHT Update - Element Not Found ";
        }

    }
    else if(code == 3)
    {
        unordered_map<uint16_t, int> :: const_iterator element2 = BHT_cache.find(index);

        if( element2 != BHT_cache.end())
        {
        if(element2->second == T)
        {
            BHT_cache[index] = t;
        }
        else if (element2->second == t)
        {
            BHT_cache[index] = n;
        }
        else if (element2->second == n)
        {
            BHT_cache[index] = N;
        }
        }
        else{
            cout<<" In BHT Update - Element Not Found ";
        }
    }
    
}


int bc2_predict(uint16_t pc, int code)
{       
    uint16_t index;
    index = pc & 4092;
    
    int prediction;
    cout<<" "<<"Index: "<<index;
    if(code == 1){
        prediction = BHT.BHT_check(index,code);

        if(prediction == N || prediction == n)
        {
            return 0;
        }
        else if(prediction == T || prediction == t)
        {
            return 1;
        }
        
    }
    else if(code == 2 || code == 3)
    {   

        BHT.BHT_update(index,0,code);
        
    }
    
    return -1;
  
}

