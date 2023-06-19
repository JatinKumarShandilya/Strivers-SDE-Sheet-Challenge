#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int num = nums[i];
            int moreNeeded = target - num;
            if(mpp.find(moreNeeded) != mpp.end()){
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return {-1,-1};
    }
};

// #include <bits/stdc++.h> 
// vector<vector<int>> pairSum(vector<int> &arr, int s){
//    vector<vector<int> > ans;
   
//     for(int i=0;i<arr.size();i++){
//         for(int j=i+1; j<arr.size(); j++){
//             if(arr[i] + arr[j] == s)
//             {
//                 vector<int> temp;
//                 temp.push_back(min(arr[i], arr[j]));
//                 temp.push_back(max(arr[i], arr[j]));
//                 ans.push_back(temp);
//             }
//         }
//     }
//     sort(ans.begin(), ans.end());
//     return ans;
// }