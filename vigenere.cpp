/*
 * vigenere.cpp
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
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string vigenereCipher(string original, string keyword, bool encrypt) {
    string processedKey;
    for (char c : keyword) {
        if (isalpha(c)) {
            processedKey += toupper(c);
        }
    }
    
    if (processedKey.empty()) return original;
    
    string result;
    int keyLength = processedKey.length();
    int keyIndex = 0;
    
    for (char c : original) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int shift = processedKey[keyIndex % keyLength] - 'A';
            if (!encrypt) shift = -shift;
            result += (c - base + shift + 26) % 26 + base;
            keyIndex++;
        } else {
            result += c;
        }
    }
    return result;
}
