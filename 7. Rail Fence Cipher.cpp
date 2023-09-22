//
///*
//zzzzzzzzzz    uuu       uuu    lll          pppppppp        eeeeeeee
//zzzzzzzzzz    uuu       uuu    lll          ppp    ppp      eeeeeeee
//       zzz    uuu       uuu    lll          ppp      ppp    eee
//     zzz      uuu       uuu    lll          ppp       ppp   eee
//    zzz       uuu       uuu    lll          ppp      ppp    eeeeeeee
//   zzz        uuu       uuu    lll          ppp    ppp      eeeeeeee
//  zzz         uuu       uuu    lll          pppppppp        eee
//zzz            uuu     uuu     lll          ppp             eee
//zzzzzzzzzz      uuu   uuu      lllllllll    ppp             eeeeeeee
//zzzzzzzzzz         uuu         lllllllll    ppp             eeeeeeee
//*/
//
//
//#include <bits/stdc++.h>
//using namespace std;
//
//string encryption(string s, int numRows) {
//
//    if (numRows == 1) return s;
//    if(numRows>=s.length()) return s;
//
//    string ans;
//    int n = s.size();
//    int looplen = 2 * numRows - 2;
//
//    for (int i = 0; i < numRows; i++) {
//        for (int j = 0; j + i < n; j += looplen) {
//            ans += s[j + i];
//            if (i != 0 && i != numRows - 1 && j + looplen - i < n)
//                ans += s[j + looplen - i];
//        }
//    }
//    return ans;
//}
//string decryption(string s, int numRows) {
//    if (numRows == 1 || numRows >= s.length()) return s;
//
//    string ans;
//    int n = s.size();
//    int looplen = 2 * numRows - 2;
//
//    for (int i = 0; i < numRows; i++) {
//        for (int j = 0; j + i < n; j += looplen) {
//            ans += s[j + i];
//
//            if (i != 0 && i != numRows - 1 && j + looplen - i < n)
//                ans += s[j + looplen - i];
//        }
//    }
//
//    int current_pos = 0;
//    string decrypted_text;
//
//    for (int i = 0; i < numRows; i++) {
//        for (int j = 0; j + i < n; j += looplen) {
//            decrypted_text += ans[current_pos++];
//            
//            if (i != 0 && i != numRows - 1 && j + looplen - i < n)
//                decrypted_text += ans[current_pos++];
//        }
//    }
//
//    return decrypted_text;
//}
//
//int main(){
//	string plainText,cipherText;
//	int key;
//	
//	cout<<"Enter your Text(Here) " ;
//	getline(cin,plainText);
//	
//	cout<<"Enter your Key " ;
//	cin>>key;
//	
//	cipherText = encryption(plainText,key);
//	cout<<cipherText<<endl;
//	
//	plainText = decryption(cipherText,key);
//	cout<<plainText;
//	
//}
//
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string encryptRailFence(string plaintext, int rails) {
    vector<string> fence(rails, "");
    int rail = 0;
    bool directionDown = true;

    for (char c : plaintext) {
        fence[rail] += c;
        if (rail == 0) {
            directionDown = true;
        } else if (rail == rails - 1) {
            directionDown = false;
        }

        if (directionDown) {
            rail++;
        } else {
            rail--;
        }
    }

    string ciphertext;
    for (const string &railStr : fence) {
        ciphertext += railStr;
    }

    return ciphertext;
}

string decryptRailFence(string ciphertext, int rails) {
    vector<string> fence(rails, "");
    int rail = 0;
    bool directionDown = true;

    for (char c : ciphertext) {
        fence[rail] += ' '; // Fill in spaces as placeholders
        if (rail == 0) {
            directionDown = true;
        } else if (rail == rails - 1) {
            directionDown = false;
        }

        if (directionDown) {
            rail++;
        } else {
            rail--;
        }
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < fence[i].size(); j++) {
            if (fence[i][j] == ' ') {
                fence[i][j] = ciphertext[index++];
            }
        }
    }

    rail = 0;
    directionDown = true;
    string plaintext;
    
    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext += fence[rail][0];
        fence[rail].erase(fence[rail].begin());
        if (rail == 0) {
            directionDown = true;
        } else if (rail == rails - 1) {
            directionDown = false;
        }

        if (directionDown) {
            rail++;
        } else {
            rail--;
        }
    }

    return plaintext;
}

int main() {
    string plaintext, ciphertext, decryptedText;
    int rails;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    cout << "Enter the number of rails: ";
    cin >> rails;

    ciphertext = encryptRailFence(plaintext, rails);
    decryptedText = decryptRailFence(ciphertext, rails);

    cout << "Encrypted ciphertext: " << ciphertext << endl;
    cout << "Decrypted plaintext: " << decryptedText << endl;

    return 0;
}


