
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
using namespace std;

// Function to calculate modular exponentiation efficiently
long long int modular_pow(long long int base, long long int exponent, long long int modulus) {
    if (modulus == 1)
        return 0;
    long long int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1; // Equivalent to exponent /= 2
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    long long int p, g, a, b, c, d, x, y, xe, ye, ka, kb, kea, keb;

    // Input from the user
    cout << "Enter a prime number (P): ";
    cin >> p;
    cout << "Enter a number (G): ";
    cin >> g;
    cout << endl;
    cout << "Enter Alice's private number (a): ";
    cin >> a;
    cout << "Enter Bob's private number (b): ";
    cin >> b;
    cout << endl;
    cout << "Enter Eve's selected private number for Bob from Alice (c): ";
    cin >> c;
    cout << "Enter Eve's selected private number for Alice from Bob (d): ";
    cin >> d;
    cout << endl;

    // Calculate and display public keys for Alice and Bob
    x = modular_pow(g, a, p);
    y = modular_pow(g, b, p);
    cout << "Alice published key: " << x << endl;
    cout << "Bob published key: " << y << endl;

    // Calculate and display values that Eve publishes for Alice and Bob
    xe = modular_pow(g, c, p);
    ye = modular_pow(g, d, p);
    cout << "Eve published value for Alice: " << xe << endl;
    cout << "Eve published value for Bob: " << ye << endl;

    // Calculate secret keys for Alice and Bob, and Eve's computed keys
    ka = modular_pow(xe, a, p);
    kea = modular_pow(x, c, p);
    kb = modular_pow(ye, b, p);
    keb = modular_pow(y, d, p);
    cout << "Alice computed (S1): " << ka << endl;
    cout << "Eve computed key for Alice (S1): " << kea << endl;
    cout << "Bob computed (S2): " << kb << endl;
    cout << "Eve computed key for Bob (S2): " << keb << endl;

    return 0;
}


