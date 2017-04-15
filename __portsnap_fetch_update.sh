#!/bin/sh

portsnap -l $(realpath DESCRIBE.local) fetch update

fix_index_patterns=""    # -e 's/PORT-OLD_VER\|/PORT-NEW_VER\|/' ...
if [ -n "$fix_index_patterns" ]; then
  sed $fix_index_patterns -i.orig ../INDEX-??
fi
