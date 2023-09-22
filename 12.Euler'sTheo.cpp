
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

int countCoprimes(int n){
    int count =0;
    for(int i = 1; i < n; i++){
        if(__gcd(i, n) == 1){
            count++;
        }
    }
    return count;
}

int main(){
	int x,n;
	cout<<"enter value of X : ";
	cin>>x;
	cout<<"enter value of n : ";
	cin>>n;
	
	if(__gcd(x,n)!=1){
		cout<<"Euler Theorem is not applicable here due to gcd(X,n) != 1";
		return 0;
	}
	
	if(pow(x,countCoprimes(n))%n ==1){
		cout<<" Varified";
	}
	
	cout<<"UnVarified";
	
	
}

