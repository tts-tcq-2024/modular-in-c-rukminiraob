// color_pair.h
#ifndef COLOR_PAIR_H
#define COLOR_PAIR_H

#include <stdio.h>
#include <assert.h>

#define MAX_BUFFER_SIZE 1024

// Enumerations for major and minor colors
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

// Constant strings for color names
extern const char* MajorColorNames[];
extern const char* MinorColorNames[];

extern const int numberOfMajorColors;
extern const int numberOfMinorColors;

// Structure to hold a color pair
typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

// Function declarations
void ColorPairToString(const ColorPair* colorPair, char* buffer);
ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair* colorPair);
void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor);
void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber);

void PrintColorCodingManual();

#endif // COLOR_PAIR_H
