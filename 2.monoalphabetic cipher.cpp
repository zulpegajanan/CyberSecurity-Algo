//#include <iostream>
//#include <string>
//using namespace std;
//
//char normalChar[]
//    = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
//        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
//        's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
//
//char codedChar[]
//    = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
//        'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K',
//        'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
//
//string stringEncryption(string s) {
//    string encryptedString = "";
//
//    for (int i = 0; i < s.length(); i++) {
//        for (int j = 0; j < 26; j++) {
//            if (s[i] == normalChar[j]) {
//                encryptedString += codedChar[j];
//                break;
//            }
//
//            if (s[i] < 'a' || s[i] > 'z') {
//                encryptedString += s[i];
//                break;
//            }
//        }
//    }
//
//    return encryptedString;
//}
//
//string stringDecryption(string s) {
//    string decryptedString = "";
//
//    for (int i = 0; i < s.length(); i++) {
//        for (int j = 0; j < 26; j++) {
//            if (s[i] == codedChar[j]) {
//                decryptedString += normalChar[j];
//                break;
//            }
//
//            if (s[i] < 'A' || s[i] > 'Z') {
//                decryptedString += s[i];
//                break;
//            }
//        }
//    }
//
//    return decryptedString;
//}
//
//int main() {
//    string str;
//    cout << "Enter a string: ";
//    getline(cin, str);
//
//    string encryptedString = stringEncryption(str);
//    cout << "Encrypted message: " << encryptedString << endl;
//
//    string decryptedString = stringDecryption(encryptedString);
//    cout << "Decrypted message: " << decryptedString << endl;
//
//    return 0;
//}




#include <iostream>
#include <string>
#include <map>

using namespace std;

string encrypt(string pt, map<char, char>& key) {
    string ct = "";
    for (char c : pt) {
        if (isalpha(c)) {
            char temp = key[tolower(c)];
            if (isupper(c)) {
                temp = toupper(temp);
            }
            ct += temp;
        } else {
            ct += c;
        }
    }
    return ct;
}

string decrypt(string ct, map<char, char>& kay) {
    string pt = "";
    for (char c : ct) {
        if (isalpha(c)) {
            char temp;
            for (const auto& pair : kay) {
                if (pair.second == tolower(c)) {
                    temp = pair.first;
                    break;
                }
            }
            if (isupper(c)) {
                temp = toupper(temp);
            }
            pt += temp;
        } else {
            pt += c;
        }
    }
    return pt;
}

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string key = "qwertyuioplkjhgfdsazxcvbnm";

    if (alphabet.length() != key.length()) {
        cout << "Error: Key length must be the same as the alphabet length." << endl;
        return 1;
    }

    map<char, char> mp;

    for (size_t i = 0; i < alphabet.length(); i++) {
        mp[alphabet[i]] = key[i];
    }

    string pt;
    cout << "Enter a message to encrypt: ";
    getline(cin, pt);

    string ct = encrypt(pt, mp);

    cout << "Ciphertext: " << ct << endl;

    string decryptedText = decrypt(ct, mp);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

