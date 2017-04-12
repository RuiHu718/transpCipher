#include <iostream>
#include "console.h"
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
using namespace std;

// Transposition Cipher

const char PAD = '~'; // padding character for cipher

// Function Prototypes
// Add more functions of your own, as well
string encrypt(string plaintext, string key);
string decrypt(string ciphertext, string key);

int main() {
    int encryptChoice = 1;
    while (encryptChoice > 0) {
        cout << "Welcome to the Transposition Cipher Machine!" << endl;
        cout << "Please choose:" << endl;
        cout << "1) encrypt text" << endl;
        cout << "2) decrypt text" << endl;
        encryptChoice = getInteger("Please type your choice, 0 to end:","Please type an integer!");

        if (encryptChoice > 0) {
            cout << "Please enter the text to " << (encryptChoice == 1 ? "encrypt: " : "decrypt: ");
            string text = getLine();
            string key = getLine("Please type in a key: ");
            string output;
            if (encryptChoice == 1) {
                output = encrypt(text, key);
                cout << "Encrypted ";

            } else if (encryptChoice == 2) {
                output = decrypt(text, key);
                cout << "Decrypted ";
            }
            cout << "text:" << endl << endl << "\"" << output << "\"" << endl << endl;
        }
    }
    cout << "Goodbye!" << endl;
    return 0;
}

string encrypt(string plaintext, string key) {
    // TODO: Implement the transposition cipher encryption
    string ciphertext;
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    // TODO: Implement the transposition cipher decryption
    string plaintext;
    return plaintext;
}
