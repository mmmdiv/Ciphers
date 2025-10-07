/*
 * utility.cpp
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

#include "utility.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************
string toUpperCase(string original) {
    for (char &c : original) {
        c = toupper(c);
    }
    return original;
}

string removeNonAlphas(string original) {
    string result;
    for (char c : original) {
        if (isalpha(c)) {
            result += c;
        }
    }
    return result;
}

int charToInt(char original) {
    if (isdigit(original)) {
        return original - '0';
    }
    return -1; // Return -1 if not a digit
}

string removeDuplicate(string original) {
    string result;
    for (char c : original) {
        if (result.find(c) == string::npos) {
            result += c;
        }
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
