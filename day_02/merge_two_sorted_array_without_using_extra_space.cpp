#include <bits/stdc++.h>
using namespace std;
void checkIfGreater(vector<int> &nums1, int left,vector<int> &nums2, int right){
        if(nums1[left] > nums2[right]){
            swap(nums1[left],nums2[right]);
        }
    }
vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
		int len = (n+m);
        int gap = (len/2) + (len%2);
        while(gap>0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                // arr1 and arr2
                if(left <n && right >= n){
                    checkIfGreater(nums1, left, nums2, right-n);
                }
                // arr2 and arr2
                else if(right >= n){
                    checkIfGreater(nums1, left-n, nums2, right-n);
                }
                // arr1 and arr1
                else {
                  checkIfGreater(nums1, left, nums2, right);
                }
                left++;
                right++;
            }
            if (gap == 1)
              break;
            gap = (gap / 2) + (gap % 2);
        }
	}
