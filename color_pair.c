#include "color_pair.h"

// Definitions for major and minor color names
const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
const int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
const int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    snprintf(buffer, MAX_BUFFER_SIZE, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int index = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(index / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(index % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}
