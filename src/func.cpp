#include "../include/func.h"
#include <iostream>
#include <iomanip>
//#include "geer.h"




void func::calc(geer& g1, geer& g2, float Npp)
{
     using namespace std;
      g1.D_delit=static_cast<float>(228.6/(1+1.0/Npp));

        g1.calcAll();
        cout<<" смещение" <<g1.stup<<"-го колеса: "<<g1.delta<<endl;
        g2.D_delit=static_cast<float>(228.6-g1.D_delit);

        g2.calcAll();
        cout<<" смещение " <<g2.stup<<"-го колеса: "<<g2.delta<<endl;
        g2.calcOb(g1);
}

void func::proverca(geer& gg1,geer& gg2,geer& gg3,geer& gg4,float Npp1,float Npp2)
{
if (abs(gg2.n_ob-gg3.n_ob)<20)
{
     func::printGeerM(gg1);
    func::printGeerM(gg2);
    func::printGeerM(gg3);
    func::printGeerM(gg4);

    std::cout<<" OK"<<std::endl;
}
     else
     {
        Npp1=(gg2.n_ob-(abs(gg2.n_ob-gg3.n_ob))/2.0)/gg1.n_ob;
        Npp2=(gg4.n_ob)/(gg3.n_ob+(abs(gg2.n_ob-gg3.n_ob))/2.0);
         std::cout<<" обороты не совпали"<<std::endl;
        func::calc(gg1, gg2, Npp1);
        func::calc(gg4, gg3,(1.0/Npp2));
        std::cout<<" Передаточное число 2 ступени: "<<Npp2<<std::endl;
        std::cout<<" Передаточное число 1 ступени: "<<Npp1<<std::endl;
    func::printGeerM(gg1);
    func::printGeerM(gg2);
    func::printGeerM(gg3);
    func::printGeerM(gg4);

   // proverca(gg1,gg2,gg3,gg4,Npp1,Npp2);
     }
}
void func::printGeerM (geer& tempgeer)
{
    using namespace std;
  cout<<tempgeer.stup;
    cout<<" Z"<<tempgeer.stup<<"-"<<left<<setw(4)<<tempgeer.z;
    cout<<" M-"<<left<<setprecision(4)<<setw(10)<<tempgeer.m;
    cout<<right<<fixed<<setprecision(3)<<" D_d-"<<left<<setw(7)<<tempgeer.D_delit;
    cout<<setprecision(2)<<right<<"("<<setw(5)<<tempgeer.delta<<")";
    cout<<right<<setprecision(4)<<setw(5)<<"  D_N-"<<left<<setw(10)<<tempgeer.D_N;
    cout<<right<<setw(7)<<"  N об/мин-"<<setw(7)<<tempgeer.n_ob<<endl;
}
