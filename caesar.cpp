/*
 * caesar.cpp
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

#include "caesar.h"
#include <iostream>

char shiftAlphaCharacter(char c, int n) {
    if (isalpha(c)) {
        char base = isupper(c) ? 'A' : 'a';
        return (c - base + n) % 26 + base;
    }
    return c; // Should never reach here due to function contract
}

string caesarCipher(string original, int key, bool encrypt) {
    if (!encrypt) {
        key = -key;
    }
    for (char &c : original) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + key + 26) % 26 + base;
        }
    }
    return original;
}