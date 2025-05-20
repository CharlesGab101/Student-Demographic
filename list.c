#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
int list(FILE * file) {    
    struct csufstudent person;
    fseek(file, 0, SEEK_SET);
    while (0 < fread(&person, sizeof(struct csufstudent), 1, file)) {
        printf("\n");
        printf("Name: %s\n", person.name);
        printf("CWID: %u\n", person.cwid);
        printf("Major: %s\n", person.major);
        printf("Class Level: %s\n", person.level_string);
        printf("Classes enrolled: %d\n", person.num_of_classes);
        for (int i = 0; i < person.num_of_classes; ++i) {
            printf("%s\n", person.classes[i]);
        }
        printf("Phone: %lu\n", person.phone);
        printf("Parking: %.2f\n", person.parking_fee);   
        printf("\n");
    }
    return 0;
}