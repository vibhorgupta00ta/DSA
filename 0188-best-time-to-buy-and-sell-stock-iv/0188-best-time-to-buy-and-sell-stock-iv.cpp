class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(int i,int buy,int cap,vector<int>&prices){
        if(i==prices.size() || cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        int profit = 0;
        if(buy){
            int take = -prices[i] + solve(i+1,0,cap,prices);
            int skip = solve(i+1,1,cap,prices);
            profit = max(take,skip);
        }
        else{
            int sell = prices[i] + solve(i+1,1,cap-1,prices);
            int skip = solve(i+1,0,cap,prices);
            profit = max(sell,skip);
        }
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        dp=vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices);
    }
};