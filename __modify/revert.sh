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


# -- revert_exist(relative_path) --
my_revert_exist()
{
  local my_to="../$1"
  local my_to_orig="${my_to}.orig"
  
  echo -n "`basename $0`: $1: " 1>&2
  
  if [ -e "${my_to_orig}" ]; then
    rm -Rf "${my_to}" 2>/dev/null && mv -n "${my_to_orig}" "${my_to}" 2>/dev/null
    
    if [ "$?" -ne 0 ]; then
      echo "error reverting" 1>&2
      return 1
    fi
  else
    echo "original doesn't exist" 1>&2
    return 1
  fi
  
  echo "reverted" 1>&2
  
  return 0
}


# -- revert --
my_revert_exist net/samba43
my_revert_exist net/dhcpcd
my_revert_exist emulators/virtualbox-ose-additions
