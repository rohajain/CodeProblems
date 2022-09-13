#include <bits/stdc++.h>
 
using namespace std;
 

int main(){
    int n; cin >> n;
    int c; cin >> c;
    vector<int> h(n);
 
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
 
    //dp[i] gives the minimum possible cost to reach ith stone
    //Initialize dp[i] with infinity for all i
    vector<int> dp(n, INT_MAX);
    
    //Base Cases
    //To reach 0th stone we dont need to jump from any cells so total cost is 0
    //To reach 1st stone we can jump from 0th cell with total cost = abs(h[1] - h[0])
    dp[0] = 0;
    dp[1] = ((h[1] - h[0])*(h[1] - h[0]))+c;
 
    //Iterate from 2 to (n -1)th stone in a bottom up manner
    for(int i = 2; i < n; i++){
       
       //ith stone can be reached either from (i - 1)th stone or (i - 2)th stone
       int minC = INT_MAX;
       for(int j=i-1;j>=0;j--)
       {
           minC = min(dp[j]+(((h[i] - h[j])*(h[i] - h[j]))+c),minC);
           //cout << minC << " " << j;
       }
        dp[i] = minC;
    }
    
    //Print cost to reach (n -1)th stone
    cout << dp[n - 1];
    return 0;
}