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
//string encryption(string str,int key){
//	int row = key;
//	int col;
//	if(str.size()%key == 0){
//		col = str.size() / key;
//	}
//	else{
//		col = 1 + str.size() / key;
//	}
//	vector<vector<char>> store(row,vector<char>(col,'*'));
//	
//	int len=0;
//	for(int i=0;i<col;i++){
//		for(int j=0;j<row;j++){
//			store[j][i]=str[len];
//			len++;
//			if(len==str.size()){
//				break;
//			}
//		}
//		if(len==str.size()){
//			break;
//		}
//	}
//	
//	string ans;
//	for(int i=0; i<row ; i++){
//		for(int j=0; j<col;j++){
//			ans+=store[i][j];
//		}
//	}
//	return ans;
//}
//
//string decryption(string str,int key){
//    int col = key;
//	int row;
//	if(str.size()%key == 0){
//		row = str.size() / key;
//	}
//	else{
//		row = 1 + str.size() / key;
//	}
//	vector<vector<char>> store(row,vector<char>(col,'*'));
//	
//	int len=0;
//	for(int i=0;i<col;i++){
//		for(int j=0;j<row;j++){
//			store[j][i]=str[len];
//			len++;
//			if(len==str.size()){
//				break;
//			}
//		}
//		if(len==str.size()){
//			break;
//		}
//	}
//	
//	string ans;
//	for(int i=0; i<row ; i++){
//		for(int j=0; j<col;j++){
//			ans+=store[i][j];
//		}
//	}
//	return ans;
//}
//
//string process(string str){
//    string ans;
//    for(int i=0;i<str.size();i++){
//        if(str[i]!='*'){
//            ans+=str[i];
//        }
//    }
//    return ans;
//}
//int main(){
//	int key;
//	string plaintext;
//	
//	cout<<"Enter Your Plain Text Here :";
//	getline(cin,plaintext);
//	
//	cout<<"Enter Your Key(int) :";
//	cin>>key;
//	
//	cout<<"----------------------"<<endl;
//	
//	string cipherText = encryption(plaintext,key);
//	string cipherText1= process(cipherText);
//	cout<<"Your Cipher Text will be :";
//	cout<<cipherText1<<endl;
//	
//	cout<<"----------------------"<<endl;
//	
//	plaintext = decryption(cipherText,key);
//	plaintext= process(plaintext);
//	cout<<"Your Cipher Text will be :";
//	cout<<plaintext<<endl;
//	
//}
//


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string encrypt(const string &plaintext, const string &key) {
    int keyLength = key.length();
    int textLength = plaintext.length();
    int numRows = ceil(static_cast<double>(textLength) / keyLength);
    char matrix[numRows][keyLength];
    int textIndex = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < keyLength; j++) {
            if (textIndex < textLength) {
                matrix[i][j] = plaintext[textIndex];
                textIndex++;
            } else {
                matrix[i][j] = ' ';
            }
        }
    }
    string ciphertext;
    for (int j = 0; j < keyLength; j++) {
        int col = key.find(key[j]);
        for (int i = 0; i < numRows; i++) {
            ciphertext += matrix[i][col];
        }
    }
    return ciphertext;
}

string decrypt(const string &ciphertext, const string &key) {
    int keyLength = key.length();
    int textLength = ciphertext.length();
    int numRows = ceil(static_cast<double>(textLength) / keyLength);
    int lastRowLength = textLength % keyLength;
    if (lastRowLength == 0) {
        lastRowLength = keyLength;
    }
    char matrix[numRows][keyLength];
    int textIndex = 0;
    for (int j = 0; j < keyLength; j++) {
        int col = key.find(key[j]);
        for (int i = 0; i < numRows; i++) {
            if (i == numRows - 1 && j >= lastRowLength) {
                matrix[i][col] = ' ';
            } else {
                matrix[i][col] = ciphertext[textIndex];
                textIndex++;
            }
        }
    }
    string plaintext;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < keyLength; j++) {
            plaintext += matrix[i][j];
        }
    }
    return plaintext;
}

int main() {
    string plaintext, key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the encryption key: ";
    getline(cin, key);

    string ciphertext = encrypt(plaintext, key);
    cout << "Encrypted Message: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted Message: " << decryptedText << endl;

    return 0;
}

