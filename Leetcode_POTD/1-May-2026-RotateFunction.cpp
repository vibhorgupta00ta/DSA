#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        long sum=0;
        long first=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            first+=(long)i*nums[i];
        }
        long ans=first;
        for(int i=1;i<n;i++){
            first=first+sum-(long)n*nums[n-i];
            ans=max(ans,first);
        }
        return (int)ans;
    }
};