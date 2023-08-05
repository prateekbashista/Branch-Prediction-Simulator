#include "Feeder.h"
#include "bimodal.h"
#include "bc2.h"

int main()
{
    uint16_t pc;
    uint16_t pc_res;
    float wrong = 0;
    float total = 0;
    int if_br;
    int if_br_res;
    int prediction;

    int predict_select;

    cout<<"Select the Predictor(1 = Bimodal, 2 = 2bc) : ";
    cin>>predict_select;
    cout<<endl;
    
    if(predict_select == 1)
    {
    
    for(int i = 0;i<17805;i++)
    {
    feeder_func(i,pc,if_br);

    cout<<" "<<pc<<" "<<if_br;

    if(if_br == 1 && pc!=0)
    {
        prediction = bimodal_func(pc,1);

        cout<<" ";
        cout<<" "<<"Prediction:"<<prediction<<" ";

        feeder_func(i+3,pc_res,if_br_res);
        
        if((pc_res!= (pc+3) && prediction == 0) ||  (pc_res == (pc+3) && prediction == 1)) // The branch was taken, but prediction was not taken
        {
            bimodal_func(pc,2);
            wrong++;
        }

    total++;
   }

    cout<<endl;
    }
    }

    else if(predict_select == 2)
    {
   
    for(int i = 0;i<17805;i++)
    {
    feeder_func(i,pc,if_br);

    cout<<" "<<pc<<" "<<if_br;

    if(if_br == 1 && pc!=0)
    {
        //prediction = bimodal_func(pc,1);
        prediction  = bc2_predict(pc,1);
        cout<<" ";
        cout<<" "<<"Prediction:"<<prediction<<" ";

        feeder_func(i+3,pc_res,if_br_res);
        
        if((pc_res!= (pc+3) && prediction == 0)) // The branch was taken, but prediction was not taken
        {
            //bimodal_func(pc,2);
            bc2_predict(pc,2);
            wrong++;
        }
        else if( (pc_res == (pc+3) && prediction == 1)) // The branch was not taken, but prediction was taken
        {
            bc2_predict(pc,3);
            wrong++;            
        }
        else if( (pc_res == (pc+3) && prediction == 0)) // The branch was not taken, but prediction was taken
        {
            bc2_predict(pc,3);            
        }
        else if((pc_res!= (pc+3) && prediction == 1)) // The branch was not taken, but prediction was taken
        {
            bc2_predict(pc,2);       
        }

    total++;
   }

    cout<<endl;
    }
    }
    int accuracy  = ((total - wrong) / total) * 100 ;
    cout<<"total : "<<total<<endl;
    cout<<"wrong : "<<wrong<<endl;
    cout<<"Accuracy  = "<<accuracy<<"%"<<endl;
    return 0;
}
