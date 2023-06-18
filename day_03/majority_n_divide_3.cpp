#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int elem1 = -1, elem2 = -1, cnt1 = 0, cnt2 = 0, n = size(nums);

        for(int val : nums){
            if( cnt1 == 0 and val != elem2 ) {
                elem1 = val;
                cnt1 = 1;
            }
            else if( cnt2 == 0 and val != elem1 ) {
                elem2 = val;
                cnt2 = 1; 
            }
            else if( elem1 == val ) cnt1++;
            else if( elem2 == val ) cnt2++;
            else cnt1--, cnt2--;
        }
        
        cnt1 = 0, cnt2 = 0;
        vector <int> res;
        for( int val : nums ){
            if( val == elem1 ) cnt1++;
            else if( val == elem2 ) cnt2++; 
        }
        if( cnt1 > n/3 ) res.push_back( elem1 );
        if( cnt2 > n/3 ) res.push_back( elem2 );
        return res;
    }

};