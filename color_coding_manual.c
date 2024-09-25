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
