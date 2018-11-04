#!/bin/sh


# -- check for root --
if [ "`id -u`" != "0" ]; then
  echo "`basename $0`: sorry, this must be done as root." 1>&2
  exit 1
fi


# -- check running in ports dir --
if [ ! -e Makefile -o ! -e GIDs -o ! -e UIDs ]; then
  echo "not in ports dir" 1>&2
  exit 1
fi


# -- replace(relative_path) --
my_replace()
{
  local my_from="$1.modified"
  local my_to="$1"
  local my_to_orig="${my_to}.orig"
  
  echo -n "`basename $0`: $1: " 1>&2
  
  if [ ! -e "${my_to_orig}" ]; then
    mv -n "${my_to}" "${my_to_orig}" 2>/dev/null
    if [ "$?" -ne 0 ]; then
      echo "error backuping orig" 1>&2
      return 1
    fi
    
    cp -nR "${my_from}" "${my_to}" 2>/dev/null
    
    if [ "$?" -ne 0 ]; then
      echo "error replacing" 1>&2
      return 1
    fi
  else
    echo "original already exists" 1>&2
    return 1
  fi
  
  echo "replaced" 1>&2
  
  return 0
}


# -- restore(relative_path) --
my_restore()
{
  local my_to="$1"
  local my_to_orig="${my_to}.orig"
  
  echo -n "`basename $0`: $1: " 1>&2
  
  if [ -e "${my_to_orig}" ]; then
    rm -Rf "${my_to}" 2>/dev/null
    if [ "$?" -ne 0 ]; then
      echo "error removing" 1>&2
      return 1
    fi
    
    mv -n "${my_to_orig}" "${my_to}" 2>/dev/null
    if [ "$?" -ne 0 ]; then
      echo "error restoring original" 1>&2
      return 1
    fi
  else
    echo "original doesn't exist" 1>&2
    return 1
  fi
  
  echo "restored" 1>&2
  
  return 0
}


# --
my_list="
  comms/sunxi-tools
  devel/arm-none-eabi-gcc
  devel/autoconf
  devel/binutils
  editors/nano
  emulators/qemu
  emulators/qemu-sbruno
  multimedia/ffmpeg
  net/dhcpcd
  net/samba48
  security/gnutls
  x11/slock
  "

# --
case $1 in
  replace)
    for i in $my_list; do
      my_replace "$i"
    done
    ;;
  restore)
    for i in $my_list; do
      my_restore "$i"
    done
    ;;
  compare)
    for i in $my_list; do
      diff -Nudrp "$i.modified" "$i" | less -c
    done
    ;;
  *)
    echo "usage: $0 [replace|restore|compare]" 1>&2
    exit 1
    ;;
esac
