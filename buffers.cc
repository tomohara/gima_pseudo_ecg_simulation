#include <math.h>
#include <stdio.h>
#include <iostream>
#include "LRddata.h"
#include "LRd.h"

using namespace std;

void LRd::buffers()
{
trpn=trpnmax*p->cai/(p->cai+kmtrpn);
cmdn=cmdnmax*p->cai/(p->cai+kmcmdn);
csqn=csqnmax*p->cajsr/(p->cajsr+kmcsqn);
}
