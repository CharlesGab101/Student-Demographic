#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
int telephone(FILE* file) {
    fseek(file, 0, SEEK_SET);
    struct csufstudent temp;
    unsigned int cwid;
    unsigned long phone_number;
    int flag = 0;
    char text_name[50];

    printf("Enter CWID number: ");
    scanf("%u", &cwid);
    while (getchar() != '\n');

    while (fread(&temp, sizeof(struct csufstudent), 1, file)) {
        if (temp.cwid == cwid) {
            printf("\nStudent Found!\n");
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("Enter new name: ");
        fgets(text_name, sizeof(text_name), stdin);
        while (getchar() != '\n');
        printf("Enter new phone number: ");
        scanf("%lu", &phone_number);
        while (getchar() != '\n');

        fseek(file, 0, SEEK_SET);
        while (fread(&temp, sizeof(struct csufstudent), 1, file)) {
            if (temp.cwid == cwid) {
                strcpy(temp.name, text_name);
                temp.phone = phone_number;
                fseek(file, -sizeof(struct csufstudent), SEEK_CUR);
                fwrite(&temp, sizeof(struct csufstudent), 1, file);
                break;
            }
        }
        printf("Phone number updated successfully.\n");
        return 0;
    } else {
        printf("Student not found.\n");
        return -1;
    }
}