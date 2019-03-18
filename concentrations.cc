#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::concentrations()
{
double dcai;
double dcait;
double y,z,u;
double dcajsr;
double dcajsrt;
p->nai=p->nai-dt*(INa+ICaNa+3.0*INaCa+3.0*INaK+InsNa+INab)*Acap/(vmyo*F);
p->ki=p->ki-dt*(Ito+ICaK+IKr+IKs+IK1+IKp+IKNa+IKATP-2.0*INaK+InsK+Ist)*Acap/(vmyo*F);
p->cansr=p->cansr+dt*(Jup-Jleak-Jtr*vjsr/vnsr);
//dcai=-dt*((ICa+ICaT-2.0*INaCa+IpCa+ICab)*Acap/(vmyo*2.0*F)+(Jup-Jleak)*vnsr/vmyo-Jrel*vjsr/vmyo);
//dcait=dcai/(1+cmdnmax*kmcmdn/pow(kmcmdn+p->cai,2)+trpnmax*kmtrpn/pow(kmtrpn+p->cai,2));
//p->cai=p->cai+dcait;

dcai=-dt*(ICa+ICaT-2.0*INaCa+IpCa+ICab)*Acap/(vmyo*2.0*F)+dt*Jleak*vnsr/vmyo+dt*Jrel*vjsr/vmyo-dt*Jup*vnsr/vmyo;
dcait=trpn+cmdn+dcai+p->cai;
y=cmdnmax+trpnmax-dcait+kmtrpn+kmcmdn;
z=kmcmdn*kmtrpn-dcait*(kmtrpn+kmcmdn)+trpnmax*kmcmdn+cmdnmax*kmtrpn;
u=-kmtrpn*kmcmdn*dcait;
p->cai=(2.0/3.0)*sqrt(y*y-3.0*z)*cos(acos((9.0*y*z-2.0*y*y*y-27.0*u)/(2.0*pow(y*y-3.0*z,1.5)))/3.0)-y/3.0;
//p->cai=1e-4;


dcajsr=dt*(Jtr-Jrel);
dcajsrt=dcajsr/(1+csqnmax*kmcsqn/pow(kmcsqn+p->cajsr,2));
p->cajsr=p->cajsr+dcajsrt;
}
