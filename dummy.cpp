#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // for reverse function

using namespace std;

int main() {
    int size, numStatements;
    
    cout << "Enter the size of integers: ";
    cin >> size;
    
    cout << "Enter the number of statements: ";
    cin >> numStatements;

    vector<vector<char>> store(numStatements, vector<char>(2 * size));

    cout << "2D Vector created with dimensions " << numStatements << " x " << 2 * size << endl;

    for(int i = 0; i < numStatements; i++) {
        string str;
        cin >> str;
        string str1 =str;
        // Reverse the string using the reverse function
        reverse(str1.begin(), str1.end());
        
        // Concatenate the reversed string to the original
        str += str1;

        // Copy the characters to the 2D vector
        for(int j = 0; j < 2 * size; j++) {
            store[i][j] = str[j];
        }
    }

    // Print the contents of the 2D vector for verification
    for(int i = 0; i < numStatements; i++) {
        for(int j = 0; j < 2 * size; j++) {
            cout << store[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

