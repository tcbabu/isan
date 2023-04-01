#!/bin/bash
install -m 755  SetPhoto /usr/bin/SetPhoto
mkdir -p /usr/share/lina
install  -m 755 userphoto.png /usr/share/lina/
install  -m 755 userphoto.desktop  /usr/share/applications/
install -m 755  configlina /usr/sbin/configlina
install -m 755 configlina.png /usr/share/lina
install -m 755 ninjagirl.jpg  /usr/share/lina
install -m 755 configlina.desktop /usr/share/applications/
install -m 755  lina /usr/sbin/lina
install -m 755 lina.init  /usr/share/lina
