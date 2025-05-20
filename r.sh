#!/bin/bash

#Author's name: Charles Edwill Gabut

echo "Compiling files"
gcc -c -Wall -m64 -no-pie -o student_demo.o student_demo.c -std=c17
gcc -c -Wall -m64 -no-pie -o list.o list.c -std=c17
gcc -c -Wall -m64 -no-pie -o add.o add.c -std=c17
gcc -c -Wall -m64 -no-pie -o search.o search.c -std=c17
gcc -c -Wall -m64 -no-pie -o position.o position.c -std=c17
gcc -c -Wall -m64 -no-pie -o telephone.o telephone.c -std=c17
gcc -c -Wall -m64 -no-pie -o menu.o menu.c -std=c17
gcc -c -Wall -m64 -no-pie -o atoe.o atoe.c -std=c17
echo "Compiled files"
echo "Linking Files"
gcc -m64 -no-pie -o student_exe.out student_demo.o list.o add.o search.o atoe.o position.o telephone.o menu.o -std=c17
chmod u+x student_exe.out
echo "Linked Files"
echo
./student_exe.out

echo "Terminate"

rm student_demo.o list.o add.o search.o position.o telephone.o menu.o atoe.o
rm student_exe.out