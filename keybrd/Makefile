include config.mak
CC	=g++ -pthread -g -L$(KULINA)/lib
#CC	=cc -pthread -Dpthred -g
Keybrd	: Keybrd.o kbcheckCallbacks.o Keybrdmain.o  \
	  kbconfig.o kbconfigCallbacks.o \
	  kbsetup.o kbsetupCallbacks.o 
	 $(CC) -o Keybrd Keybrd.o kbcheckCallbacks.o Keybrdmain.o \
	  kbconfig.o kbconfigCallbacks.o \
	  kbsetup.o kbsetupCallbacks.o \
	  -I$(KULINA)/include $(KULINA)/lib/libkulina.a $(KULINA)/lib/libgm.a -L/usr/X11R6/lib -lX11 -lXext -lm -lpthread -lz -lbz2 -lGL
Keybrd.o	: Keybrd.c 
	 $(CC) -c Keybrd.c
kbcheckCallbacks.o	: kbcheckCallbacks.c 
	 $(CC) -c kbcheckCallbacks.c
Keybrdmain.o	: Keybrdmain.c 
	 $(CC) -c Keybrdmain.c
clean	:  
	   rm -f *.o Keybrd
install	: Keybrd
	 cp Keybrd /usr/bin/
