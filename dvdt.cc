#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::dvdt(int x)
{
p->vdotold=p->vdot;
p->vdot=(p->v-p->vold)/dt;
if (p->APDflag==0 && p->v>-35 && p->vdot<p->vdotold)
	{
	p->vdotmax=p->vdotold;
	p->tvdotmax=t-dt;
	if (x==0)
		{
		tvdotmax_start=p->tvdotmax;
		}
	if (x==strandlength-1)
		{
		tvdotmax_end=p->tvdotmax;
		CV=1.65*1.0e3/(tvdotmax_end-tvdotmax_start);
		}
	p->APDflag=1;
	}
if	(p->APDflag==1 && p->v<0.9*p->vrest)
	{
	p->APD=t-p->tvdotmax;
	p->vrest=0;
	p->APDflag=0;
	}

p->dICa_total_old=p->dICa_total;
p->dICa_total=(p->ICa_total-p->ICa_total_old)/dt;
p->t_CICR=p->t_CICR+dt;
if (p->CICR==0 && p->vdot>10 && p->t_CICR>10)
	{
	p->CICR=1;
	}
if (p->CICR==1 && p->v>-35 && p->dICa_total>p->dICa_total_old)
	{
	p->t_CICR=0;
	p->CICR=0;
	}
	
p->t_spont=p->t_spont+dt;	
if (p->spont==0 && csqn>=csqnmax)
	{
	p->t_spont=0;
	p->spont=1;
	}
if (p->spont==1 && csqn<csqnmax)
	{
	p->spont=0;
	}		
}
