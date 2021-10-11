#!/bin/bash
gcc -Wall -Werror -Wextra -c *.c
ar rc libstr.a *.o
rm *.o
ranlib libstr.a
