// main.c
#include "color_pair.h"

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    // Print the formatted color coding manual
    PrintColorCodingManual();

    return 0;
}
