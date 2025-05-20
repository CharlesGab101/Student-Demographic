#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
int search(FILE* file) {
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
            printf("\n"); 
            printf("Student found at position: %d\n", pos);
            printf("Name: %s\n", temp.name);
            printf("CWID: %u\n", temp.cwid);
            printf("Major: %s\n", temp.major);
            printf("Class level: %s\n", temp.level_string);
            printf("Classes enrolled: %u\n", temp.num_of_classes);
            for (int i = 0; i < temp.num_of_classes ; ++i) {
                printf("%s\n", temp.classes[i]);
            }
            printf("Phone: %lu\n", temp.phone);
            printf("Parking: %.2f\n", temp.parking_fee);
            printf("\n");
            found = 1;
        }
        ++pos;
    }
    if (!found) {
        printf("Student not found!\n");
        printf("\n");
        return 0;
    }
    return 0;
}