/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * EECS 183: Project 3
 * Winter 2025
 *
 * <#description#>
 */


#include "polybius.h"
#include <string>
using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************

/*
Project Name: Encryption Algorithm Testing
Author: Even Birhane (ebirhane)
Partner: [Partner Name] ([Partner Uniqname])
Description: This test file is designed to test the functions declared in
             utility.h, caesar.h, vigenere.h, and polybius.h.
*/

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testShiftAlphaCharacter();
void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testCaesarCipher();
void testVigenereCipher();
void testMixKey();
void testFillGrid();
void testFindInGrid();
void testPolybiusSquare();


//************************************************************************
// Implement the functions below this line.
//************************************************************************

string mixKey(string key) {
    string mixedKey;
    key = toUpperCase(removeDuplicate(key));  // Remove duplicates and convert to uppercase

    // Append unique characters from key
    for (char c : key) {
        if (isalnum(c) && mixedKey.find(c) == string::npos) {
            mixedKey += c;
        }
    }

    // Append remaining characters from ALNUM (defined in utility.h)
    string ALNUM = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (char c : ALNUM) {
        if (mixedKey.find(c) == string::npos) {
            mixedKey += c;
        }
    }

    return mixedKey;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = content[index++];
        }
    }
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == c) {
                return to_string(i) + to_string(j);  // Row and column as string
            }
        }
    }
    return "";  // Return empty if character is not found
}

string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool encrypt) {
    fillGrid(grid, mixKey(key));  // Ensure grid is correctly filled
    string result = "";

    if (encrypt) {
        for (char c : original) {
            if (c == ' ') {
                result += " ";  // Preserve spaces
            } else {
                string pos = findInGrid(toupper(c), grid);
                if (!pos.empty()) {
                    result += pos;
                }
            }
        }
    } else {
        for (size_t i = 0; i < original.length(); i += 2) {
            if (original[i] == ' ') {
                result += " ";
                i--;  // Adjust for spaces
            } else {
                int row = original[i] - '0';
                int col = original[i + 1] - '0';
                result += grid[row][col];
            }
        }
    }

    return result;
}