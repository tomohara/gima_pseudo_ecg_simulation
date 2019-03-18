#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::fluxes()
{
const double Jup_max=0.00875;
const double CaNSR_max=15;
const double Kmrel=0.8e-3;
const double Kmup=0.92e-3;
const double Kleak=Jup_max/CaNSR_max;
const double tau_tr=180;
double grel_CICR=150/(1+exp(((ICa+ICab+IpCa+ICaT-2*INaCa)+5)/0.9));
double RyRopen=1.0/(1+exp((-p->t_CICR+4)/0.5));
double RyRclose=1-(1.0/(1+exp((-p->t_CICR+4)/0.5)));
const double tau_on_spont=2;
const double tau_off_spont=2;
const double Grel_spont=4;
double grel_spont=Grel_spont*(1-exp(-p->t_spont/tau_on_spont))*exp(-p->t_spont/tau_off_spont);
double Jrel_CICR;
double Jrel_spont;

Jrel_CICR=grel_CICR*RyRopen*RyRclose*(p->cajsr-p->cai);

Jrel_spont=grel_spont*(p->cajsr-p->cai);
	
Jrel=Jrel_CICR+Jrel_spont;

Jup=Jup_max*p->cai/(p->cai+Kmup);

Jleak=Kleak*p->cansr;

Jtr=(p->cansr-p->cajsr)/tau_tr;
}
