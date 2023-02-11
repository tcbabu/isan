#include <kulina.h>
#include <sys/stat.h>
#include <sys/types.h>

char **Fonts=NULL;
//static KBINFO *ki;
#if 0
int kgInitKbinfo(KBINFO *ki) {
  char buff[500];
  FILE *fp;
  KBINFO Ki= {-123132123,-216226216,-49054049,64,44,4,4,0,25,0.300000,0.000000,4,10};
  *ki = Ki;
  sprintf(buff,"%-s/.kulina",getenv("HOME"));
  mkdir(buff,0700);
  strcat(buff,(char *)"/kbconfig");
  fp = fopen(buff,"r");
  if(fp != NULL) {
    fscanf(fp,"%d%d%d%d%d%d%d%d%d%f%f%d%d",
        &(ki->fillclr),&(ki->butclr),&(ki->charclr),
        &(ki->xl),&(ki->yl),&(ki->xg),&(ki->yg),&(ki->btype),&(ki->font),
        &(ki->rfac),&(ki->trans),
        &(ki->kbtype),&(ki->Bodr));
    fclose(fp);
  }
  return 1;
}
#endif
static void *MakeLightImage(int xl,int yl,int r,int g,int b,float fac) {
   void *Img,*Img1;
   float h,s,v,rf,gf,bf,vm;
   DIG *fid;
   fid = (DIG *)kgInitImage(xl,yl,8);
   kgUserFrame(fid,-2.,-2.,(float)xl+2,(float)yl+2);
   kgChangeColor(fid,551,(int)r,(int)g,(int)b);
   kgRoundedRectangleFill(fid,(float)xl*0.5,(float)yl*0.5,
                        (float)xl+2,(float)yl+2,0,551,fac);
   Img = kgGetSharpImage(fid);
   kgCloseImage(fid);
   return Img;
}
int  kbsetupdslide1callback(int val,int i,void *Tmp) {
  /*********************************** 
    val : current value 
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIALOG *D;DID *SD; 
  int ret=1; 
  D = (DIALOG *)Tmp;
  KBINFO *ki;
  ki = (KBINFO *)(D->pt);
  SD = (DID *) kgGetWidget(Tmp,i);
  ki->yl = val;
  return ret;
}
int  kbsetupdslide2callback(int val,int i,void *Tmp) {
  /*********************************** 
    val : current value 
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIALOG *D;DID *SD; 
  int ret=1; 
  D = (DIALOG *)Tmp;
  KBINFO *ki;
  ki = (KBINFO *)(D->pt);
  SD = (DID *) kgGetWidget(Tmp,i);
  ki->xl = val;
  return ret;
}
static int ChangeColor(int *val,DIN *B,int i) {
   int r,g,b,fac,clr;
   BUT_STR *buts;
   buts = (BUT_STR *)B->buts;
   clr = *val;
   clr = -clr;
   b = clr%1000;
   fac = clr/1000;
   g = fac%1000;
   r= fac/1000;
   kgGetColor(NULL,100,200,&r,&g,&b);
   kgChangeButtonColor(B,i,r,g,b);
   clr = r*1000000+g*1000+b;
   *val = -clr;
   buts[i].bkgr = *val;
   buts[i].xpmn = MakeLightImage(B->lngth,B->width,r,g,b,0.15);
   return clr;
}
int  kbsetupbutton1callback(int butno,int i,void *Tmp) {
  /*********************************** 
    butno : selected item (1 to max_item) 
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIALOG *D;DIN *B; 
  int n,ret =0; 
  D = (DIALOG *)Tmp;
  KBINFO *ki;
  ki = (KBINFO *)(D->pt);
  B = (DIN *)kgGetWidget(Tmp,i);
  n = B->nx*B->ny;
  switch(butno) {
    case 1: 
      ChangeColor(&(ki->fillclr),B,0);
      break;
    case 2: 
      ChangeColor(&(ki->butclr),B,1);
      break;
    case 3: 
      ChangeColor(&(ki->charclr),B,2);
      break;
  }
  kgUpdateWidget(B);
  kgUpdateOn(D);
  return ret;
}
void  kbsetupbutton1init(DIN *B,void *pt) {
   BUT_STR *buts;
   int r,g,b;
   int n,i,clr,fac;
   n = B->nx*B->ny;
   buts = (BUT_STR *)B->buts;
   KBINFO *ki;
   ki = (KBINFO *)pt;
   buts[0].bkgr = ki->fillclr;
   buts[1].bkgr = ki->butclr;
   buts[2].bkgr = ki->charclr;

   for(i=0;i<n;i++) {
     
     clr = buts[i].bkgr;
     clr = -clr;
     b = clr%1000;
     fac = clr/1000;
     g = fac%1000;
     r= fac/1000;
     buts[i].xpmn = MakeLightImage(B->lngth,B->width,r,g,b,0.15);
   }

}
int  kbsetupbutton2callback(int butno,int i,void *Tmp) {
  /*********************************** 
    butno : selected item (1 to max_item) 
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIALOG *D;DIN *B; 
  int n,ret =0; 
  int font;
  D = (DIALOG *)Tmp;
  KBINFO *ki;
  ki = (KBINFO *)(D->pt);
  B = (DIN *)kgGetWidget(Tmp,i);
  n = B->nx*B->ny;
  font = kgGetFont(NULL,100,200);
  kgChangeButtonTitle(B,0,Fonts[font]);
  ki->font = font;
  kgUpdateWidget(B);
  switch(butno) {
    case 1: 
      break;
  }
  return ret;
}
void  kbsetupbutton2init(DIN *B,void *pt) {
   int font;
   BUT_STR *buts;
   KBINFO *ki;
   if(Fonts==NULL) Fonts= kgFontNames();
   ki = (KBINFO *)pt;
   buts = (BUT_STR *)B->buts;
   strcpy(buts[0].title,Fonts[ki->font]);
}
int  kbsetupsplbutton1callback(int butno,int i,void *Tmp) {
  /*********************************** 
    butno : selected item (1 to max_item) 
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIALOG *D;DIL *B; 
  int n,ret=1; 
#if 0
  char buff[500];
  sprintf(buff,"cat /proc/%-d/statm",getpid());
  system(buff);
#endif
  D = (DIALOG *)Tmp;
  B = (DIL *) kgGetWidget(Tmp,i);
  n = B->nx;
  switch(butno) {
    case 1: 
      break;
  }
  return ret;
}
void  kbsetupsplbutton1init(DIL *B,void *pt) {
}
int  kbsetupbrowser1callback(int item,int i,void *Tmp) {
  /*********************************** 
    item : selected item (1 to max_item)  not any specific relevence
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIRA *R;DIALOG *D;void *pt; 
  ThumbNail **th; 
  int ret=1; 
  D = (DIALOG *)Tmp;
  KBINFO *ki;
  ki = (KBINFO *)(D->pt);
  pt = D->pt;
  R = (DIRA *)kgGetWidget(Tmp,i);
  th = (ThumbNail **) R->list;
  ki->xg = item -1;
  return ret;
}
void  kbsetupbrowser1init(DIRA *R,void *pt) {
}
int  kbsetupbrowser2callback(int item,int i,void *Tmp) {
  /*********************************** 
    item : selected item (1 to max_item)  not any specific relevence
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIRA *R;DIALOG *D;void *pt; 
  ThumbNail **th; 
  int ret=1; 
  D = (DIALOG *)Tmp;
  KBINFO *ki;
  ki = (KBINFO *)(D->pt);
  pt = D->pt;
  R = (DIRA *)kgGetWidget(Tmp,i);
  th = (ThumbNail **) R->list;
  ki->yg = item -1;
  return ret;
}
void  kbsetupbrowser2init(DIRA *R,void *pt) {
}
int  kbsetupbrowser3callback(int item,int i,void *Tmp) {
  /*********************************** 
    item : selected item (1 to max_item) 
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIALOG *D;DIW *B; 
  int ret=1; 
  D = (DIALOG *)Tmp;
  KBINFO *ki;
  ki = (KBINFO *)(D->pt);
  B = (DIW *) kgGetWidget(Tmp,i);
  ki->rfac = (item -1)*0.05;
  switch(item) {
    case 1: 
      break;
  }
  return ret;
}
int  kbsetupbrowser4callback(int item,int i,void *Tmp) {
  /*********************************** 
    item : selected item (1 to max_item) 
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIALOG *D;DIW *B; 
  int ret=1; 
  D = (DIALOG *)Tmp;
  KBINFO *ki;
  ki = (KBINFO *)(D->pt);
  B = (DIW *) kgGetWidget(Tmp,i);
  ki->trans = (item -1)*0.1;
  switch(item) {
    case 1: 
      break;
  }
  return ret;
}
int  kbsetupbrowser5callback(int item,int i,void *Tmp) {
  /*********************************** 
    item : selected item (1 to max_item)  not any specific relevence
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIRA *R;DIALOG *D;void *pt; 
  ThumbNail **th; 
  int ret=1; 
  D = (DIALOG *)Tmp;
  KBINFO *ki;
  ki = (KBINFO *)(D->pt);
  pt = D->pt;
  R = (DIRA *)kgGetWidget(Tmp,i);
  th = (ThumbNail **) R->list;
  ki->btype = item -1;
  return ret;
}
void  kbsetupbrowser5init(DIRA *R,void *pt) {
}
int kbsetupinit(void *Tmp) {
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
int kbsetupcleanup(void *Tmp) {
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
int Modifykbsetup(void *Tmp,int GrpId) {
  DIALOG *D;
  D = (DIALOG *)Tmp;
  DIA *d;
  int i,n;
  d = D->d;
  i=GrpId;while(d[i].t!= NULL) {;
     i++;
  };
  n=1;
  return GrpId;
}

int kbsetupCallBack(void *Tmp,void *tmp) {
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
int kbsetupResizeCallBack(void *Tmp) {
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
int kbsetupWaitCallBack(void *Tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
    Called while waiting for event  
    return value 1 will close the the UI  
   ***********************************/ 
  int ret = 0;
  return ret;
}
int  kbsetupbrowser6callback(int item,int i,void *Tmp) {
  /*********************************** 
    item : selected item (1 to max_item)  not any specific relevence
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIRA *R;DIALOG *D;void *pt; 
  ThumbNail **th; 
  int ret=1; 
  D = (DIALOG *)Tmp;
  pt = D->pt;
  R = (DIRA *)kgGetWidget(Tmp,i);
  th = (ThumbNail **) R->list;
  return ret;
}
void  kbsetupbrowser6init(DIRA *R,void *pt) {
}
int  kbsetupbrowser7callback(int item,int i,void *Tmp) {
  /*********************************** 
    item : selected item (1 to max_item)  not any specific relevence
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIRA *R;DIALOG *D;void *pt; 
  ThumbNail **th; 
  int ret=1; 
  D = (DIALOG *)Tmp;
  pt = D->pt;
  R = (DIRA *)kgGetWidget(Tmp,i);
  th = (ThumbNail **) R->list;
  return ret;
}
void  kbsetupbrowser7init(DIRA *R,void *pt) {
}
int  kbsetupdslide3callback(int val,int i,void *Tmp) {
  /*********************************** 
    val : current value 
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIALOG *D;DID *SD; 
  int ret=1; 
  D = (DIALOG *)Tmp;
  SD = (DID *) kgGetWidget(Tmp,i);
  return ret;
}
