#include <kulina.h>
#include "kbsetupCallbacks.h"
void ModifykbsetupGc(Gclr *gc) {
#if 0
/*
//  You may change default settings here 
//  probably you can allow the user to create a config in $HOME
//  and try to read that file (if exits); so dynamic configuration is possible
   gc->FontSize =8;
   gc->Font=23;
   int char_clr;     /* character colour */
  int fill_clr;     /* fill colour */
  int bodr_clr;     /* border colour */
  int  cur_clr;     /* cursor colour for text box*/
  int high_clr;     /* menu item high light colour */
  int char_hclr;    /* high light colour for character in menu item*/
  int msg_char;     /* character colour for message */
  int msg_fill;     /* fill colour for message */
  int msg_bodr;     /* border colour for message */
  int txt_fill;     /* fill colour for text entry box */
  int txt_char;     /* character colour for text entry box */
  int txt_pchar;    /* colour for text entry box prompt */
  int tabl_fill;    /* colour for table box fill */
  int tabl_line;    /* colour for table box lines */
  int tabl_char;    /* colour for table box characters */
  int tabl_hchar;   /* colour for table box characters(output only) */
  int v_dim;        /* very dim colour */
  int dim;          /* dim colour for 3d effect*/
  int bright;       /* bright colourfor 3d effect */
  int vbright;      /* colour for key board attention */
  int twin_fill;    /* fill colour for text window */
  int twin_char;    /* character colour for text window */
  int twin_bodr ;   /* border colour for text window */
  int info_fill;    /* fill colour for info box */
  int info_char;    /* character colour for info box */
  int but_char;     /* character colour for button title */
  int menu_char;    /* Color for menu item */
  int c_bound;
  int GuiFontSize;
  int MenuFont;
  int PromptFont;
  int ButtonFont;
  int MsgFont;
  int Font;   //internal use
  int FontSize;   //internal use
  int SplashFont;
  int SplashFillColor;
  int SplashBodrColor;
  int SplashCharColor;
  int ProgFillColor;
  int ProgBodrColor;
  int ProgColor;
  int ItemHighColor;
*/

#endif


   gc->Font=25;
   gc->FontSize =10;
   gc->msg_char = 24;
   gc->MenuFont = 24;
}

int kbsetupGroup( DIALOG *D,void **v,void *pt) {
  int GrpId=0,oitems=0,i,j;
  DIA *d=NULL,*dtmp;
  DID d0 = { 
    'd',
    271,6,  
    402,52,   
    20,100,  
    81,  
    (int *)v[0],
    NULL,
    NULL,kbsetupdslide1callback /* *args, callback */
  };
  strcpy(d0.Wid,(char *)"Height");
  d0.item = -1;
  DID d1 = { 
    'd',
    139,6,  
    270,52,   
    20,100,  
    81,  
    (int *)v[1],
    NULL,
    NULL,kbsetupdslide2callback /* *args, callback */
  };
  strcpy(d1.Wid,(char *)"Length");
  d1.item = -1;
  DIM m2 = { 
    'm',
    38,26,  
    138,50,  
    1,0  
  };
  strncpy(m2.msg,(char *)"Key length",499);
  strcpy(m2.Wid,(char *)"kbsetupWidget5");
  m2.item = -1;
  DIM m3 = { 
    'm',
    403,26,  
    469,50,  
    1,0  
  };
  strncpy(m3.msg,(char *)"Key height",499);
  strcpy(m3.Wid,(char *)"kbsetupWidget6");
  m3.item = -1;
  BUT_STR  *butn4=NULL; 
  butn4= (BUT_STR *)malloc(sizeof(BUT_STR)*3);
  butn4[0].sw=1;
  strcpy(butn4[0].title,(char *)"Background");
  butn4[0].xpmn=NULL;
  butn4[0].xpmp=NULL;
  butn4[0].xpmh=NULL;
  butn4[0].bkgr=-235255250;
  butn4[0].butncode='';
  butn4[1].sw=1;
  strcpy(butn4[1].title,(char *)"Key Color");
  butn4[1].xpmn=NULL;
  butn4[1].xpmp=NULL;
  butn4[1].xpmh=NULL;
  butn4[1].bkgr=-98098098;
  butn4[1].butncode='';
  butn4[2].sw=1;
  strcpy(butn4[2].title,(char *)"Text Color");
  butn4[2].xpmn=NULL;
  butn4[2].xpmp=NULL;
  butn4[2].xpmh=NULL;
  butn4[2].bkgr=-216216216;
  butn4[2].butncode='';
  DIN b4 = { 
    'n',
    10,128,  
    270,220,
    20,20,  
    64, 
    64, 
    3,1, 
    0,0.150000,0,0,0,1, /* button type and roundinfg factor(0-0.5),bordr,hide ,nodrawbkgr*/
 
    butn4, 
    kbsetupbutton1callback, /*  Callbak */
      NULL  /* any args */
  };
  strcpy(b4.Wid,(char *)"Colors");
  b4.item = -1;
  BUT_STR  *butn5=NULL; 
  butn5= (BUT_STR *)malloc(sizeof(BUT_STR)*1);
  butn5[0].sw=1;
  strcpy(butn5[0].title,(char *)"Select Font");
  butn5[0].xpmn=NULL;
  butn5[0].xpmp=NULL;
  butn5[0].xpmh=NULL;
  butn5[0].bkgr=-235255250;
  butn5[0].butncode='';
  DIN b5 = { 
    'n',
    329,189,  
    539,219,
    2,2,  
    200, 
    20, 
    1,1, 
    9,0.150000,1,0,0,1, /* button type and roundinfg factor(0-0.5),bordr,hide ,nodrawbkgr*/
 
    butn5, 
    kbsetupbutton2callback, /*  Callbak */
      NULL  /* any args */
  };
  strcpy(b5.Wid,(char *)"Font");
  b5.item = -1;
  BUT_STR  *butn6=NULL; 
  butn6= (BUT_STR *)malloc(sizeof(BUT_STR)*1);
  butn6[0].sw=1;
  strcpy(butn6[0].title,(char *)"Okay");
  butn6[0].xpmn=NULL;
  butn6[0].xpmp=NULL;
  butn6[0].xpmh=NULL;
  butn6[0].bkgr=-235255250;
  butn6[0].butncode='';
  DIL h6 = { 
    'h',
    240,405,  
    317,434,
    2,0,  
    72, 
    25, 
    1,1, 
    4,0.500000,0,0,0,1, /* button type and roundinfg factor(0-0.5),bordr,hide ,nodrawbkgr*/
 
    butn6, 
    kbsetupsplbutton1callback, /*  Callbak */
      NULL  /* any args */
  };
  strcpy(h6.Wid,(char *)"kbsetupWidget13");
  h6.item = -1;
  char *menu7[]  = { 
    (char *)"0",
    (char *)"1",
    (char *)"2",
    (char *)"3",
    (char *)"4",
    (char *)"5",
    (char *)"6",
    (char *)"7",
    (char *)"8",
    NULL 
  };
  ThumbNail **th0 ;
  DIRA r7 = { 
    'r',
    64,55,  
    269,128,   
    8,0,  
    45, 
    22, 
    1,9, 
    -2302756,3, 
    (int *)v[2], 
    NULL, 
    NULL ,
    NULL,kbsetupbrowser1callback, /* *args, callback */
    0,  /* Border Offset  */
     2,  /* Scroll width  */
     0,  /* Type  */
     0, /* item highlight */
    1, /* bordr */
    0, /* bkgr */
    0  /* =1 hide  */
   };
  th0 = (ThumbNail **)kgStringToThumbNails((char **)menu7);
  r7.list=(void **)th0;
  strcpy(r7.Wid,(char *)"Xgap");
  r7.item = -1;
  DIM m8 = { 
    'm',
    1,77,  
    63,101,  
    1,0  
  };
  strncpy(m8.msg,(char *)"Hori gap",499);
  strcpy(m8.Wid,(char *)"kbsetupWidget16");
  m8.item = -1;
  char *menu9[]  = { 
    (char *)"0",
    (char *)"1",
    (char *)"2",
    (char *)"3",
    (char *)"4",
    (char *)"5",
    (char *)"6",
    (char *)"7",
    (char *)"8",
    NULL 
  };
  ThumbNail **th1 ;
  DIRA r9 = { 
    'r',
    333,55,  
    539,128,   
    8,0,  
    45, 
    22, 
    1,9, 
    -2302756,3, 
    (int *)v[3], 
    NULL, 
    NULL ,
    NULL,kbsetupbrowser2callback, /* *args, callback */
    0,  /* Border Offset  */
     2,  /* Scroll width  */
     0,  /* Type  */
     0, /* item highlight */
    1, /* bordr */
    0, /* bkgr */
    0  /* =1 hide  */
   };
  th1 = (ThumbNail **)kgStringToThumbNails((char **)menu9);
  r9.list=(void **)th1;
  strcpy(r9.Wid,(char *)"Ygap");
  r9.item = -1;
  DIM m10 = { 
    'm',
    271,79,  
    332,103,  
    1,0  
  };
  strncpy(m10.msg,(char *)"Vert gap",499);
  strcpy(m10.Wid,(char *)"kbsetupWidget16");
  m10.item = -1;
  char **menu11 ; 
  menu11= (char **)malloc(sizeof(char *)*12);
  menu11[11]=NULL;
  menu11[0]=(char *)malloc(4);
  strcpy(menu11[0],(char *)"0.0");
  menu11[1]=(char *)malloc(5);
  strcpy(menu11[1],(char *)"0.05");
  menu11[2]=(char *)malloc(5);
  strcpy(menu11[2],(char *)"0.10");
  menu11[3]=(char *)malloc(5);
  strcpy(menu11[3],(char *)"0.15");
  menu11[4]=(char *)malloc(5);
  strcpy(menu11[4],(char *)"0.20");
  menu11[5]=(char *)malloc(5);
  strcpy(menu11[5],(char *)"0.25");
  menu11[6]=(char *)malloc(5);
  strcpy(menu11[6],(char *)"0.30");
  menu11[7]=(char *)malloc(5);
  strcpy(menu11[7],(char *)"0.35");
  menu11[8]=(char *)malloc(5);
  strcpy(menu11[8],(char *)"0.40");
  menu11[9]=(char *)malloc(5);
  strcpy(menu11[9],(char *)"0.45");
  menu11[10]=(char *)malloc(5);
  strcpy(menu11[10],(char *)"0.50");
  char *prompt11 ; 
  prompt11=(char *)malloc(20);
  strcpy(prompt11,(char *)"Key rounding factor");
  DIW w11 = { 
    'w',
    274,131,  
    539,160,   
    6,  
    (int *)v[4],
    prompt11 ,
    menu11 ,
    NULL,kbsetupbrowser3callback, /* *args, callback */
    0 
  };
  strcpy(w11.Wid,(char *)"kbsetupWidget17");
  w11.item = -1;
  char **menu12 ; 
  menu12= (char **)malloc(sizeof(char *)*12);
  menu12[11]=NULL;
  menu12[0]=(char *)malloc(4);
  strcpy(menu12[0],(char *)"0.0");
  menu12[1]=(char *)malloc(4);
  strcpy(menu12[1],(char *)"0.1");
  menu12[2]=(char *)malloc(4);
  strcpy(menu12[2],(char *)"0.2");
  menu12[3]=(char *)malloc(4);
  strcpy(menu12[3],(char *)"0.3");
  menu12[4]=(char *)malloc(4);
  strcpy(menu12[4],(char *)"0.4");
  menu12[5]=(char *)malloc(4);
  strcpy(menu12[5],(char *)"0.5");
  menu12[6]=(char *)malloc(4);
  strcpy(menu12[6],(char *)"0.6");
  menu12[7]=(char *)malloc(4);
  strcpy(menu12[7],(char *)"0.7");
  menu12[8]=(char *)malloc(4);
  strcpy(menu12[8],(char *)"0.8");
  menu12[9]=(char *)malloc(4);
  strcpy(menu12[9],(char *)"0.9");
  menu12[10]=(char *)malloc(4);
  strcpy(menu12[10],(char *)"1.0");
  char *prompt12 ; 
  prompt12=(char *)malloc(13);
  strcpy(prompt12,(char *)"Transparency");
  DIW w12 = { 
    'w',
    337,160,  
    539,189,   
    6,  
    (int *)v[5],
    prompt12 ,
    menu12 ,
    NULL,kbsetupbrowser4callback, /* *args, callback */
    0 
  };
  strcpy(w12.Wid,(char *)"kbsetupWidget18");
  w12.item = -1;
  char *menu13[]  = { 
    (char *)"0",
    (char *)"1",
    (char *)"2",
    (char *)"3",
    (char *)"4",
    (char *)"5",
    (char *)"6",
    (char *)"7",
    (char *)"8",
    NULL 
  };
  ThumbNail **th2 ;
  DIRA r13 = { 
    'r',
    34,256,  
    229,349,   
    8,0,  
    45, 
    25, 
    1,9, 
    -2302756,3, 
    (int *)v[6], 
    NULL, 
    NULL ,
    NULL,kbsetupbrowser5callback, /* *args, callback */
    6,  /* Border Offset  */
     2,  /* Scroll width  */
     0,  /* Type  */
     0, /* item highlight */
    1, /* bordr */
    0, /* bkgr */
    0  /* =1 hide  */
   };
  th2 = (ThumbNail **)kgStringToThumbNails((char **)menu13);
  r13.list=(void **)th2;
  strcpy(r13.Wid,(char *)"kbsetupWidget14");
  r13.item = -1;
  DIM m14 = { 
    'm',
    95,235,  
    165,260,  
    1,0  
  };
  strncpy(m14.msg,(char *)"Key type",499);
  strcpy(m14.Wid,(char *)"kbsetupWidget15");
  m14.item = -1;
  DIM m15 = { 
    'm',
    259,235,  
    359,259,  
    0,0  
  };
  strncpy(m15.msg,(char *)"Keyborad Type",499);
  strcpy(m15.Wid,(char *)"kbsetupWidget16");
  m15.item = -1;
  char *menu16[]  = { 
    (char *)"type 1",
    (char *)"type 2",
    (char *)"type 3",
    NULL 
  };
  ThumbNail **th3 ;
  DIRA r16 = { 
    'r',
    261,256,  
    356,348,   
    8,0,  
    53, 
    25, 
    1,3, 
    -2302756,3, 
    (int *)v[7], 
    NULL, 
    NULL ,
    NULL,kbsetupbrowser6callback, /* *args, callback */
    6,  /* Border Offset  */
     22,  /* Scroll width  */
     0,  /* Type  */
     0, /* item highlight */
    1, /* bordr */
    0, /* bkgr */
    0  /* =1 hide  */
   };
  th3 = (ThumbNail **)kgStringToThumbNails((char **)menu16);
  r16.list=(void **)th3;
  strcpy(r16.Wid,(char *)"kbsetupWidget23");
  r16.item = -1;
  char *menu17[]  = { 
    (char *)"0.00",
    (char *)"0.05",
    (char *)"0.10",
    NULL 
  };
  ThumbNail **th4 ;
  DIRA r17 = { 
    'r',
    385,255,  
    515,349,   
    8,0,  
    90, 
    25, 
    1,3, 
    -2302756,3, 
    (int *)v[8], 
    NULL, 
    NULL ,
    NULL,kbsetupbrowser7callback, /* *args, callback */
    6,  /* Border Offset  */
     22,  /* Scroll width  */
     0,  /* Type  */
     0, /* item highlight */
    1, /* bordr */
    0, /* bkgr */
    0  /* =1 hide  */
   };
  th4 = (ThumbNail **)kgStringToThumbNails((char **)menu17);
  r17.list=(void **)th4;
  strcpy(r17.Wid,(char *)"kbsetupWidget24");
  r17.item = -1;
  DIM m18 = { 
    'm',
    381,234,  
    519,258,  
    0,0  
  };
  strncpy(m18.msg,(char *)"Background Rounding",499);
  strcpy(m18.Wid,(char *)"kbsetupWidget25");
  m18.item = -1;
  DID d19 = { 
    'd',
    233,354,  
    328,401,   
    10,60,  
    50,  
    (int *)v[9],
    NULL,
    NULL,kbsetupdslide3callback /* *args, callback */
  };
  strcpy(d19.Wid,(char *)"Bordrbar");
  d19.item = -1;
  DIM m20 = { 
    'm',
    88,373,  
    239,396,  
    1,0  
  };
  strncpy(m20.msg,(char *)"Keybord border size",499);
  strcpy(m20.Wid,(char *)"kbsetupWidget21");
  m20.item = -1;
  dtmp = D->d;
  i=0;
  if(dtmp!= NULL) while(dtmp[i].t!=NULL)i++;
  dtmp = (DIA *)realloc(dtmp,sizeof(DIA )*(i+22));
  d =dtmp+i; 
  d[21].t=NULL;
  d[0].t = (DIT *)malloc(sizeof(DID));
  *d[0].d = d0;
  d[0].d->item = -1;
  d[1].t = (DIT *)malloc(sizeof(DID));
  *d[1].d = d1;
  d[1].d->item = -1;
  d[2].t = (DIT *)malloc(sizeof(DIM));
  *d[2].m = m2;
  d[2].m->item = -1;
  d[3].t = (DIT *)malloc(sizeof(DIM));
  *d[3].m = m3;
  d[3].m->item = -1;
  d[4].t = (DIT *)malloc(sizeof(DIN));
  *d[4].N = b4;
  d[4].N->item = -1;
  kbsetupbutton1init(d[4].N,pt) ;
  d[5].t = (DIT *)malloc(sizeof(DIN));
  *d[5].N = b5;
  d[5].N->item = -1;
  kbsetupbutton2init(d[5].N,pt) ;
  d[6].t = (DIT *)malloc(sizeof(DIL));
  *d[6].h = h6;
  d[6].h->item = -1;
  kbsetupsplbutton1init(d[6].h,pt) ;
  d[7].t = (DIT *)malloc(sizeof(DIRA));
  *d[7].r = r7;
  d[7].r->item = -1;
  kbsetupbrowser1init(d[7].r,pt) ;
  d[8].t = (DIT *)malloc(sizeof(DIM));
  *d[8].m = m8;
  d[8].m->item = -1;
  d[9].t = (DIT *)malloc(sizeof(DIRA));
  *d[9].r = r9;
  d[9].r->item = -1;
  kbsetupbrowser2init(d[9].r,pt) ;
  d[10].t = (DIT *)malloc(sizeof(DIM));
  *d[10].m = m10;
  d[10].m->item = -1;
  d[11].t = (DIT *)malloc(sizeof(DIW));
  *d[11].w = w11;
  d[11].w->item = -1;
  d[12].t = (DIT *)malloc(sizeof(DIW));
  *d[12].w = w12;
  d[12].w->item = -1;
  d[13].t = (DIT *)malloc(sizeof(DIRA));
  *d[13].r = r13;
  d[13].r->item = -1;
  kbsetupbrowser5init(d[13].r,pt) ;
  d[14].t = (DIT *)malloc(sizeof(DIM));
  *d[14].m = m14;
  d[14].m->item = -1;
  d[15].t = (DIT *)malloc(sizeof(DIM));
  *d[15].m = m15;
  d[15].m->item = -1;
  d[16].t = (DIT *)malloc(sizeof(DIRA));
  *d[16].r = r16;
  d[16].r->item = -1;
  kbsetupbrowser6init(d[16].r,pt) ;
  d[17].t = (DIT *)malloc(sizeof(DIRA));
  *d[17].r = r17;
  d[17].r->item = -1;
  kbsetupbrowser7init(d[17].r,pt) ;
  d[18].t = (DIT *)malloc(sizeof(DIM));
  *d[18].m = m18;
  d[18].m->item = -1;
  d[19].t = (DIT *)malloc(sizeof(DID));
  *d[19].d = d19;
  d[19].d->item = -1;
  d[20].t = (DIT *)malloc(sizeof(DIM));
  *d[20].m = m20;
  d[20].m->item = -1;
  d[21].t = NULL;
  GrpId=kgOpenGrp(D);
  D->d = dtmp;
  j=0;
  while(d[j].t!=NULL){ kgAddtoGrp(D,GrpId,(void *)(d[j].t));j++;}
  return GrpId;
} 

/* One can also use the following code to add Widgets to an existing Dialog */

int MakekbsetupGroup(DIALOG *D,void *arg) {
   int GrpId;
   WIDGETGRP *Gpt;
/*************************************************

    Integerslidebar1  1 data value
    Integerslidebar2  1 data value
    RadioButtons1  1 data value
    RadioButtons2  1 data value
    Browser3  1 data value
    Browser4  1 data value
    RadioButtons5  1 data value
    RadioButtons6  1 data value
    RadioButtons7  1 data value
    Integerslidebar3  1 data value

*************************************************/
   int  *v0 ;
   v0 = (int *)malloc(sizeof(int));
   *v0 = 1;
   int  *v1 ;
   v1 = (int *)malloc(sizeof(int));
   *v1 = 1;
   int  *v2 ;
   v2 = (int *)malloc(sizeof(int));
   *v2 = 1;
   int  *v3 ;
   v3 = (int *)malloc(sizeof(int));
   *v3 = 1;
   int  *v4 ;
   v4 = (int *)malloc(sizeof(int));
   *v4 = 1;
   int  *v5 ;
   v5 = (int *)malloc(sizeof(int));
   *v5 = 1;
   int  *v6 ;
   v6 = (int *)malloc(sizeof(int));
   *v6 = 1;
   int  *v7 ;
   v7 = (int *)malloc(sizeof(int));
   *v7 = 1;
   int  *v8 ;
   v8 = (int *)malloc(sizeof(int));
   *v8 = 1;
   int  *v9 ;
   v9 = (int *)malloc(sizeof(int));
   *v9 = 1;
   void** v=(void **)malloc(sizeof(void*)*11);
   v[10]=NULL;
   v[0]=(void *)(v0);
   v[1]=(void *)(v1);
   v[2]=(void *)(v2);
   v[3]=(void *)(v3);
   v[4]=(void *)(v4);
   v[5]=(void *)(v5);
   v[6]=(void *)(v6);
   v[7]=(void *)(v7);
   v[8]=(void *)(v8);
   v[9]=(void *)(v9);
   void *pt=NULL; /* pointer to send any extra information */
   GrpId = kbsetupGroup(D,v,pt);
   Gpt = kgGetWidgetGrp(D,GrpId);
   Gpt->arg= v; // kulina will double free this; you may modify
   return GrpId;
}

int kbsetup( void *parent,void **v,void *pt) {
  int ret=1,GrpId,k;
  DIALOG D;
  DIA *d=NULL;
  D.VerId=2107030000;
  kgInitUi(&D);
  D.d=NULL;
#if 1
  GrpId = kbsetupGroup(&D,v,pt);
#else 
  GrpId = MakekbsetupGroup(&D,pt); // can try this also
#endif 
  d = D.d;
  D.d = d;
  D.bkup = 1; /* set to 1 for backup */
  D.bor_type = 1;
  D.df = 19;
  D.tw = 4;
  D.bw = 4;
  D.lw = 4;
  D.rw = 4;
  D.xo = 0;   /* Position of Dialog */ 
  D.yo = 0;
  D.xl = 560;    /*  Length of Dialog */
  D.yl = 438;    /*  Width  of Dialog */
  D.Initfun = kbsetupinit;    /*   init fuction for Dialog */
  D.Cleanupfun = kbsetupcleanup;    /*   init fuction for Dialog */
  D.kbattn = 0;    /*  1 for drawing keyborad attention */
  D.butattn = 0;    /*  1 for drawing button attention */
  D.fullscreen = 0;    /*  1 for for fullscreen mode */
  D.Deco = 1;    /*  1 for Window Decorration */
  D.transparency = 0.000000;    /*  float 1.0 for full transparency */
  D.Newwin = 0;    /*  1 for new window not yet implemented */
  D.DrawBkgr = 1;    /*  1 for drawing background */
  D.Bkpixmap = NULL;    /*  background image */
  D.Sticky = 0;    /*  1 for stickyness */
  D.Resize = 0;    /*  1 for Resize option */
  D.MinWidth = 100;    /*   for Resize option */
  D.MinHeight = 100;    /*   for Resize option */
#if 1 
  D.Callback = kbsetupCallBack;    /*  default callback */
#else 
  D.Callback = NULL;    
#endif
  D.ResizeCallback = kbsetupResizeCallBack;  /*  Resize callback */
#if 0 
  D.WaitCallback = NULL;  /*  Wait callback */
#else 
  D.WaitCallback = kbsetupWaitCallBack;  /*  Wait callback */
#endif
  D.Fixpos = 1;    /*  1 for Fixing Position */
  D.NoTaskBar = 0;    /*  1 for not showing in task bar*/
  D.NoWinMngr = 0;    /*  1 for no Window Manager*/
  D.StackPos = 0;    /* -1,0,1 for for Stack Position -1:below 0:normal 1:above*/
  D.Shapexpm = NULL;    /*  PNG/jpeg file for window shape;Black color will not be drawn */
  D.parent = parent;    /*  1 for not showing in task bar*/
  D.pt = pt;    /*  any data to be passed by user*/
//  strcpy(D.name,"Kulina Designer ver 1.0");    /*  Dialog name you may change */
  if(D.fullscreen!=1) {    /*  if not fullscreen mode */
     int xres,yres; 
     kgDisplaySize(&xres,&yres); 
      // D.xo=D.yo=0; D.xl = xres-10; D.yl=yres-80;
  }
  else {    // for fullscreen
     int xres,yres; 
     kgDisplaySize(&xres,&yres); 
     D.xo=D.yo=0; D.xl = xres; D.yl=yres;
//     D.StackPos = 1; // you may need it
  }    /*  end of fullscreen mode */
//  kgColorTheme(&D,210,210,210);    /*  set colors for gui*/
//  ModifykbsetupGc(&(D.gc));    /*  set colors for gui*/
  Modifykbsetup(&D,GrpId);    /*  add extras to  gui*/
  ret= kgUi(&D);
  kgCleanUi(&D);
  return ret;
}
void *Runkbsetup(void *arg) {
/*************************************************

    Integerslidebar1  1 data value
    Integerslidebar2  1 data value
    RadioButtons1  1 data value
    RadioButtons2  1 data value
    Browser3  1 data value
    Browser4  1 data value
    RadioButtons5  1 data value
    RadioButtons6  1 data value
    RadioButtons7  1 data value
    Integerslidebar3  1 data value

*************************************************/
   int   v0 = 1;
   int   v1 = 1;
   int   v2 = 1;
   int   v3 = 1;
   int   v4 = 1;
   int   v5 = 1;
   int   v6 = 1;
   int   v7 = 1;
   int   v8 = 1;
   int   v9 = 1;
   void* v[10];
   v[0]=(void *)(&v0);
   v[1]=(void *)(&v1);
   v[2]=(void *)(&v2);
   v[3]=(void *)(&v3);
   v[4]=(void *)(&v4);
   v[5]=(void *)(&v5);
   v[6]=(void *)(&v6);
   v[7]=(void *)(&v7);
   v[8]=(void *)(&v8);
   v[9]=(void *)(&v9);
   KBINFO *ki;
   ki = (KBINFO *) arg;
   v2 = ki->xg+1;
   v3 = ki->yg+1;
   v6 = ki->btype+1;
   v1 = ki->xl;
   v0 = ki->yl;
   v2 = (ki->xg);
   v3 = (ki->yg);
   v2 = (v2%9)+1;
   v3 = (v3%9)+1;
   v4 = (int)(ki->rfac*100+0.1);
   v4 = v4%51;
   v4 = v4/5 +1;
   ki->rfac = (v4-1)*0.05;
   v5 = (int)(ki->trans*10+0.1);
   v5 %=11;
   v5 = v5 +1;
   ki->trans = (v5-1)*0.1;
   v6 = ki->btype;
   v6 = v6%9;
   ki->btype =v6;
   v6 +=1;
   v7 = 1;
   if(ki->kbtype == 0) v7=3;
   if(ki->kbtype == 4) v7=2;
//   v4 = (ki->rfac+0.001)/0.05+1;
//   v5 = (ki->trans+0.001)/0.1+1;
   v8 = (ki->Brfac+0.001)/0.05+1;
   if(v8> 3) v8 =3;
   v9=10;
   v9 = ki->Bodr;
   if(v9 <10) v9=10;
   if(v9>60) v9=60;
   void *pt=NULL; /* pointer to send any extra information */
   kbsetup(NULL,v,arg );
   switch(v7) {
     case 1:
       ki->kbtype= 5;
       break;
     case 2:
       ki->kbtype=4;
       break;
     case 3:
       ki->kbtype=0;
       break;
   }
   ki->Brfac = (v8-1)*0.05;
   ki->Bodr = v9;
   return NULL;
}
