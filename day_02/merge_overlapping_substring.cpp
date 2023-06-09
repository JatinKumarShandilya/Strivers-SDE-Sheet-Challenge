#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergedInterval;
    if(intervals.size()  == 0)  return mergedInterval;

    sort(intervals.begin(),intervals.end());

    vector<int> tempInterval = intervals[0];

    for(auto it : intervals){
        if(it[0] <= tempInterval[1]){
            tempInterval[1] = max(it[1],tempInterval[1]);
        }
        else{
            mergedInterval.push_back(tempInterval);
            tempInterval = it;
        }
    }
    mergedInterval.push_back(tempInterval);
    return mergedInterval;
}
