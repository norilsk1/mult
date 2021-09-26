#include "stupen.h"

stupen::stupen(int Zkol, int Zsh, float OBinp=10, float OBout=10)
{
    //ctor
    koleso= new geer(1,OBinp,Zkol,100);
    shestern= new geer(1,OBout,Zsh,100);

    //koleso.D_delit=(228.6*geer4.D_delit*N)/((228.6-geer4.D_delit)*(1+((geer4.D_delit*N)/(228.6-geer4.D_delit))));
   // shestern->D_delit=228.6-koleso->D_delit; //но нужен метод поссле ввода
//    geer3.D_delit=228.6-geer4.D_delit;
/*
    geer1.calcM();
    geer2.calcM();
    geer3.calcM();
    geer4.calcM();
     geer1.calcD();
    geer2.calcD();
    geer3.calcD();
    geer4.calcD();
    geer2.calcOb(geer1);
    geer3.calcOb(geer4);
    func::printGeerM(geer1);    //вывод промежуточного результата
    func::printGeerM(geer2);
    func::printGeerM(geer3);
    func::printGeerM(geer4);
    */
}

void stupen::calc()
{
 shestern->D_delit=228.6-koleso->D_delit;
 shestern->calcM();
 koleso->calcM();
 shestern->calcD();
 koleso->calcD();
 //shestern->calcOb(*koleso);

}
void stupen::calc2()
{
    /*
 using namespace std;
      g1.D_delit=static_cast<float>(228.6/(1+1.0/Npp));

        g1.calcAll();
        cout<<"смещение" <<g1.stup<<"-го колеса: "<<g1.delta<<endl;
        g2.D_delit=static_cast<float>(228.6-g1.D_delit);

        g2.calcAll();
        cout<<"смещение " <<g2.stup<<"-го колеса: "<<g2.delta<<endl;
        g2.calcOb(g1);
        */
}


void stupen::calcObkol()
{
    koleso->n_ob=shestern->n_ob*shestern->D_delit/koleso->D_delit;
//n_ob=static_cast<float>(para.n_ob*para.D_delit)/D_delit;
}
void stupen::calcObSh()
{
shestern->n_ob=koleso->n_ob*koleso->D_delit/shestern->D_delit;
}
stupen::~stupen()
{
    //dtor
}
