#include "Feeder.h"
#include "bimodal.h"

int main()
{
    uint16_t pc;
    uint16_t pc_res;
    float wrong = 0;
    float total = 0;
    int if_br;
    int if_br_res;
    int prediction;

    for(int i = 0;i<197483;i++)
    {
    feeder_func(i,pc,if_br);

    cout<<" "<<pc<<" "<<if_br;

    if(if_br == 1 && pc!=0)
    {
        prediction = bimodal_func(pc,1);
        cout<<" ";
        feeder_func(i+3,pc_res,if_br_res);
        cout<<" "<<"Prediction:"<<prediction;

        if((pc_res!= (pc+3) && prediction == 0) || (pc_res == (pc+3) && prediction == 1))
        {
            bimodal_func(pc,2);
            wrong++;
        }
    total++;
   }

    cout<<endl;
    }
    
    int accuracy  = ((total - wrong) / total) * 100 ;
    cout<<"total : "<<total<<endl;
    cout<<"wrong : "<<wrong<<endl;
    cout<<"Accuracy  = "<<accuracy<<"%"<<endl;
    return 0;
}
