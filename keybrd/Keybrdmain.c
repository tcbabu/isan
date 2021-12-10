#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <kulina.h>
//int kgInitKbinfo(KBINFO *ki);
void *Runkbcheck(void *);

int main(void) {
  FILE *fp;
  char buff[500];
  char buff1[500];
  KBINFO ki= {2,3,4,45,45,2,2,1,16,0.2,0.1,4,10,0.0};
  kgInitKbinfo(&ki);
  sprintf(buff,"%-s/.kulina",getenv("HOME"));
  mkdir(buff,0700);
  strcat(buff,(char *)"/kbconfig");
  fp = fopen(buff,"r");
  printf("BUFF= %s\n",buff);
  if(fp != NULL) {
    fscanf(fp,"%d%d%d%d%d%d%d%d%d%f%f%d%d%f",
        &(ki.fillclr),&(ki.butclr),&(ki.charclr),
        &(ki.xl),&(ki.yl),&(ki.xg),&(ki.yg),&(ki.btype),&(ki.font),
        &(ki.rfac),&(ki.trans),
        &(ki.kbtype),&(ki.Bodr),&(ki.Brfac));
    fclose(fp);
  }
  sprintf(buff1,"cat /proc/%-d/statm",getpid());
  while (1) {
//   system(buff1);
   if(Runkbcheck(&ki)==NULL) {
    break;
//     continue;
   }
    fp= fopen(buff,"w");
    fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%f\n%f\n%d\n%d\n%f\n",
        (ki.fillclr),(ki.butclr),(ki.charclr),
        (ki.xl),(ki.yl),(ki.xg),(ki.yg),(ki.btype),(ki.font),
        (ki.rfac),(ki.trans),
        (ki.kbtype),(ki.Bodr),(ki.Brfac));
    fprintf(fp,"  KBINFO Ki= {%d,%d,%d,%d,%d,%d,%d,%d,%d,%f,%f,%d,%d,%f};\n",
         ki.fillclr,ki.butclr,ki.charclr,ki.xl,ki.yl,ki.xg,ki.yg,
         ki.btype,ki.font,ki.rfac,ki.trans,ki.kbtype,ki.Bodr,ki.Brfac);
    fclose(fp);
  }
  return 1;
}
