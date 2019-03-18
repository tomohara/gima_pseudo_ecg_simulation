#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

LRd::LRd(char argv1[],char argv2[])
{
strandlength=165;

stim_here=0;

CL=300;

ft=300;

start=1;
amp=-600;
duration=0.5;

endo=60;
M=105;
epi=strandlength-1;

t=0.0;
dt=0.005;
save_flag=0;
n=0;
skip=400;
startsave=ft-CL;
gj=1.73;
gj_epi_factor=0.2;
Rmyo=150;
radius=11;
dX=100;

nao=150;	
cao=1.8;
ko=4;
ATPi=3.0;
C=1.0;	
R=8314;	
T=310;	
F=96485;	
L=0.01;
rad=0.0011;
vcell=1000*3.14*rad*rad*L;
Ageo=2*3.14*rad*rad+2*3.14*rad*L;
Acap=2*Ageo;
vmyo=0.68*vcell;
vmito=0.26*vcell;
vsr=0.06*vcell;
vnsr=0.0552*vcell;
vjsr=0.0048*vcell;
trpnmax=0.07;
kmtrpn=0.0005;
cmdnmax=0.05;
kmcmdn=0.00238;
csqnmax=10.0;
kmcsqn=0.8;

CV=0.0;

sprintf(apd_path,"./output/apd_file_%s_%s.txt",argv1,argv2);
sprintf(voltages_path,"./output/voltages_%s_%s.txt",argv1,argv2);
sprintf(one_path,"./output/one_%s_%s.txt",argv1,argv2);
sprintf(two_path,"./output/two_%s_%s.txt",argv1,argv2);
sprintf(three_path,"./output/three_%s_%s.txt",argv1,argv2);
sprintf(four_path,"./output/four_%s_%s.txt",argv1,argv2);
sprintf(five_path,"./output/five_%s_%s.txt",argv1,argv2);
sprintf(ecg_path,"./output/ecg_%s_%s.txt",argv1,argv2);
}
