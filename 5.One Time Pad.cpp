
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

#include <iostream>
#include <string>
using namespace std;

string gen_random(const int len) {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

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
    key=gen_random(inputStr.size());
    cout<<"Key is "<<key<<endl;
    
    string encryptedString = vernerEncrypt(inputStr, key);
    cout << "Encrypted message: " << encryptedString << endl;

    string decryptedString = vernerDecrypt(encryptedString, key);
    cout << "Decrypted message: " << decryptedString << endl;

    return 0;
}

