#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
int menu() {
    printf("Menu\n");
        printf("L - Output a list of all the student infomations in the bin file\n");
        printf("A - Add a new student to the bin file\n");
        printf("S - Search to output the information of the student and output the position number of the found student\n");
        printf("P - Find and show the position number of the student.\n");
        printf("T - Change the telephone number of the student.\n");
        printf("M - Display menu commands with a short statement.\n");
        printf("X - Exit from the program.\n");
        printf("\n");
    return 0;
}