char* intToRoman(int num) {
    if (num <= 0 || num > 3999) {
        // Valid Roman numerals are in the range 1 to 3999
        return NULL;
    }

    char* romanNumeral = (char*)malloc(20 * sizeof(char)); // Sufficient size for Roman numerals
    if (romanNumeral == NULL) {
        // Memory allocation failure
        return NULL;
    }
    romanNumeral[0] = '\0'; // Ensure the string is initially empty

    // Arrays to store Roman numeral symbols and their corresponding values
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // Build the Roman numeral string
    for (int i = 0; i < 13; ++i) {
        while (num >= values[i]) {
            strcat(romanNumeral, symbols[i]);
            num -= values[i];
        }
    }

    return romanNumeral;
}
