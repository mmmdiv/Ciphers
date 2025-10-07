/*
Project Name: Encryption Algorithm Testing
Author: Even Birhane (ebirhane)
Partner: [Partner Name] ([Partner Uniqname])
Description: This file contains test cases for functions declared in utility.h, 
             caesar.h, vigenere.h, and polybius.h.
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

void startTests() {
    testShiftAlphaCharacter();
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testCaesarCipher();
    testVigenereCipher();
    testMixKey();
    testFillGrid();
    testFindInGrid();
    testPolybiusSquare();
    return;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function shiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "Expected: 'b', Actual: '" << shiftAlphaCharacter('a', 1) << "'" << endl;
    cout << "Expected: 'd', Actual: '" << shiftAlphaCharacter('b', 2) << "'" << endl;
    return;
}

void testToUpperCase() {
    cout << "Now testing function toUpperCase()" << endl;
    cout << "Expected: 'DIAG @ 11 P.M.', Actual: '" << toUpperCase("Diag @ 11 p.m.") << "'" << endl;
    return;
}

void testRemoveNonAlphas() {
    cout << "Now testing function removeNonAlphas()" << endl;
    cout << "Expected: 'Diagpm', Actual: '" << removeNonAlphas("Diag @ 11 p.m.") << "'" << endl;
    return;
}

void testRemoveDuplicate() {
    cout << "Now testing function removeDuplicate()" << endl;
    cout << "Expected: 'HELOWRD', Actual: '" << removeDuplicate("HELLOWORLD") << "'" << endl;
    return;
}

void testCharToInt() {
    cout << "Now testing function charToInt()" << endl;
    cout << "Expected: 1, Actual: " << charToInt('1') << endl;
    return;
}

void testCaesarCipher() {
    cout << "Now testing function caesarCipher()" << endl;
    cout << "Expected: 'Cuuj cu qj jxu Tyqw qj 11 f.c.', Actual: '" << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << "'" << endl;
    cout << "Expected: 'Meet me at the Diag at 11 p.m.', Actual: '" << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << "'" << endl;
    return;
}

void testVigenereCipher() {
    cout << "Now testing function vigenereCipher()" << endl;
    cout << "Expected: 'Euyb dv ee lxy Lzrk ll 11 f.g.', Actual: '" << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true) << "'" << endl;
    cout << "Expected: 'Meet me at the Diag at 11 p.m.', Actual: '" << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false) << "'" << endl;
    return;
}

void testMixKey() {
    cout << "Now testing function mixKey()" << endl;
    cout << "Expected: 'POLYBIUSACDEFGHJKMNQRTVWXZ0123456789', Actual: '" << mixKey("POLYBIUS") << "'" << endl;
    return;
}

void testFillGrid() {
    cout << "Now testing function fillGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, "ABCDEFGHIKLMNOPQRSTUVWXYZ0123456789");
    cout << "Grid filled with key." << endl;
    return;
}

void testFindInGrid() {
    cout << "Now testing function findInGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, "ABCDEFGHIKLMNOPQRSTUVWXYZ0123456789");
    cout << "Expected: '00', Actual: '" << findInGrid('A', grid) << "'" << endl;
    return;
}

void testPolybiusSquare() {
    cout << "Now testing function polybiusSquare()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, "ABCDEFGHIKLMNOPQRSTUVWXYZ0123456789");
    cout << "Expected: '15151311 435445 0511 332215 04151133', Actual: '" << polybiusSquare(grid, "POLYBIUS", "EECS 183 IS THE BEST", true) << "'" << endl;
    return;
}
