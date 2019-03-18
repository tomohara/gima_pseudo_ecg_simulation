#include <iostream>
#include <math.h>
#include <stdio.h>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

int main(int argc,char *argv[])
{
LRd cell(argv[1],argv[2]);

LRddata *stranddata;					
stranddata = new LRddata[cell.strandlength];

cell.save_heading(cell.strandlength);
cell.ecg_heading();

if (cell.stim_here>(cell.strandlength-1))
	{
	perror("stim_here is greater than strandlength");
	}

int i=1;

while (cell.t<cell.ft)			
	{
	for (int x=0;x<cell.strandlength;x++)
		{
		cell.p=&(stranddata[x]);
		
		if (x==0)
			{
			cell.p->vwest=cell.p->v;
			}
		else
			{
			cell.l=&(stranddata[x-1]);
			cell.p->vwest=cell.l->v;	
			}
			
		if (x==(cell.strandlength-1))
			{
			cell.p->veast=cell.p->v;
			}
		else
			{
			cell.r=&(stranddata[x+1]);
			cell.p->veast=cell.r->v;
			}
			
		cell.update(x);	
		
		if (i%cell.skip==0 && cell.t >= cell.startsave)
			{
			cell.save(x,cell.strandlength);
			}						
		}
	if (i%cell.skip==0 && cell.t >= cell.startsave)
		{
		cell.ecg_save();
                }

	cell.t+=cell.dt;
	
        i++;
	
	if (i%500000==0)
		{
		cout<<cell.t/cell.ft*100.0<<"% complete"<<endl;
		}
		
	if (isnan(cell.p->v))
		{
		perror("v is nan");
		break;
		}
	}	

cell.apd_heading();	
for (int x=0;x<cell.strandlength;x++)
	{
	cell.p=&(stranddata[x]);
	cell.apd_save(x);
	}

return(0);
}
