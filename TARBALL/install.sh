#!/bin/bash
make
make install
mkdir -p /usr/share/isan
install  -m 755 isan.desktop  /usr/share/applications/
install -m 755 keyboard.png /usr/share/isan/

