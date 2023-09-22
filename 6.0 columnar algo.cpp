#include <bits/stdc++.h>
using namespace std;

string encryption(string str, int key) {
    string ans;
    for (int i = 0; i < key; i++) {
        int k = i;
        while (k < str.size()) {
            ans += str[k];
            k += key;
        }
    }
    return ans;
}

string decryption(string str, int key) {
    int len = str.size();
    int rows = key;
    int cols = len / key;
    int extra = len % key;

    if (extra != 0) {
        cols++;
    }

    int full_rows = key - extra;

    string ans(len, ' ');

    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i < full_rows) || (i == full_rows && j < extra)) {
                ans[i + j * rows] = str[index++];
            } else {
                ans[i + j * rows] = ' ';
            }
        }
    }

    return ans;
}

int main() {
    string str;
    int key;
    cout << "Enter your string: ";
    getline(cin, str);
    cout << "Enter your integer key: ";
    cin >> key;

    string enc = encryption(str, key);
    cout << "\nEncrypted key: " << enc;

    string dec = decryption(enc, key);
    cout << "\nDecrypted key: " << dec;

    return 0;
}

