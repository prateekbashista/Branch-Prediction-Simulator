#include "gshare.h"

class GSHARE{
    // unordered map
     //max_size = 1024 Utilising the 10 bits of pc
        unordered_map<uint16_t, int> BHT_cache;
        unordered_map<uint16_t,uint16_t> BHR;
    public:
       int BHT_check(uint16_t,int);
       void BHT_update(uint16_t,int,int);
       void BHR_update(uint16_t,int);
       uint16_t BHR_check(uint16_t);

};

GSHARE BHT_BHR;

int GSHARE::BHT_check(uint16_t index, int code)
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


void GSHARE::BHT_update(uint16_t index, int value, int code)
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

uint16_t GSHARE::BHR_check(uint16_t index)
{
    
    unordered_map<uint16_t, uint16_t> :: iterator element1 = BHR.find(index);
    
    if(element1 == BHR.end())
    {
        BHR[index] = NNN;
        cout<<""<<"BHR Table OUTPUT : "<<"NNN";
        return NNN;

    }
    else
    {
        if(element1->second == 0)
        {
            cout<<" "<<"BHR Table OUTPUT : "<<"NNN"<<" ";
        }
        else if(element1->second == 1)
        {
            cout<<" "<<"BHR Table OUTPUT : "<<"NNT"<<" ";
        }
        else if(element1->second == 2)
        {
            cout<<" "<<"BHR Table OUTPUT : "<<"NTN"<<" ";
        }
        else if(element1->second == 3)
        {
            cout<<" "<<"BHR Table OUTPUT : "<<"NTT"<<" ";
        }
        else if(element1->second == 4)
        {
            cout<<" "<<"BHR Table OUTPUT : "<<"TNN"<<" ";
        }
        else if(element1->second == 5)
        {
            cout<<" "<<"BHR Table OUTPUT : "<<"TNT"<<" ";
        }
        else if(element1->second == 6)
        {
            cout<<" "<<"BHR Table OUTPUT : "<<"TTN"<<" ";
        }
        else if(element1->second == 7)
        {
            cout<<" "<<"BHR Table OUTPUT : "<<"TTT"<<" ";
        }

        return element1->second;
    }


}

void GSHARE::BHR_update(uint16_t index,int code)
{   
    unordered_map<uint16_t, uint16_t> :: iterator element2 = BHR.find(index);

    switch (element2->second)
    {
    case NNN:
        if(code == 2)
        {
            BHR[index] = NNT;
        }
        else if(code == 3)
        {
            BHR[index] = NNN;
        }
        break;
    case NNT:
        if(code == 2)
        {
            BHR[index] = NTT;
        }
        else if(code == 3)
        {
            BHR[index] = NTN;
        }
        break;
    case NTN:
        if(code == 2)
        {
            BHR[index] = TNT;
        }
        else if(code == 3)
        {
            BHR[index] = TNN;
        }
        break;
    case NTT:
        if(code == 2)
        {
            BHR[index] = TTT;
        }
        else if(code == 3)
        {
            BHR[index] = TTN;
        }
        break;
    case TNN:
        if(code == 2)
        {
            BHR[index] = NNT;
        }
        else if(code == 3)
        {
            BHR[index] = NNN;
        }
        break;
    case TNT:
        if(code == 2)
        {
            BHR[index] = NTT;
        }
        else if(code == 3)
        {
            BHR[index] = NTN;
        }
        break;
    case TTN:
        if(code == 2)
        {
            BHR[index] = TNT;
        }
        else if(code == 3)
        {
            BHR[index] = TNN;
        }
        break;
    case TTT:
        if(code == 2)
        {
            BHR[index] = TTT;
        }
        else if(code == 3)
        {
            BHR[index] = TTN;
        }
        break;
    
    default: break;
    }
    
}


int gshare_predict(uint16_t pc, int code)
{       
    uint16_t index;
    index = pc & 4092;
    uint16_t BHT_index;   
    uint16_t BHR_res;
    int prediction;
    cout<<" "<<"Index for BHR: "<<index;

    BHR_res = BHT_BHR.BHR_check(index);
    BHT_index = BHR_res ^ index;
    cout<<" "<<"Index for BHT: "<<BHT_index;

    if(code == 1)
    {
        prediction = BHT_BHR.BHT_check(BHT_index,code);

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

        BHT_BHR.BHT_update(BHT_index,0,code);
        BHT_BHR.BHR_update(index,code);
        
    }
    
    return -1;

}


