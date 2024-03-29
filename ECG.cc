#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::ECG(int x)
{
if (x==0)
	{
	Phi=0.0;
	gradV=0;
	}
if (x>=15 && x <= 149)//do not include the 15 cells at the ends as in gima & rudy
	{
	double K=1;
	Phi+=K*(p->vwest-p->veast)/pow(2.0+(strandlength-x)/100.0,2.0);
	gradV+=(p->vwest-p->veast);
	}
}

void LRd::ecg_heading()
{
ecg_file=fopen(ecg_path,"w");
fprintf(ecg_file,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","Phi","gradV","CV");
fclose(ecg_file);
}

void LRd::ecg_save()
{
ecg_file=fopen(ecg_path,"a");
fprintf(ecg_file,"%-016e\t%-07g\t%-07g\t%-07g\n",
t,Phi,gradV,CV);
fclose(ecg_file);
}
