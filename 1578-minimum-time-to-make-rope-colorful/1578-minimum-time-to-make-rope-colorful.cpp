class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0;
        int n=colors.size();
        int ans=0;
        int res=0;
        while(i<n){
            int j=i;
            int val=0;
            while(j<n && colors[j]==colors[i]){
                val=max(val,neededTime[j]);
                ans+=neededTime[j];
                j++;
            }
            ans-=val;
            i=j;
        }
        return ans;
    }
};