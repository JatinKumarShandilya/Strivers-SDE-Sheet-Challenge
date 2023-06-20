#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int mini = prices[0]; 
    int maxProfit = 0;
    int profit = 0;
    for(int i= 0 ; i<n ; i++){
        profit = prices[i] - mini;
        maxProfit = max(profit,maxProfit);
        mini = min(mini, prices[i]);
    }  
    return maxProfit;
}