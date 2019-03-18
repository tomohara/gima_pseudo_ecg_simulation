#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::revpots()
{
const double PNaK=0.01833;

ENa=(R*T/F)*log(nao/p->nai);
ECaT=(R*T/(2.0*F))*log(cao/p->cai);
EKr=(R*T/F)*log(ko/p->ki);
EKs=(R*T/F)*log((ko+PNaK*nao)/(p->ki+PNaK*p->nai));
EK1=EKr;
EKp=EKr;
EKNa=EKr;
EKATP=EKr;
EnsCa=(R*T/F)*log((ko+nao)/(p->ki+p->nai));
ENab=ENa;
ECab=ECaT;
}
