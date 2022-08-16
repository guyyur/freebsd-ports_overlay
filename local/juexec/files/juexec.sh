#!/bin/sh

# version 1.1

if [ -z $1 ]; then
  printf "Usage: $0 jail\n" 1>&2
  exit 1
fi

if [ "$(id -u)" = "0" ]; then
  printf "$0: running as root not supported\n" 1>&2;
  exit 1
fi

su - root -c "jexec -l -U '$USER' $1 /bin/sh -i -c '. /etc/profile; [ -e ./.profile ] && . ./.profile; exec sh -i'"
