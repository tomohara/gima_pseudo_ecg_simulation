#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::voltage(int x)
{
p->vold=p->v;

double gj_use;
if (x>=104 && x<=107)
{
gj_use=gj_epi_factor*gj;
}
else
{
gj_use=gj;
}

double Rg=3.14159*pow(radius*1e-4,2)/(gj_use*1.0e-6);
Iaxfactor=0.1*(radius*1e-4)/(4.0*(Rmyo+Rg/(dX*1.0e-4))*pow(dX*1.0e-6,2.0));
p->v+=dt/C*(0.1*(radius*1e-4)/(4.0*(Rmyo+Rg/(dX*1.0e-4))*pow(dX*1.0e-6,2.0))*(p->veast-2*p->v+p->vwest)-(Ii+Ist));
}
