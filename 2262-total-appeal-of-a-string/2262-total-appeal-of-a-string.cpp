class Solution {
public:
    long long appealSum(string s) {
        vector<int> mpp[26];
        int n = s.size();
        for(int i = 0; i < n; i++)
            mpp[s[i] - 'a'].push_back(i);
        long long ans = 0;
        for(int i = 0; i < 26; i++) {
            if(mpp[i].empty())
                continue;
            int prev = -1;
            for(int j = 1; j < mpp[i].size(); j++) {
                int left = mpp[i][j - 1] - prev;
                int right = n - mpp[i][j - 1];
                ans += 1LL * left * right;
                prev = mpp[i][j - 1];
            }
            int left = mpp[i].back() - prev;
            int right = n - mpp[i].back();

            ans += 1LL * left * right;
        }

        return ans;
    }
};