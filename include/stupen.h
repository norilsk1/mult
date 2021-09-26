#ifndef STUPEN_H
#define STUPEN_H
#include "geer.h"

//namespace stupen



class stupen
{
    public:
        stupen(int, int, float,float);

        geer* koleso;
        geer* shestern;
        float Ustup;
        void calc();
        void calc2();
        void calcObkol();
        void calcObSh();
   // geer geer1(int,float,int,float);
   // geer geer2(int,float,int,float);

        virtual ~stupen();

    protected:

    private:
};

#endif // STUPEN_H
