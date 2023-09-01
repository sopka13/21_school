#!/bin/bash

gcc main.c exam.h -o microshell -Wall -Wextra -Werror -g

./microshell
./microshell ";" 
./microshell ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";"
./microshell "|"
./microshell "|" "|"
./microshell "|" "|" "|" "|" "|" "|" "|" ";" ";" ";" ";" ";" ";" ";" ";" ";"
./microshell 1 2 3 4 5 6 7 8 9
./microshell hello1 hello2 hello3 ";" fine1 fine2 fine4 ";" stop1 stop2 stop3
./microshell hello1 "|" hello2 hello3 ";" fine1 fine2 "|" fine4 ";" stop1 "|" stop2 stop3
./microshell /bin/ls
./microshell /bin/ls "|" /bin/grep main ";" cd /home/sergey/ ";" /bin/ls
./microshell /bin/ls "|" /bin/grep main  "|" /bin/grep main "|" /bin/grep main "|" /bin/grep main "|" /bin/grep main "|" /bin/grep main ";" cd /home/sergey/ ";" /bin/ls "|" /bin/grep main ";" /bin/ls "|" /bin/grep main ";" /bin/ls "|" /bin/grep main ";" /bin/ls "|" /bin/grep main ";" /bin/ls "|" /bin/grep main  ";" cd 12345
./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
./microshell /bin/ls "|" /bin/grep main "|" /bin/grep main "|" /bin/grep main "|" /bin/grep main "|" /bin/grep main