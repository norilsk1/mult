#ifndef GEER_H
#define GEER_H

#include <iostream>

class geer
{

    public:
        float n_ob,delta,temp;
        int z,stup;
        float D_delit,m,D_N;
geer(int, double, int, double, double);
geer(int, float, int, float);
void calcD();
void calcM();
void calcZ();
void printGeer();
void calcAll();
void calcOb(geer&);
        virtual ~geer();
//enum pitch {18,19,20};
    protected:
//double D_delit,m,D_N;
    private:

};
#endif // GEER_H

