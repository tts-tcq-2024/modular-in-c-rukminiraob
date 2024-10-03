#ifndef COLOR_PAIR_TEST_H
#define COLOR_PAIR_TEST_H

#include "color_pair.h"

// Test functions
void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor);
void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber);

#endif // COLOR_PAIR_TEST_H
