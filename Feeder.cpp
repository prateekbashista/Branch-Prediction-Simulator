#include "Feeder.h"

char hexDigits[16] = { '0', '1', '2', '3', '4', '5', '6', '7','8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

void feeder_func(int line,uint16_t &pc, int &if_br)
{
    fstream ctracer;
    string pc_imm;
    string insn;
    uint16_t pc_i = 0;
    int power = 0;


    ctracer.open("wireframe.ctrace", ios::in);

    if(!ctracer){
        cout<<"File not found !!";
        //return 0;
    }
    else {

            ctracer.seekg(50*line,ios::beg); 
            getline(ctracer, pc_imm, ' ');
            //ctracer.seekg(1,ios::cur); 
            getline(ctracer,insn, ' ');
            
            for(int k = 3; k>=0; k--)
            {
                for(int j =0 ; j<16 ; j++)
                {
                    if(pc_imm[k] == hexDigits[j])
                    {
                        pc_i = pc_i + j*pow(16,power);
                    }
                }
                power++;
            }
            pc = pc_i;
            cout<<pc_imm;
            // cout<<" "<<insn;
           // cout<<" "<<insn[0]<<insn[1]<<insn[2]<<insn[3];

            if(insn[0] == 48 && insn[1] == 48 && insn[2] == 48 && insn[3] == 48)
            {
                if_br = 1;
            }
            else
            {
                if_br = 0;
            }

    }


}