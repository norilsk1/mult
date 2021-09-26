//#include <iostream>
#include <windows.h>
#include <locale.h>
#include "geer.h"
#include "func.h"
#include "stupen.h"

using namespace std;

float Np1,Np2;  //глобальные переменные это плохо
int main()
{

stupen* stupenT= new stupen(116,57,2960.0,10);
stupen* stupenB= new stupen(113,67,10,10160.0);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
string inp;
 float N,n1,n4;
 n1=2960.0;
 //n2=10.0;
  //n3=10.0;
   n4=10160.0;

 N=static_cast<float>(n4)/n1;
//double Np1,Np2;
    geer geer1(1,2960.0,116,100);
    geer geer2(2,1000,57,100);
    geer geer3(3,4000,113,100);
    geer geer4(4,10160.0,67,100);

    //----------------------------
    while (inp!="next")
    {
         cout<<"общее N: "<<N<<endl;;
    cout<<"наружный диаметр 4 колеса: ";
    cin>>geer4.D_delit;
cout<<"наружный диаметр 1 колеса: ";
    cin>>stupenT->koleso->D_delit;
//stupenT->calc();
//cout<<"print koleso"<<endl;
//stupenT->koleso->printGeer();
 //func::printGeerM(*stupenT->koleso);
   // geer4.D_delit=geer1.D_delit/(228.6*10160/2960-geer1.D_delit*10160/2960-1);
    //stupenT->koleso->D_delit=(228.6*stupenB->shestern->D_delit*N)/((228.6-stupenB->shestern->D_delit)*(1+((stupenB->shestern->D_delit*N)/(228.6-stupenB->shestern->D_delit))));
stupenB->koleso->D_delit=(N*228.6*(228.6-stupenT->koleso->D_delit))/
(stupenT->koleso->D_delit*(1+(228.6-stupenT->koleso->D_delit)*N/stupenT->koleso->D_delit));


    stupenT->calc();
    stupenB->calc();
    stupenT->calcObSh();
    stupenB->calcObkol();

    func::printGeerM(*stupenT->koleso);
    func::printGeerM(*stupenT->shestern);  //переписать по ступеням пллплплл
    func::printGeerM(*stupenB->koleso);
    func::printGeerM(*stupenB->shestern);


    geer1.D_delit=(228.6*geer4.D_delit*N)/((228.6-geer4.D_delit)*(1+((geer4.D_delit*N)/(228.6-geer4.D_delit))));
    geer2.D_delit=228.6-geer1.D_delit;
    geer3.D_delit=228.6-geer4.D_delit;

    geer1.calcM();
    geer2.calcM();
    geer3.calcM();
    geer4.calcM();
 //   geer2.calcOb(geer1);
  //  geer3.calcOb(geer4);
//cout<<"до прощета calcD"<<endl;
 /*   func::printGeerM(geer1);    //вывод промежуточного результата
    func::printGeerM(geer2);
    func::printGeerM(geer3);
   func::printGeerM(geer4);*/
  //  cout<<"после прощета calcD"<<endl;
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



    cout <<"next?"<< endl;
    cin>>inp;
    }

    while (inp!="exit")
        {
    cout<<"модуль 1 передачи-"<<endl;
    cin>>geer1.m;

    cout<<"модуль второй передачи"<<endl;
    cin>>geer3.m;

    cout<<"передаточное число первой передачи"<<endl;
    cin>>Np1;
    cout<<"передаточное число 1 передачи"<<Np1<<endl;


        geer2.m=geer1.m;
        geer4.m=geer3.m;
        func::calc(geer1, geer2, Np1);


    Np2=static_cast<float>(n4)/(n1*Np1);  cout<<"Передаточное число 2 ступени: "<<Np2<<endl;

        func::calc(geer4, geer3,(1.0/Np2));

    func::printGeerM(geer1);
    func::printGeerM(geer2);
    func::printGeerM(geer3);
    func::printGeerM(geer4);

func::proverca(geer1,geer2,geer3,geer4,Np1,Np2);

    cout <<"exit?"<< endl;
    cin>>inp;
}
    return 0;
}

