#include "Feeder.h"

int main()
{
    uint16_t pc;
    int if_br;

    for(int i = 0;i<17805;i++)
    {
    feeder_func(i,pc,if_br);

    cout<<" "<<pc<<" "<<if_br<<endl;
    }

    return 0;
}