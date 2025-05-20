#include "student.h"
enum student_level atoe(const char * txt) {
    enum student_level var = UNKNOWN;
    if (strcmp(txt, "Freshman") == 0) {
        var = FRESHMAN;
    }
    else if (strcmp(txt, "Sophomore") == 0) {
        var = SOPHOMORE;
    } else if (strcmp(txt, "Junior") == 0) {
        var = JUNIOR;
    } else if (strcmp(txt, "Senior") == 0) {
        var = SENIOR;
    } else {
        var = UNKNOWN;
    }
    return var;
}