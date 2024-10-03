#include "color_pair.h"

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    
    char buffer[MAX_BUFFER_SIZE] = ""; // to store the entire manual
    PrepareColorCodingManual(buffer);
    printf("%s", buffer); // print the prepared data
    return 0;
    return 0;
}
