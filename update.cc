#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::update(int x)	
{
stim(x,stim_here);
revpots();
rates();
gates();
currents(x);
voltage(x);
dvdt(x);
fluxes();
buffers();
concentrations();
ECG(x);
}
