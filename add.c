#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
int addstudent(FILE* file) {
    struct csufstudent person;
    char * level_grade[] = {"Freshman" , "Sophomore" , "Junior", "Senior" ,"Unknown"};
    char text[256];
    printf("Enter the name of student: ");
    fgets(person.name, sizeof(person.name), stdin);
    if (person.name[strlen(person.name) - 1] == '\n') {
        person.name[strlen(person.name) - 1] = '\0';
    }
    printf("Enter the CWID: ");
    if (fscanf(stdin, "%u", &person.cwid) != 1) {
        printf("Error reading CWID\n");
        return -1;
    }
    fgetc(stdin);
    printf("Enter the Major: ");
    if (!fgets(person.major, sizeof(person.major), stdin)) {
        printf("Error reading major\n");
        return -1;
    }
    if (person.major[strlen(person.major) - 1] == '\n') {
        person.major[strlen(person.major) - 1] = '\0';
    }
    printf("Enter Class Level: ");
    fgets(text, sizeof(text), stdin);
    if (text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }
    person.level = atoe(text);
    strcpy(person.level_string, level_grade[person.level]);
    printf("Enter number of classes: ");
    if (fscanf(stdin, "%u", &person.num_of_classes) != 1) {
        printf("Error reading number of classes\n");
        return -1;
    }
    fgetc(stdin);
    for (int i = 0; i < person.num_of_classes; ++i) {
        printf("Enter Class course: ");
        if (!fgets(person.classes[i], 24, stdin)) {
            printf("Error reading class name\n");
            return -1;
        }

        size_t len = strlen(person.classes[i]);
        if (len > 0 && person.classes[i][len - 1] == '\n') {
            person.classes[i][len - 1] = '\0';
        }
    }
    printf("Enter Phone Number: ");
    if (fscanf(stdin, "%lu", &person.phone) != 1) {
        printf("Error reading phone\n");
        return -1;
    }
    fgetc(stdin);
    printf("Enter Parking Fee: ");
    if (fscanf(stdin, "%f", &person.parking_fee) != 1) {
        printf("Error reading parking fee: ");
        return -1;
    }
    fgetc(stdin);
    fseek(file, 0, SEEK_END); 
    fwrite(&person, sizeof(struct csufstudent), 1, file);
    return 0;
}