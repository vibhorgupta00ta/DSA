class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=(n/2)-1;
        long long cs=0,ts=0;
        for(int k=0;k<n/2;k++){
            cs+=nums[k];
        }
        for(int k=0;k<n;k++) ts+=nums[k];
        int cnt=0;
        while(i<n){
            if(cs>ts-cs) cnt++;
            cs-=nums[i];
            cs+=nums[(j+1)%n];
            i++;
            j=(j+1)%n;
        }
        return cnt;
    }
};