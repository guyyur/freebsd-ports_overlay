#!/bin/sh


# -- check for root --
if [ "`id -u`" != "0" ]; then
  echo "`basename $0`: sorry, this must be done as root." 1>&2
  exit 1
fi


# -- check in ports changes dir --
if [ ! -e ../Makefile ]; then
  echo "not in ports dir" 1>&2
  exit 1
fi


# -- replace_exist(relative_path) --
my_replace_exist()
{
  local my_from="tree/$1"
  local my_to="../$1"
  local my_to_orig="${my_to}.orig"
  
  echo -n "`basename $0`: $1: " 1>&2
  
  if [ ! -e "${my_to_orig}" ]; then
    mv -n "${my_to}" "${my_to_orig}" 2>/dev/null && cp -nR "${my_from}" "${my_to}" 2>/dev/null
    
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


# -- apply --
my_replace_exist emulators/virtualbox-ose-additions
my_replace_exist net/dhcpcd
my_replace_exist net/samba43
