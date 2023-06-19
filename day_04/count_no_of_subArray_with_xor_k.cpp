#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++; // {0,1}
    int cnt = 0;
    for(int i = 0;i<arr.size();i++){
        xr = xr ^ arr[i];
        // b
        int y = xr ^ x;
        cnt += mpp[y];
        mpp[xr]++;
    }
    return cnt;
}