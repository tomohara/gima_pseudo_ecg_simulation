#include <iostream>
#include <math.h>
#include <stdio.h>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::apd_heading()
{
apd_file=fopen(apd_path,"w");
fprintf(apd_file,"%-07s\t%-07s\t%-07s\n",
"variables=","cell#","APD");
fclose(apd_file);
}

void LRd::apd_save(int x)
{
apd_file=fopen(apd_path,"a");
fprintf(apd_file,"%-07i\t%-07g\n",
x,p->APD);
fclose(apd_file);
}
