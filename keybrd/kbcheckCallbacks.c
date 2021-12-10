#include <kulina.h>
int keybrd4cleanup(void *Tmp);
int MakekbconfigGroup(DIALOG *D,void *arg);
int kbcheckinit(void *Tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  /* you add any initialisation here */
  int ret = 1;
  DIALOG *D;void *pt;
  D = (DIALOG *)Tmp;
  pt = D->pt;
  return ret;
}
int kbcheckcleanup(void *Tmp) {
  /* you add any cleanup/mem free here */
  /*********************************** 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  int ret = 1;
  DIALOG *D;void *pt;
  D = (DIALOG *)Tmp;
  pt = D->pt;
  return ret;
}
int Modifykbcheck(void *Tmp,int GrpId,void *kpt) {
  DIALOG *D;
  D = (DIALOG *)Tmp;
  DIA *d;
  int i,n;
  int xkb,ykb;
  int ngrp;
  
  KBINFO *ki;
  ki = (KBINFO *)(kpt);
  d = D->d;
  if(d== NULL) fprintf(stderr,"%d %s d== NULL\n",__LINE__,__FILE__);
  i=0;while(d[i].t!= NULL) {;
     i++;
  };
  n=1;
//  ki->kbtype=0;
#if 0
  kgMakeKeybrd5(D,ki->xl,ki->yl,ki->xg,ki->yg,1,ki->btype,ki->font,ki->charclr,
         ki->butclr,ki->fillclr,ki->rfac,ki->trans,ki->Bodr);
#else
  kgKeybrd(D,1,ki);
#endif
  kgGetKeybrdSize(D,&xkb,&ykb);
  D->xl=xkb+1;
  D->yl=ykb+1;
#if 1
  ngrp =  MakekbconfigGroup(D,kpt);
  kgShiftGrp(D,ngrp,xkb-130,ykb-30);
#endif
  
  return GrpId;
}

int kbcheckCallBack(void *Tmp,void *tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
    tmp :  Pointer to KBEVENT  
   ***********************************/ 
  int ret = 0;
  DIALOG *D;
  KBEVENT *kbe;
  KEYBRD *kb;
  D = (DIALOG *)Tmp;
  kbe = (KBEVENT *)tmp;
  kb = (KEYBRD *)D->Kbrd;
  if(kb->Vis == 0) kgLowerWindow(Tmp);
  
  if(kbe->event ==1) {
    if(kbe->button ==1) {
    }
  }
  return ret;
}
int kbcheckResizeCallBack(void *Tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  int ret = 0;
  int xres,yres,dx,dy;
  DIALOG *D;
  D = (DIALOG *)Tmp;
  kgGetWindowSize(D,&xres,&yres);
  dx = xres - D->xl;
  dy = yres - D->yl;
  /* extra code */
  D->xl= xres;
  D->yl= yres;
  kgRedrawDialog(D);
  return ret;
}
int kbcheckWaitCallBack(void *Tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
    Called while waiting for event  
    return value 1 will close the the UI  
   ***********************************/ 
  int ret = 0;
  void *win=NULL;
  DIALOG *D;
  KEYBRD *kb;
  D = (DIALOG *)Tmp;
  if(Tmp == NULL) return 0;
//  fprintf(stderr,"Waiting\n");
//  kgDropFocus(Tmp);
#if 1
  win = kgGetInputFocus(Tmp);
  if(win==NULL) {
      fprintf(stderr,"Win NULL\n");
      return ret;
  }
  kb = (KEYBRD *)D->Kbrd;
  if(kb->TargetWindow==NULL) {kb->TargetWindow=win; return ret;}
  if (kgCheckMyWindow(Tmp,win)== 0)  {
//   fprintf(stderr ,"Not My Window\n");
   kb->TargetWindow = win;
  }
//  else fprintf(stderr,"My Window\n");
#endif
//  kgRaiseWindow(Tmp);
//  kgThreadSleep(0,25000);
  return ret;
}
