// color_pair.c
#include "color_pair.h"

// Definitions for major and minor color names
const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

const int MAX_COLORPAIR_NAME_CHARS = 16;

// Convert ColorPair to string
void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

// Get ColorPair from pair number
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

// Get pair number from ColorPair
int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

// Test function for pair to number conversion
void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

// Test function for number to pair conversion
void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

// Print a formatted header for the reference manual
void PrintManualHeader() {
    printf("---------------------------------------------------\n");
    printf("| %-12s | %-12s | %-12s |\n", "Pair Number", "Major Color", "Minor Color");
    printf("---------------------------------------------------\n");
}

// Print a row for a color pair, including its pair number and colors
void PrintColorPairRow(int pairNumber, const char* majorColor, const char* minorColor) {
    printf("| %-12d | %-12s | %-12s |\n", pairNumber, majorColor, minorColor);
}

// Print a footer to complete the table format
void PrintManualFooter() {
    printf("---------------------------------------------------\n");
}

// Function to print the entire 25-pair color coding manual in a table format
void PrintColorCodingManual() {
    PrintManualHeader(); // Start with the header
    for (int pairNumber = 1; pairNumber <= numberOfMajorColors * numberOfMinorColors; ++pairNumber) {
        // Get the color pair corresponding to the pair number
        ColorPair colorPair = GetColorFromPairNumber(pairNumber);
        // Print the row with pair number, major color, and minor color
        PrintColorPairRow(pairNumber, MajorColorNames[colorPair.majorColor], MinorColorNames[colorPair.minorColor]);
    }
    PrintManualFooter(); // End with the footer
}

