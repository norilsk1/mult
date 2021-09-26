#include "geer.h"

geer::geer(int stup1,double nn,int zz, double DD, double mm)
{
    //ctor
    D_delit=DD;
    n_ob=nn;
    z=zz;
    m=mm;
    stup=stup1;

}
geer::geer(int stup1, float nn,int zz, float DD)
{
    //ctor
    n_ob=nn;
    z=zz;
    m=1;
    D_delit=DD-2*m;
    D_N=DD;
    stup=stup1;
}

void geer::calcD()
{
    D_delit=static_cast<float>(m)*z;
    D_N=static_cast<float>(D_delit)+(2*static_cast<float>(m));
}
void geer::calcM()
{
    //static_cast<double>
     m=static_cast<float>(D_delit)/z;

}
void geer::calcZ()
{
    z=((D_delit)/m)+0.5; //z-int
}

void geer::calcAll()
{
    calcZ();
    temp=D_delit;
    calcD();
  //  if (temp>D_delit)
    delta=temp-D_delit;
  //  else delta=D_delit-temp;
}
void geer::calcOb(geer& para)
{
 n_ob=static_cast<float>(para.n_ob*para.D_delit)/D_delit;
}
void geer::printGeer()
{
    using namespace std;
     cout<<stup<<" колесo: "<<endl;
    cout<<"  Z"<<stup<<"-"<<z<<"  ";
    cout<<"  M-"<<m<<"   ";
    cout<<"  D_d-"<<D_delit<<"   ";
    cout<<"  D_N-"<<D_N<<"   ";
    cout<<"  N об/мин-"<<n_ob<<endl;
}
geer::~geer()
{
    //dtor
}
