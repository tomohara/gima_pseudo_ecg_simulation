#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::gates()
{
const double KmCaL=0.6e-3;
const double Kd=66;
const double nn=2.8;
const double khalf=0.25;
const double H=2.0;

p->m=alpha_m/(alpha_m+beta_m)-(alpha_m/(alpha_m+beta_m)-p->m)*exp(-dt*(alpha_m+beta_m));
p->h=alpha_h/(alpha_h+beta_h)-(alpha_h/(alpha_h+beta_h)-p->h)*exp(-dt*(alpha_h+beta_h));
p->j=alpha_j/(alpha_j+beta_j)-(alpha_j/(alpha_j+beta_j)-p->j)*exp(-dt*(alpha_j+beta_j));
p->zto=az/(az+bz)-(az/(az+bz)-p->zto)*exp(-dt*(az+bz));
p->yto=ay/(ay+by)-(ay/(ay+by)-p->yto)*exp(-dt*(ay+by));
p->d=d_inf-(d_inf-p->d)*exp(-dt/tau_d);
p->f=f_inf-(f_inf-p->f)*exp(-dt/tau_f);
fCa=1.0/(1.0+p->cai/KmCaL);
p->b=b_inf-(b_inf-p->b)*exp(-dt/tau_b);
p->g=g_inf-(g_inf-p->g)*exp(-dt/tau_g);
p->Xr=Xr_inf-(Xr_inf-p->Xr)*exp(-dt/tau_Xr);
rgate=1.0/(1.0+exp((p->v+9.0)/22.4));
p->Xs1=Xs1_inf-(Xs1_inf-p->Xs1)*exp(-dt/tau_Xs1);
p->Xs2=Xs2_inf-(Xs2_inf-p->Xs2)*exp(-dt/tau_Xs2);
Xi=1.0/(1.0+exp((p->v-56.26)/32.1));
K1_inf=alpha_K1/(alpha_K1+beta_K1);
Kp=1.0/(1.0+exp((7.488-p->v)/5.98));
PoNai=0.85/(1+pow(Kd/p->nai,nn));
PoV=0.8-0.65/(1+exp((p->v+125)/15));
PATP=1.0/(1.0+pow(khalf/ATPi,H));
}
