#!/bin/sh


# -- check for root --
if [ "$(id -u)" != "0" ]; then
  echo "$(basename $0): sorry, this must be done as root." 1>&2
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
  local my_orig="__orig/${1}"
  local my_from="__overlay/$1"
  local my_to="$1"
  
  echo -n "`basename $0`: $1: " 1>&2
  
  if [ ! -e "${my_orig}" ]; then
    echo "original doesn't exist" 1>&2
    return 1
  fi

  rm -Rf "${my_to}" 2>/dev/null
  if [ "$?" -ne 0 ]; then
    echo "error removing" 1>&2
    return 1
  fi
  
  cp -nR "${my_from}" "${my_to}" 2>/dev/null
  if [ "$?" -ne 0 ]; then
    echo "error replacing" 1>&2
    return 1
  fi
  
  echo "replaced" 1>&2
  
  return 0
}


# -- restore(relative_path) --
my_restore()
{
  local my_orig="__orig/${1}"
  local my_to="$1"
  
  echo -n "`basename $0`: $1: " 1>&2
  
  if [ ! -e "${my_orig}" ]; then
    echo "original doesn't exist" 1>&2
    return 1
  fi
  
  rm -Rf "${my_to}" 2>/dev/null
  if [ "$?" -ne 0 ]; then
    echo "error removing" 1>&2
    return 1
  fi
  
  cp -nR "${my_orig}" "${my_to}" 2>/dev/null
  if [ "$?" -ne 0 ]; then
    echo "error restoring original" 1>&2
    return 1
  fi
  
  echo "restored" 1>&2
  
  return 0
}


# --
my_list="
  comms/sunxi-tools
  devel/liblxqt
  editors/xed
  net/dhcpcd
  net/samba413
  sysutils/lxtask
  x11/gmrun
  x11/slock
  x11/tint
  x11-servers/xorg-server
  x11-themes/lxappearance
  Mk/Uses/xorg-cat.mk
  "

# --
case $1 in
  backup)
    if [ ! -d __orig ]; then
      mkdir __orig || exit 1
    fi
    for i in $my_list; do
      if [ ! -d "__orig/$i" ]; then
        d=$(dirname $i)
        if [ "$d" != "." -a ! -d "__orig/$d" ]; then
          mkdir "__orig/$d" || exit 1
        fi
        cp -a "$i" "__orig/$i" || exit 1
      fi
    done
    ;;
  compare-orig)
    for i in $my_list; do
      diff -Nudrp "__orig/$i" "$i" | less -c
    done
    ;;
  compare-overlay)
    for i in $my_list; do
      diff -Nudrp "__overlay/$i" "$i" | less -c
    done
    ;;
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
  *)
    echo "usage: $0 [backup|compare-orig|compare-overlay|replace|restore]" 1>&2
    exit 1
    ;;
esac
