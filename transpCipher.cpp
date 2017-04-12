#include <iostream>
#include "console.h"
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "grid.h"
using namespace std;

// Transposition Cipher

const char PAD = '~'; // padding character for cipher

// Function Prototypes
// Add more functions of your own, as well
string encrypt(string plaintext, string key);
string decrypt(string ciphertext, string key);
Vector<int> genLetterOrder(string key);
void loadPlainText(Grid<char> &textG, string text, string key);
int findIndex(const Vector<int> &order, int value);
string printColum(const Grid<char> &textG, int col);

int main() {
  // int encryptChoice = 1;
  // while (encryptChoice > 0) {
  //   cout << "Welcome to the Transposition Cipher Machine!" << endl;
  //   cout << "Please choose:" << endl;
  //   cout << "1) encrypt text" << endl;
  //   cout << "2) decrypt text" << endl;
  //   encryptChoice = getInteger("Please type your choice, 0 to end:","Please type an integer!");

  //   if (encryptChoice > 0) {
  //     cout << "Please enter the text to " << (encryptChoice == 1 ? "encrypt: " : "decrypt: ");
  //     string text = getLine();
  //     string key = getLine("Please type in a key: ");
  //     string output;
  //     if (encryptChoice == 1) {
  // 	output = encrypt(text, key);
  // 	cout << "Encrypted ";

  //     } else if (encryptChoice == 2) {
  // 	output = decrypt(text, key);
  // 	cout << "Decrypted ";
  //     }
  //     cout << "text:" << endl << endl << "\"" << output << "\"" << endl << endl;
  //   }
  // }


  //Vector<int> test = genLetterOrder("COMPSCI");
  //cout << test.toString() << endl;
  cout << encrypt("I have a dream!", "king") << endl;
  
  cout << "Goodbye!" << endl;
  return 0;
}

string encrypt(string plaintext, string key) {
  string ciphertext;

  Grid<char> textG;
  loadPlainText(textG, plaintext, key);
  Vector<int> order = genLetterOrder(key);
  //cout << textG.toString() << endl;
  
  for (int i = 0; i < key.length(); i++) {
    int index = findIndex(order, i);
    ciphertext += printColum(textG, index);
  }
  return ciphertext;
}

string decrypt(string ciphertext, string key) {
  // TODO: Implement the transposition cipher decryption
  string plaintext;
  return plaintext;
}


/* Function: genLetterOrder
 * Usage:    vec = genLetterOrder(key)
 * ------------------------------------
 * Example: COMPSCI => [0435612]
 * Precondition:
 * Postcondition:
 * Issues: what happens when you have special chars in key?
 * What is their ordering?
 * Do I need to worry about case?
 */
Vector<int> genLetterOrder(string key) {
  int length = key.length();
  Vector<int> order(length, 0);	// initialize vec

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (i == j) continue;
      if (key[i] > key[j]) order[i]++;
      // tricky code, explain later
      if ((key[i] == key[j]) && (i > j)) order[i]++;
    }
  }

  return order;
}


/* Function: loadPlainText
 * Usage:    loadPlainText(textG)
 * ------------------------------
 * Loads plain text into a grid
 * Note length of text has to be multiple of 
 * Length of key, otherwise need to pad
 */
void loadPlainText(Grid<char> &textG, string text, string key) {
  // should probably convert everything to lower case
  int distance = text.length() % key.length();
  //cout << distance << endl;
  if (distance != 0) {
    while (true) {
      text = text + "~";	// pad
      //cout << text << endl;
      if ((text.length() % key.length()) == 0) break;
    }
  }

  //cout << text.length() << endl;
  int row = text.length() / key.length();
  int col = key.length();

  textG.resize(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      textG[i][j] = text[i*col+j];

  }
  }
}

int findIndex(const Vector<int> &order, int value) {
  int result = 0;
  for (int i = 0; i < order.size(); i++) {
    if (order[i] == value) return i;
  }

  return result;
}

string printColum(const Grid<char> &textG, int col) {
  string result;
  for (int i = 0; i < textG.numRows(); i++) {
    result = result + textG[i][col];
  }

  return result;
}
