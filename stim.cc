#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::stim(int x, int stim_here)
{
if (x==stim_here && (fabs(t-(start+n*CL))<1e-6 || fabs(t-(start+duration+n*CL-dt))<1e-6 || (t>(start+n*CL) && t<(start+duration+n*CL-dt))))
	{
	Ist=amp;
	}    
else if (t>(start+duration+n*CL-dt))
	{   
	Ist=0.0;
	n++;
	}
else
	{
	Ist=0.0;
	}
}
