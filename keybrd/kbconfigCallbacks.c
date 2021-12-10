#include <kulina.h>
//static   KBINFO *ki;
void *Xpmn1=NULL,*Xpmn2=NULL,*Xpmn3=NULL,*Xpmp3=NULL,*Xpmh4=NULL;
void *Runkbsetup(void *arg);
int kgInitKbinfo(KBINFO *ki);
int  kbconfigsplbutton1callback(int butno,int i,void *Tmp) {
  /*********************************** 
    butno : selected item (1 to max_item) 
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIALOG *D;DIL *B; 
  int n,ret=1; 
  KBINFO *ki;
  KEYBRD *kb;
  static int xo=-1001,yo=-1001,xl,yl;
  static int xres,yres;
  void *img,*oimg;
  char buff[300];
  D = (DIALOG *)Tmp;
  ki = (KBINFO *)(D->pt);
  kb = (KEYBRD *)D->Kbrd;
  B = (DIL *) kgGetWidget(Tmp,i);
  BUT_STR *buts;
  buts = (BUT_STR *)B->buts;
  n = B->nx;
  if((xo == -1001) ||(yo ==-1001)) {
    xo = D->xo;
    yo = D->yo;
    xl = D->xl;
    yl = D->yl;
    kgDisplaySize(&xres,&yres);
    xo = (xres - xl)/2;
    yo = (yres - (yl+2));
  }
  switch(butno) {
    case 1: 
      Runkbsetup(ki);
      xo = -1001;
      yo = -1001;
      break;
    case 2: 
      sprintf(buff,"cat /proc/%-d/statm",getpid());
      system(buff);
      ret =2;
      break;
    default:
      ret =0;
      if(kb->Vis) {
         kgChangeButtonNormalImage(B,2,Xpmp3);
         kgUpdateWidget(B);
         kgHideKeybrd(Tmp);
//         kgMoveWindow(D,-xl+120,yres-yl-2-100);
         kgMoveWindow(D,xres-xl,yres-yl-2-100);
//         kgRedrawDialog(D);
         kgLowerWindow(Tmp);
         
      }
      else {
        kgMoveWindow(D,xo,yo);
        kgChangeButtonNormalImage(B,2,Xpmn3);
        kgUpdateWidget(B);
        kgShowKeybrd(Tmp);
        kgRaiseWindow(Tmp);
      }
      break;
  }
#if 0
  char buff[500];
  sprintf(buff,"cat /proc/%-d/statm",getpid());
  system(buff);
#endif
  return ret;
}
void  kbconfigsplbutton1init(DIL *B,void *pt) {
   KBINFO *ki;
   ki = (KBINFO *)pt;
   BUT_STR *butn0;
   butn0 = (BUT_STR *)B->buts;
#if 1
  Xpmn1 = kgRedoImage(12,30,235,185);
  butn0[0].xpmn= (char *)Xpmn1;
#endif
#if 1
  Xpmn2 = kgPowerdownImage(16,130,65,30);
  butn0[1].xpmn= (char *)Xpmn2;
#endif
#if 1
  Xpmn3 = kgDowndirImage(12,130,165,30);
  Xpmp3 = kgUpdirImage(12,130,165,30);
  butn0[2].xpmn= (char *)Xpmn3;
  butn0[2].xpmp=NULL;
  butn0[2].xpmh= NULL;
  butn0[2].bkgr = -210220215;
#endif
}
int kbconfiginit(void *Tmp) {
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
int kbconfigcleanup(void *Tmp) {
  /* you add any cleanup/mem free here */
  /*********************************** 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  int ret = 1;
  DIALOG *D;void *pt;
  D = (DIALOG *)Tmp;
  pt = D->pt;
//  fprintf(stderr,"Kbconfig Cleanup\n");
  kgFreeImage(Xpmn1);
  kgFreeImage(Xpmn2);
  kgFreeImage(Xpmn3);
  kgFreeImage(Xpmp3);
  Xpmn1=NULL;
  Xpmn2=NULL;
  Xpmn3=NULL;
  Xpmp3=NULL;
  return ret;
}
int Modifykbconfig(void *Tmp,int GrpId) {
  DIALOG *D;
  D = (DIALOG *)Tmp;
  DIA *d;
  int i,n;
  d = D->d;
  i=0;while(d[i].t!= NULL) {;
     i++;
  };
  n=1;
  return GrpId;
}

int kbconfigCallBack(void *Tmp,void *tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
    tmp :  Pointer to KBEVENT  
   ***********************************/ 
  int ret = 0;
  DIALOG *D;
  KBEVENT *kbe;
  D = (DIALOG *)Tmp;
  kbe = (KBEVENT *)tmp;
  if(kbe->event ==1) {
    if(kbe->button ==1) {
    }
  }
  return ret;
}
int kbconfigResizeCallBack(void *Tmp) {
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
int kbconfigWaitCallBack(void *Tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
    Called while waiting for event  
    return value 1 will close the the UI  
   ***********************************/ 
  int ret = 0;
  return ret;
}
