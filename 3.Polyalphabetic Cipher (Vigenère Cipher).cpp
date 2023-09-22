#include <bits/stdc++.h>
using namespace std;

string stringEncryption(string str, string key) {
    string encryptedText = "";
    int len = str.size();

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
        	// plain text char is upper or lower
            char base = isupper(str[i]) ? 'A' : 'a';
            // this will make this algo capable with any length of key
            char keyShift = isupper(key[i % key.size()]) ? 'A' : 'a';
            // p = str[i] - base
            // k = key[i % key.size()] - keyShift
            // c = (p+k)%26
            char encryptedChar = static_cast<char>((str[i] - base + key[i % key.size()] - keyShift) % 26 + base);
            encryptedText += encryptedChar;
        } else {
            encryptedText += str[i];
        }
    }

    return encryptedText;
}

string stringDecryption(string str, string key) {
    string decryptedText = "";
    int len = str.size();

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            char base = isupper(str[i]) ? 'A' : 'a';
            char keyShift = isupper(key[i % key.size()]) ? 'A' : 'a';
            
			char decryptedChar = static_cast<char>((str[i] - base - key[i % key.size()] + keyShift + 26) % 26 + base);
            decryptedText += decryptedChar;
        } else {
            decryptedText += str[i];
        }
    }

    return decryptedText;
}

int main() {
    string inputStr;
    cout << "Enter a string: ";
    getline(cin, inputStr);

    string key;
    cout << "Enter a key string : ";
    getline(cin, key);

    string encryptedString = stringEncryption(inputStr, key);
    cout << "Encrypted message: " << encryptedString << endl;

    string decryptedString = stringDecryption(encryptedString, key);
    cout << "Decrypted message: " << decryptedString << endl;

    return 0;
}

