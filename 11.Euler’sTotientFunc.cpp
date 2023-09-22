
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

vector<int> countCoprimes(int n){
    vector<int> vect;
    for(int i = 1; i < n; i++){
        if(__gcd(i, n) == 1){
            vect.push_back(i);
        }
    }
    return vect;
}

int main(){
	cout<<"enter your number : ";
	int num;
	cin>>num;
    vector<int> vect = countCoprimes(num);
    
    cout<<"Euler's Totient Function Value for "<<num<<" : "<<vect.size()<<endl;
    for(int i=0;i<vect.size();i++){
    	cout<<vect[i];
    	if(i!=vect.size()-1){
    		cout<<"==>";
		}
	}
    
    
    return 0;
}

