#include "color_coding_manual.h"

void PrepareColorCodingManual(char* buffer) {
    strcat(buffer, "---------------------------------------------------\n");
    strcat(buffer, "| Pair Number | Major Color  | Minor Color  |\n");
    strcat(buffer, "---------------------------------------------------\n");

    for (int pairNumber = 1; pairNumber <= numberOfMajorColors * numberOfMinorColors; ++pairNumber) {
        ColorPair colorPair = GetColorFromPairNumber(pairNumber);
        char row[128];
        snprintf(row, sizeof(row), "| %-12d | %-12s | %-12s |\n", 
                pairNumber, MajorColorNames[colorPair.majorColor], MinorColorNames[colorPair.minorColor]);
        strncat(buffer, row, MAX_BUFFER_SIZE - strlen(buffer) - 1);
    }

    strcat(buffer, "---------------------------------------------------\n");
}

