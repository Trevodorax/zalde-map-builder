#include "utils.h"

int fileExists(const char * fileName) {
    FILE * file = fopen(fileName, "r");
    if(file == NULL) {
        fclose(file)
        return 0;
    }
    fclose(file);
    return 1;
}
