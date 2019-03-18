class LRd
{
public:

LRd();
LRd(char argv1[], char argv2[]);
 
LRddata *p,*l,*r;

FILE *ecg_file,*apd_file,*voltages,*one,*two,*three,*four,*five;

char ecg_path[250],apd_path[250],voltages_path[250],one_path[250],two_path[250],three_path[250],four_path[250],five_path[250];

double theta[29];

void ECG(int x),ecg_heading(),ecg_save(),apd_heading(),apd_save(int x),revpots(),rates(),gates(),currents(int x),stim(int x, int stim_here),voltage(int x),dvdt(int x),fluxes(),buffers(),concentrations(),update(int x),save_heading(int strandlength),save(int x, int strandlength);	

int endo,M,epi;

double t,dt,ft;

int skip;
double startsave;
int strandlength;

double CL,start,amp,duration;
int n,stim_here;

int save_flag;

double radius,gj,gj_epi_factor,Rmyo,dX;

double nao,cao,ko,ATPi;
double C,R,T,F;	
double L,rad,vcell,Ageo,Acap,vmyo,vmito,vsr,vnsr,vjsr;
double trpnmax,kmtrpn,cmdnmax,kmcmdn,csqnmax,kmcsqn;
double trpn,cmdn,csqn;	
double fCa,rgate,Xi,K1_inf,Kp,PoNai,PoV,PATP;
double ENa,ECaT,EKr,EKs,EK1,EKp,EKNa,EKATP,EnsCa,ENab,ECab;
double alpha_m,beta_m,alpha_h,beta_h,alpha_j,beta_j,az,bz,ay,by,d_inf,tau_d,f_inf,tau_f,b_inf,tau_b,g_inf,tau_g,Xr_inf,tau_Xr,Xs1_inf,Xs2_inf,tau_Xs1,tau_Xs2,alpha_K1,beta_K1;
double alpha_a,beta_a,alpha_i,beta_i,alpha_i2,beta_i2,Rto1;
double INa,Ito,ICa,ICaT,ICaNa,ICaK,IKr,IKs,IK1,IKp,IKNa,IKATP,INaCa,INaK,InsNa,InsK,IpCa,INab,ICab,Ist,Ii;
double Jrel,Jup,Jleak,Jtr,Jdiff;
double Phi,gradV;
double tvdotmax_start,tvdotmax_end,CV;
double Iaxfactor;
};
