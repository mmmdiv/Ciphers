/*
 * ciphers.cpp
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
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************
void ciphers() {
    string cipherChoice, mode, message, key;
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    getline(cin, cipherChoice);
    cipherChoice = toUpperCase(cipherChoice);
    
    if (cipherChoice != "CAESAR" && cipherChoice != "VIGENERE" && cipherChoice != "POLYBIUS" &&
        cipherChoice != "C" && cipherChoice != "V" && cipherChoice != "P") {
        cout << "Invalid cipher!" << endl;
        return;
    }
    
    cout << "Encrypt or decrypt: ";
    getline(cin, mode);
    mode = toUpperCase(mode);
    
    if (mode != "ENCRYPT" && mode != "DECRYPT" && mode != "E" && mode != "D") {
        cout << "Invalid mode!" << endl;
        return;
    }
    
    bool encrypt = (mode == "ENCRYPT" || mode == "E");
    
    cout << "Enter a message: ";
    getline(cin, message);
    
    cout << "What is your key: ";
    getline(cin, key);
    
    if (cipherChoice == "CAESAR" || cipherChoice == "C") {
        int caesarKey = stoi(key);
        cout << (encrypt ? "The encrypted message is: " : "The decrypted message is: ")
             << caesarCipher(message, caesarKey, encrypt) << endl;
    }
    else if (cipherChoice == "VIGENERE" || cipherChoice == "V") {
        if (removeNonAlphas(key).empty()) {
            cout << "Invalid key!" << endl;
            return;
        }
        cout << (encrypt ? "The encrypted message is: " : "The decrypted message is: ")
             << vigenereCipher(message, key, encrypt) << endl;
    }
    else if (cipherChoice == "POLYBIUS" || cipherChoice == "P") {
        message = toUpperCase(message);
        key = toUpperCase(key);
        if (removeNonAlphas(key) != key) {
            cout << "Invalid key!" << endl;
            return;
        }
        key = removeDuplicate(key);
        
        char grid[SIZE][SIZE];
        cout << (encrypt ? "The encrypted message is: " : "The decrypted message is: ")
             << polybiusSquare(grid, key, message, encrypt) << endl;
    }
}