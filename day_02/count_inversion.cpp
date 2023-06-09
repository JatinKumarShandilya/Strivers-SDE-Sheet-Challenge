#include <bits/stdc++.h> 
using namespace std;
long long merge(long long *arr,int lo,int mid,int hi){
    int left = lo;
    int right = mid+1;
    long long cnt = 0;

    vector<long long> temp;
    while(left<=mid && right <= hi){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            
            temp.push_back(arr[right]);
            cnt += mid-left+1;
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=hi){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=lo;i<=hi;i++){
        arr[i] = temp[i-lo];
    }
    return cnt;
}

long long mS(long long *arr,int lo,int hi){
    long long cnt = 0;
    if(lo >= hi)    return cnt ;
    int mid = (lo+hi)/2;
    cnt += mS(arr,lo,mid);
    cnt += mS(arr,mid+1,hi);
    cnt += merge(arr,lo,mid,hi);
    return cnt;
}
long long getInversions(long long *arr, int n){
    return mS(arr,0,n-1);
}