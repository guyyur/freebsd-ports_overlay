#!/bin/sh

portsnap -l $(realpath DESCRIBE.local) fetch update

fix_index_patterns=""    # -e 's/PORT-OLD_VER\|/PORT-NEW_VER\|/' ...
fix_index_patterns="${fix_index_patterns} -e s/dhcpcd-6.11.5_1/dhcpcd-7.0.8/"
fix_index_patterns="${fix_index_patterns} -e s/sunxi-tools-1.4.2/sunxi-tools-1.4.2.5c19710/"
if [ -n "$fix_index_patterns" ]; then
  sed $fix_index_patterns -i.orig INDEX-?? && rm -f INDEX-??.orig
fi
