#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>
#include <string.h>
//Author's name: Charles Edwill Gabut
//Author's email address: charles_g@csu.fullerton.edu
//CPSC 223C
//Due Date: April, 12, 2025

enum student_level {
    FRESHMAN,
    SOPHOMORE,
    JUNIOR,
    SENIOR,
    UNKNOWN
};

enum student_level atoe(const char * txt);

int list(FILE * file);
int addstudent(FILE* file);
int search(FILE* file);
int position(FILE* file);
int telephone(FILE* file);
int menu();


struct csufstudent
{
    char name[24];
    unsigned int cwid;
    char major[24];
    enum student_level level;
    unsigned int num_of_classes;
    char classes[6][24];
    unsigned long phone;
    float parking_fee;
    char level_string[10];
};

#endif