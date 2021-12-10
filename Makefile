# lina Makefile
#
#
# This file is part of lina
#
###### variable declarations #######

# local fallbacks for missing operating system features
SHELL	:= /bin/bash
PREFIX=/usr
export CFLAGS=-I$(PWD)/include
export LDFLAGS=-L$(PWD)/lib
X11_CFLAGS	="-I$(PWD)/include $(shell pkg-config --cflags x11)"
X11_LIBS 	="$(shell pkg-config --libs x11)"
PKG_CONFIG_PATH_OLD	:=$(PKG_CONFIG_PATH)
PKG_CONFIG_PATH	:=$(PWD)/lib/pkgconfig:/usr/X11R76/lib/pkgconfig
PATH_OLD	:=$(PATH)
PATHNEW	:=$(PWD)/bin:$(PATH_OLD)
PKG_CONFIG_PATH_NEW	:=$(PWD)/lib/pkgconfig:$(PKG_CONFIG_PATH_OLD):/usr/X11R76/lib/pkgconfig


GMFILES = $(foreach part, OpenSource, $(wildcard $(addprefix $(part)/,*.gz)))
GMFILES += $(foreach part, OpenSource, $(wildcard $(addprefix $(part)/,*.bz2)))
GMFILES += $(foreach part, OpenSource, $(wildcard $(addprefix $(part)/,*.xz)))

KGLIBFILES = $(foreach part, kglib, $(wildcard $(addprefix $(part)/,*.[ch])))
KBFILES = $(foreach part, keybrd, $(wildcard $(addprefix $(part)/,*.[ch])))

all	: keybrd/Keybrd

lib/libkulina.a	: lib/libgm.a $(KGLIBFILES) 
	echo "PREFIX=$(PWD)">kglib/config.mak
	echo "export X11_CFLAGS=\"$(X11_CFLAGS)\"">>kglib/config.mak
	echo "export X11_LIBS=\"$(X11_LIBS)\"">>kglib/config.mak
	$(MAKE) -C kglib 
	$(MAKE) -C kglib  install

lib/libgm.a	: $(GMFILES)
	echo "PREFIX=$(PWD)">OpenSource/config.mak
	echo "KULINA=$(PWD)">>OpenSource/config.mak
	echo "export X11_CFLAGS=\"$(X11_CFLAGS)\"">>OpenSource/config.mak
	echo "export X11_LIBS=\"$(X11_LIBS)\"">>OpenSource/config.mak
	echo "export PKG_CONFIG_PATH=$(PWD)/lib/pkgconfig:/usr/X11R76/lib/pkgconfig">>OpenSource/config.mak
	$(MAKE) -C OpenSource 
	$(MAKE) -C OpenSource install
keybrd/Keybrd	: lib/libgm.a lib/libkulina.a $(KBFILES)
	echo "PREFIX=$(PREFIX)">keybrd/config.mak
	echo "KULINA=$(PWD)">>keybrd/config.mak
	$(MAKE) -C keybrd
install	: keybrd/Keybrd
	  $(MAKE) -C keybrd install
clean	:
	 rm -rf lib/* share/* bin/* man/*
	$(MAKE) -C OpenSource clean
	$(MAKE) -C kglib clean
	$(MAKE) -C keybrd clean
