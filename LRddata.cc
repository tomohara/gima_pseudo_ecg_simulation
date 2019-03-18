#include <iostream>
#include <math.h>
#include <stdio.h>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

LRddata::LRddata()
{
v=-91;
vwest=v;
veast=v;
vrest=v;
nai=14.603;
cai=0.00008278;
ki=140.516;
cansr=1.2;
cajsr=1.2;
m=0;
h=1;
j=1;
zto=0;
yto=1;
a=0;
i=1;
i2=1;
d=0;
f=1;
b=0;
g=1;
Xr=0;
Xs1=0;
vold=v;
vdot=0;
vdotmax=0;
tvdotmax=0;
CICR=0;
spont=0;
t_CICR=1e6;
t_spont=1e6;
vdotold=0;
APD=0;
APDflag=0;
}
