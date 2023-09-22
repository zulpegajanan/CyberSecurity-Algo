
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


#include <bits/stdc++.h>
using namespace std;

// return pow(base,pow) % mod 
int solve(int base, int pow, int mod){
	int result = 1;
    while (pow > 0) {
        if (pow % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        pow /= 2;
    }
    return result;
}

// check num are co-prime
bool isCoprime(int a, int b){
	if(__gcd(a,b) == 1) return 1;
	return 0;
}

// isPrime
bool isPrime(int n) {
    if (n <= 1) return false; 
    if (n <= 3) return true; 
    if (n % 2 == 0 || n % 3 == 0) return false;
    // Check for prime using 6k +/- 1 rule.
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) { 
            return false;
        }
    }
    
    return true;
}

// d*e = 1 % phn
// d = ( ( phn * i ) + 1) / e
// 1 >= 1

int calD(int e, int phn){
	int i=1;
	while(1){
		int d = (phn*i + 1)/e;
		int E = (phn*i + 1)/d;
		
		if(e==E) return d;
		else i++;
	}
	return -1;
}

int encryption(int P, int e ,int n){
	return solve(P,e,n);
}

int decryption(int C, int d, int n){
	return solve(C,d,n);
}



int main(){
	// step 01
	int p,q;
	cout<<"Enter first Prime Number p : ";
	cin>>p;
	if(!isPrime(p)){
		cout<<"you need to enter prime number";
		cout<<"check it !...";
		return 0;
	}
	
	cout<<"Enter second Prime Number q: ";
	cin>>q;
	if(!isPrime(q)){
		cout<<"you need to enter prime number";
		cout<<"check it !...";
		return 0;
	}
	
	if(p==q){
		cout<<"both number should be different";
		return 0;
	}
	
	// step 02
	int n = p*q;
	cout<<"n = "<<n;
	
	// step 03
	int phn = (p-1)*(q-1);
	
	// step 04
	cout<<"select e such that 1 < e < phn and  coprime with phn";
	int e;
	cin>>e;
	if(__gcd(phn,e)!=1 || e<=1 || e>=phn) {
		cout<<"check it again...";
		return 0;
	}
	
	// step 05
	int d = calD(e,phn);
	cout<<"d = " << d<<endl;
	
	// step 06
	cout<<"public key = {"<< e <<","<<n<<"}"<<endl;
	cout<<"private key = {"<< d <<","<<n<<"}"<<endl;
	
	// step 07
	int C,P;
	cout<<"Enter your plain text (int) :";
	cin>>P;
	
	// step 08
	cout<<"-----------------------------";
	C = encryption(P,e,n);
	cout<<"encrypted value = "<<C<<endl;
	
	// step 09
	P = encryption(C,d,n);
	cout<<"decrypted value = "<<P<<endl;
	
	return 0;
}

