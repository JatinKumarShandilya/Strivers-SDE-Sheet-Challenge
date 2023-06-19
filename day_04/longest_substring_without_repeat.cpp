#include <bits/stdc++.h> 
using namespace std;
int uniqueSubstrings(string input)
{
    vector<int> mpp(256, -1);

    int left = 0, right = 0;
    int n = input.size();
    int len = 0;
    while(right < n){
        if(mpp[input[right]] != -1) left = max(mpp[input[right]] + 1, left);

        mpp[input[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}


// or


#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
class Solution {
    bool saareOneSeChoteYaBarabarHaiyaNahi(vector<ll> &freq){
    bool koiOneSeBadaHaiKya = false;
    for(auto itr : freq){
        if(itr>1) koiOneSeBadaHaiKya = true;
    }
    if(koiOneSeBadaHaiKya) return false;
    return true;
}
public:
    int lengthOfLongestSubstring(string s) {
        ll lo = 1, hi = min((ll)256, (ll)s.size()), ans = 0;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            vector<ll> frequencyArray(256, 0);
            ll sp = 0, ep = mid-1;
            for(ll i=sp;i<=ep;i++) frequencyArray[s[i]]++;
           
            bool koiSubstringExistKartiHaiKya = false;
            if(saareOneSeChoteYaBarabarHaiyaNahi(frequencyArray)) koiSubstringExistKartiHaiKya=true;
            while(ep<s.size()){
                sp++;
                ep++;
                if(ep>=s.size()) break;
                frequencyArray[s[ep]]++;
                frequencyArray[s[sp-1]]--;
                if(saareOneSeChoteYaBarabarHaiyaNahi(frequencyArray)) koiSubstringExistKartiHaiKya = true;
            }

            if(koiSubstringExistKartiHaiKya){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }

        }
        return ans;
    }
};