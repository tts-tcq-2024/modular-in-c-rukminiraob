#include "color_pair.h"
#include <string.h> // for strcat

#define MAX_BUFFER_SIZE 1024

// Prepare a color coding manual in a string format instead of directly printing
void PrepareColorCodingManual(char* buffer) {
    strcat(buffer, "---------------------------------------------------\n");
    strcat(buffer, "| Pair Number | Major Color  | Minor Color  |\n");
    strcat(buffer, "---------------------------------------------------\n");

    for (int pairNumber = 1; pairNumber <= numberOfMajorColors * numberOfMinorColors; ++pairNumber) {
        ColorPair colorPair = GetColorFromPairNumber(pairNumber);
        char row[128]; // temporary row storage
        snprintf(row, sizeof(row), "| %-12d | %-12s | %-12s |\n", 
                pairNumber, MajorColorNames[colorPair.majorColor], MinorColorNames[colorPair.minorColor]);
        strcat(buffer, row); // append row to buffer
    }

    strcat(buffer, "---------------------------------------------------\n");
}

int main() {
    char buffer[MAX_BUFFER_SIZE] = ""; // to store the entire manual
    PrepareColorCodingManual(buffer);
    printf("%s", buffer); // print the prepared data
    return 0;
}
