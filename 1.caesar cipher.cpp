
/*
zzzzzzzzzz    uuu       uuu    lll          pppppppp        eeeeeeee
zzzzzzzzzz    uuu       uuu    lll          ppp    ppp      eeeeeeee
       zzz    uuu       uuu    lll          ppp      ppp    eee
     zzz      uuu       uuu    lll          ppp       ppp   eee
    zzz       uuu       uuu    lll          ppp      ppp    eeeeeeee
   zzz        uuu       uuu    lll          ppp    ppp      eeeeeeee
  zzz         uuu       uuu    lll          pppppppp        eee
zzz            uuu     uuu     lll          ppp             eee
zzzzzzzzzz      uuu   uuu      lllllllll    ppp             eeeeeeee
zzzzzzzzzz         uuu         lllllllll    ppp             eeeeeeee
*/

//classica; encryption technique
//1)caesar cipher

#include <bits/stdc++.h>
using namespace std;

string caesarCipherEncrypt(string &text, int shift) {
    string encryptedText = "";
    
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            encryptedText += static_cast<char>((c - base + shift + 26) % 26 + base);
        } else {
            encryptedText += c;
        }
    }
    
    return encryptedText;
}

string caesarCipherDecrypt(string &text, int shift) {
    return caesarCipherEncrypt(text, -shift);
}

int main() {
    string plaintext, encryptedText, decryptedText;
    int key;

    // Input
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the shift key value (integer): ";
    cin >> key;

    // Encryption
    encryptedText = caesarCipherEncrypt(plaintext, key);
    cout << "Encrypted text: " << encryptedText << endl;

    // Decryption
    decryptedText = caesarCipherDecrypt(encryptedText, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}

