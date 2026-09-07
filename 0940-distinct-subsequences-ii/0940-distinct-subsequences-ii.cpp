class Solution {
public:

    //MEMORY LIMIT EXCEEDED............
    // set<string>st;
    // void solve(string &s,int i,string curr){
    //     if(i==s.size()){
    //         st.insert(curr);
    //         return;
    //     }
    //     solve(s,i+1,curr+s[i]);
    //     solve(s,i+1,curr);
    // }
    // int distinctSubseqII(string s) {
    //     string curr;
    //     solve(s,0,curr);
    //     return st.size()-1;
    // }
    int distinctSubseqII(string s) {
        int n=s.size();
        const int MOD=1e9+7;
        vector<long long>dp(n+1,0);
        vector<int>last(26,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%MOD;
            if(last[s[i-1]-'a']){
                dp[i]=(2*dp[i-1]-dp[last[s[i-1]-'a']-1]+MOD)%MOD;
            }
            last[s[i-1]-'a'] = i;
        }
        return (dp[n]-1+MOD)%MOD;
    }
};