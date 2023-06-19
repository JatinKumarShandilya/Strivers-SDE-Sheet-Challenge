#include <bits/stdc++.h>
using namespace std;
int LongestSubsetWithZeroSum(vector < int > arr) {

  unordered_map<int,int> mpp;
  int maxi = 0;
  int sum = 0;
  for(int i=0;i<arr.size();i++){
    sum += arr[i];
    if(sum == 0){
      maxi = i + 1;
    }
    else{
      if(mpp.find(sum) != mpp.end()){
        maxi = max(maxi, i - mpp[sum]);
      }
      else{
        mpp[sum] = i;
      }
    }
  }
  return maxi;

}



// brute force                TC ~ O(n^3)

// len = 0;
// for(int i = 0; i < n ; i++){
//   for(int j = i; j < n;j++){
//     s = 0;
//     for(k=i;k<=j;k++)
//       s+= a[k];
//     if(s==k)  len = max(len,j-i+1);
//   }
// }
// print(len)
