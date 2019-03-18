#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::save_heading(int strandlength)
{

one=fopen(one_path,"w");
fprintf(one,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","v","vdot","Iax","INa","Ito","ICa","IKr","IKs","APD");
fclose(one);

if (strandlength>=5)
	{
	two=fopen(two_path,"w");
	fprintf(two,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","v","vdot","Iax","INa","Ito","ICa","IKr","IKs","APD");
	fclose(two);
	
	three=fopen(three_path,"w");
	fprintf(three,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","v","vdot","Iax","INa","Ito","ICa","IKr","IKs","APD");
	fclose(three);

	four=fopen(four_path,"w");
	fprintf(four,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","v","vdot","Iax","INa","Ito","ICa","IKr","IKs","APD");
	fclose(four);
	
	five=fopen(five_path,"w");
	fprintf(five,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","v","vdot","Iax","INa","Ito","ICa","IKr","IKs","APD");
	fclose(five);
	}
}

void LRd::save(int x, int strandlength)
{
if (x==0 && save_flag==0 && strandlength==1)
	{
	voltages=fopen(voltages_path,"w");
	fprintf(voltages,"%-016e\t%-07g\n",
	t,p->v);
	fclose(voltages);
	save_flag=1;
	}
else if (x==0 && save_flag==1 && strandlength==1)
	{
	voltages=fopen(voltages_path,"a");
	fprintf(voltages,"%-016e\t%-07g\n",
	t,p->v);
	fclose(voltages);
	}
else if (x==0 && save_flag==0)
	{
	voltages=fopen(voltages_path,"w");
	fprintf(voltages,"%-016e\t%-07g\t",
	t,p->v);
	fclose(voltages);
	save_flag=1;
	}
else if (x==0 && save_flag==1)
	{
	voltages=fopen(voltages_path,"a");
	fprintf(voltages,"%-016e\t%-07g\t",
	t,p->v);
	fclose(voltages);
	}
else if (x==(strandlength-1))
	{
	voltages=fopen(voltages_path,"a");
	fprintf(voltages,"%-07g\n",
	p->v);
	fclose(voltages);
	}
else
	{
	voltages=fopen(voltages_path,"a");
	fprintf(voltages,"%-07g\t",
	p->v);
	fclose(voltages);
	}
	
double here=(double)x/(double)strandlength;
double there=(double)(x+1)/(double)strandlength;

if (x==0)
	{
	one=fopen(one_path,"a");	
	fprintf(one,"%-016e\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\n",
	t,p->v,p->vdot,Iaxfactor*(2.0*p->v-p->vwest-p->veast),INa,Ito,ICa,IKr,IKs,p->APD);
	fclose(one);
	}	
//else if (strandlength>=5 && here<=0.2 && there>0.2)
else if (x==14)
	{
	two=fopen(two_path,"a");
	fprintf(two,"%-016e\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\n",
        t,p->v,p->vdot,Iaxfactor*(2.0*p->v-p->vwest-p->veast),INa,Ito,ICa,IKr,IKs,p->APD);
	fclose(two);
	}
//else if (strandlength>=5 && here<=0.4 && there>0.4)	
else if (x==79)
	{
	three=fopen(three_path,"a");
	fprintf(three,"%-016e\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\n",
        t,p->v,p->vdot,Iaxfactor*(2.0*p->v-p->vwest-p->veast),INa,Ito,ICa,IKr,IKs,p->APD);
	fclose(three);
	}
//else if (strandlength>=5 && here<=0.6 && there>0.6)
else if (x==149)
	{
	four=fopen(four_path,"a");
	fprintf(four,"%-016e\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\n",
        t,p->v,p->vdot,Iaxfactor*(2.0*p->v-p->vwest-p->veast),INa,Ito,ICa,IKr,IKs,p->APD);
	fclose(four);
	}
else if (strandlength>=5 && here<=0.8 && there>0.8)
	{
	five=fopen(five_path,"a");
	fprintf(five,"%-016e\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\n",
        t,p->v,p->vdot,Iaxfactor*(2.0*p->v-p->vwest-p->veast),INa,Ito,ICa,IKr,IKs,p->APD);
	fclose(five);
	}
}
