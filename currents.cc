#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::currents(int x)
{
double GNa=16;
double GCaT=0.05;
double GKr=0.02614*sqrt(ko/5.4);
double GKs=(35.0/23.0)*0.433*(1.0+0.6/(1+pow(3.8e-5/p->cai,1.4)));
double GK1=0.75*sqrt(ko/5.4);	
double GKp=0.00552;
double GKNa=0.12848;
double Nichols=5.0e-3;
double GKATP=195e-6/Nichols;	
double konorm=4.0;
double gKATP=GKATP*PATP*pow(ko/konorm,0.24);
double GNab=0.004;	
double GCab=0.003016;
double PCa=5.4e-4;
double PNa=6.75e-7;
double PK=1.93e-7;
double PnsCa=1.75e-7;	
double Kmnai=10;
double Kmko=1.5;
double KmnsCa=1.2e-3;
double KmpCa=0.5e-3;
double gama_cai=1;
double gama_cao=0.341;
double gama_nai=0.75;
double gama_nao=0.75;
double gama_ki=0.75;
double gama_ko=0.75;
double sigma=(1.0/7.0)*(exp(nao/67.3)-1);
double fNaK=1.0/(1.0+0.1245*exp(-0.1*p->v*F/(R*T))+0.0365*sigma*exp(-p->v*F/(R*T)));
double c1=0.00025;
double c2=0.0001;
double gama=0.15;
double ICa_max=PCa*4*p->v*F*F/(R*T)*(gama_cai*p->cai*exp(2.0*p->v*F/(R*T))-gama_cao*cao)/(exp(2*p->v*F/(R*T))-1.0);
double ICaNa_max=PNa*p->v*F*F/(R*T)*(gama_nai*p->nai*exp(p->v*F/(R*T))-gama_nao*nao)/(exp(p->v*F/(R*T))-1.0);
double ICaK_max=PK*p->v*F*F/(R*T)*(gama_ki*p->ki*exp(p->v*F/(R*T))-gama_ko*ko)/(exp(p->v*F/(R*T))-1.0);
double INaK_max=2.25;	
double InsNa_max=PnsCa*p->v*F*F/(R*T)*(gama_nai*p->nai*exp(p->v*F/(R*T))-gama_nao*nao)/(exp(p->v*F/(R*T))-1.0);
double InsK_max=PnsCa*p->v*F*F/(R*T)*(gama_ki*p->ki*exp(p->v*F/(R*T))-gama_ko*ko)/(exp(p->v*F/(R*T))-1.0);
double IpCa_max=1.15;	
INa=GNa*pow(p->m,3)*p->h*p->j*(p->v-ENa);

double itofactor;
if (x<endo)
{
itofactor=0.0;//Gima
}
else if (x<M)
{
itofactor=(0.2125/0.25);//Gima
}
else
{
itofactor=1;
}
//Ito=itofactor*0.25*pow(p->zto,3)*p->yto*exp(p->v/100.0)*(p->v-EKr);//Gima
Ito=itofactor*3*0.25*pow(p->zto,3)*p->yto*exp(p->v/100.0)*(p->v-EKr);//Gima RVOT

ICa=p->d*p->f*fCa*ICa_max;
ICaNa=p->d*p->f*fCa*ICaNa_max;
ICaK=p->d*p->f*fCa*ICaK_max;
ICaT=GCaT*pow(p->b,2)*p->g*(p->v-ECaT);
IKr=GKr*p->Xr*rgate*(p->v-EKr);

double iksfactor;
if (x<endo)
{
iksfactor=(11.0/35.0);//gima
}
else if (x<M)
{
iksfactor=(4.0/35.0);//gima
}
else
{
iksfactor=1;
}
IKs=iksfactor*GKs*p->Xs1*p->Xs2*(p->v-EKs);

IK1=GK1*K1_inf*(p->v-EK1);
IKp=GKp*Kp*(p->v-EKp);
//IKNa=GKNa*Ponai*Pov*(p->v-EKNa); //Na that comes through the K channel (which isn't fully selective)
IKNa=0;
//IKATP=gKATP*(p->v-EKATP);
IKATP=0;
INaCa=c1*exp((gama-1)*p->v*F/(R*T))*((exp(p->v*F/(R*T))*pow(p->nai,3)*cao-nao*nao*nao*p->cai)/(1+c2*exp((gama-1)*p->v*F/(R*T))*(exp(p->v*F/(R*T))*pow(p->nai,3)*cao+nao*nao*nao*p->cai)));
INaK=INaK_max*fNaK*ko/((1.0+pow(Kmnai/p->nai,2))*(ko+Kmko));
//InsNa=InsNa_max/(1.0+pow(KmnsCa/cai,3.0));
InsNa=0;
//InsK=InsK_max/(1.0+pow(KmnsCa/cai,3.0));
InsK=0;
IpCa=IpCa_max*p->cai/(KmpCa+p->cai);
INab=GNab*(p->v-ENab);
ICab=GCab*(p->v-ECab);
p->ICa_total_old=p->ICa_total;
p->ICa_total=ICa+ICaT-2*INaCa+IpCa+ICab;
Ii=INa+Ito+ICa+ICaNa+ICaK+ICaT+IKr+IKs+IK1+IKp+IKNa+IKATP+INaCa+INaK+InsNa+InsK+IpCa+INab+ICab;
}
