#include <bits/stdc++.h>

using namespace std;

int solve(int A) {
    long long int givenN = A;
    int primes[100000];
    for(int i=0;i<100000;i++){
        primes[i] = 1;
    }
    for(int p=2;p*p<100000;p++){
        if(primes[p]){
            for(int j=p;j*p<100000;j++){
                primes[j*p]=0;
            }
        }
    }
    vector<int> allP;
    for(int p=2;p<100000;p++){
        if(primes[p])
            allP.push_back(p);
    }
    int cnt=0;
    int sum=0;
    int mod = (int)1e9+7;
    if(A>=2){
        sum+=1;
        cnt++;
    }
    if(A>=4){
        sum+=3;
        cnt++;
    }
    // cout << "-=-==" << endl;
    for(int i=1;i<allP.size();i++){
        // cout << allP[i] << endl;
        int k=allP[i];
        while(k<=A){
            // cout << k << " ";
            cnt++;
            sum+=(k-1);
            sum%=mod;
            k*=allP[i];
        }
        k=allP[i];
        while(2*k<=A){
            // cout << 2*k << " ";
            cnt++;
            sum+=(2*k-1);
            sum%=mod;
            k*=allP[i];
        }
    }
    // cout << cnt << endl;
    for(int num=100000;num<=A;num++){
        int div = 0;
        for(int i=0;i<allP.size();i++){
            if(num%allP[i]==0){
                div=1;
                break;
            }
        }
        if(!div){
            sum+=(num-1);
            cnt++;
            sum%=mod;
        }
        div = 0;
        if(num%2==0){
            int temp=num/2;
            for(int i=0;i<allP.size();i++){
                if(temp%allP[i]==0){
                    div=1;
                    break;
                }
            }
            if(!div){
                sum+=(num-1);
                cnt++;
                sum%=mod;
            }
        }
    }
    cnt++;
    sum+=A;
    sum%=mod;
    sum-=cnt;
    sum+=mod;
    sum%=mod;
    return sum;
}


int main(){
    while(1){
        int n;
        cin >> n;
    cout << solve(n) << endl;
    }
}