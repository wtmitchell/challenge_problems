#!/bin/bash

#===-- tools/check_format.sh ------------------------------------------------===
#
# Challenge Problem solutions by Will Mitchell
#
# This file is distributed under the MIT License. See LICENSE for details.
#
#===-------------------------------------------------------------------------===

if ! which clang-format; then
    echo "Error: cannot find clang-format"
    exit 1
fi

DIFFERENCE=0
FLAGS=-style=file

for ARG in "$@"
do
    clang-format $FLAGS $ARG | diff -u $ARG -

    if [[ $? -eq 1 ]]; then
	DIFFERENCE=1
    fi
done

if [[ $DIFFERENCE -eq "1" ]];
then
    echo "Error: clang-format reported formatting differences"
    exit 1
else
    echo "OK: clang-format reported no formatting differences"
    exit 0
fi

