#include <iostream>
#include <string>
using namespace std;

string vernerEncrypt(const string &plaintext, const string &key) {
    string ciphertext = "";
    int keyLength = key.length();

    for (int i = 0; i < plaintext.length(); ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength];

        int plainNum = static_cast<int>(plainChar) - 'A';
        int keyNum = static_cast<int>(keyChar) - 'A';
        
        int encryptedNum = (plainNum ^ keyNum);
        if (encryptedNum >= 26)
            encryptedNum -= 26;

        char encryptedChar = static_cast<char>(encryptedNum + 'A');
        ciphertext += encryptedChar;
    }

    return ciphertext;
}

string vernerDecrypt(const string &ciphertext, const string &key) {
    string decryptedText = "";
    int keyLength = key.length();

    for (int i = 0; i < ciphertext.length(); ++i) {
        char encryptedChar = ciphertext[i];
        char keyChar = key[i % keyLength];

        int encryptedNum = static_cast<int>(encryptedChar) - 'A';
        int keyNum = static_cast<int>(keyChar) - 'A';
        
        int decryptedNum = (encryptedNum ^ keyNum);
        if (decryptedNum < 0)
            decryptedNum += 26;

        char decryptedChar = static_cast<char>(decryptedNum + 'A');
        decryptedText += decryptedChar;
    }

    return decryptedText;
}

int main() {
    string inputStr;
    cout << "Enter a string: ";
    getline(cin, inputStr);

    string key;
    cout << "Enter a key: ";
    getline(cin, key);
    
    string encryptedString = vernerEncrypt(inputStr, key);
    cout << "Encrypted message: " << encryptedString << endl;

    string decryptedString = vernerDecrypt(encryptedString, key);
    cout << "Decrypted message: " << decryptedString << endl;

    return 0;
}

