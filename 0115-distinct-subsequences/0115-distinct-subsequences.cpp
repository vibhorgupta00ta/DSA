class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s,string &t,int i,int j){
        if(j>=t.size()) return 1;
        if(i>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            dp[i][j] = solve(s,t,i+1,j+1) + solve(s,t,i+1,j);
        }
        else dp[i][j] = solve(s,t,i+1,j);
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        dp=vector<vector<int>>(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(s,t,0,0);
    }
};