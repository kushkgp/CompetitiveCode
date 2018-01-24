#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        vector<int> arr;
        for(int i=0;i<=100;i++){
            arr.push_back(i);
        }
        
        int n,m;
        cin >> n;
        while(n--){
            int j,k;
            cin >> j >> k;
            arr[j]=k;
        }
        cin >> m;
        while(m--){
            int j,k;
            cin >> j >> k;
            arr[j]=k;
        }
        vector<vector<int> > route;
        route.push_back(vector<int>());
        for(int i=1;i<100;i++){
            vector<int> temp;
            for(int j=1;j<=6 && i+j<=100;j++){
                temp.push_back(arr[i+j]);
            }
            route.push_back(temp);
        }
        vector<int> reach(101);
        for(int i=0;i<reach.size();i++){
            reach[i]=-1;
        }
        reach[1]=0;
        deque<int> q;
        q.push_back(1);
        int flag=0;
        while(!q.empty()){
            int crt = q.front();
            q.pop_front();
            for(int i=0;i<route[crt].size();i++){
                if(reach[route[crt][i]]==-1){
                    reach[route[crt][i]] = reach[crt]+1;
                    q.push_back(route[crt][i]);
                }
                if(route[crt][i]==100){
                    cout << reach[crt]+1 << endl;
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(reach[100]==-1)
            cout << -1 << endl;
    }  
    return 0;
}
