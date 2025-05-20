#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
int position(FILE* file) {
    fseek(file, 0, SEEK_SET);
    struct csufstudent temp;
    unsigned int cwid;
    printf("Enter CWID number: ");
    fscanf(stdin, "%u", &cwid);
    fgetc(stdin);
    int pos = 0;
    int found = 0; 
    while (fread(&temp, sizeof(struct csufstudent), 1, file)) {
        if (temp.cwid == cwid) {
            int bytes = ftell(file);
            int pos = bytes / sizeof(struct csufstudent);
            --pos;
            printf("\n");
            printf("Student found at position: %d\n\n", pos);

            found = 1;
        }
    }
    if (found != 1) {
        printf("Student not found!\n");
        return -1;
    }
    return pos;
}