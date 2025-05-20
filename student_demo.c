//Author's name: Charles Edwill Gabut
//Purpose: The program reads the data from the bin file and has the ability to add something in the bin file. The program has list (to list all the student information)
// add (to add a student in the bin file), search (to search for students and show its information), position (to output the position number of the student)
// telephone to change the phone of the student
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main() {

    char filebiname[64];
    
    printf("Enter the name of the bin or text file: ");
    if (!fgets(filebiname, sizeof(filebiname), stdin)) {
        printf("Error reading file name.\n");
        return 1;
    }
    size_t len = strlen(filebiname);
    if (len > 0 && filebiname[len - 1] == '\n') {
        filebiname[len - 1] = '\0';
    }
    FILE* binfile = fopen(filebiname, "rb+");
    if (!binfile) {
        printf("File not found. Creating a new binary file.\n");
        binfile = fopen(filebiname, "wb");
        if (!binfile) {
            printf("Error opening/creating file.\n");
            return 1;
        }

    }
    printf("File opened successfully: %s\n", filebiname);
    int flag = 0;
    int action;
    do {
        printf("\nEnter command (M for menu) or X (to exit): ");
        action = getchar();
        while (getchar() != '\n');
        flag = 0;

        switch (action) {
            case 'L':
                flag = 1;
                list(binfile);
                break;
            case 'A':
                flag = 1;
                addstudent(binfile);
                break;
            case 'S':
                flag = 1;
                search(binfile);
                break;
            case 'P':
                flag = 1;
                position(binfile);
                break;
            case 'T':
                flag = 1;
                telephone(binfile);
                break;
            case 'M':
                flag = 1;
                menu(binfile);
                break;  
        }
        if (action != 'X' && flag != 1) {
            printf("Invalid choice. Try Again!\n");
        }   
    } while (action != 'X');
    printf("Thank you! Have a great day!\n");
    fclose(binfile);
    return 0;
   
}