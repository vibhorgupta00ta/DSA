//MAXIMAUM PATH SCORE IN A GRID
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m, n, klim;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, int cost) {
        if (i >= m || j >= n) return -1e9;
        int val = grid[i][j];
        int score = (val == 1 ? 1 : (val == 2 ? 2 : 0));
        int extra = (val == 0 ? 0 : 1);
        int newcost = cost + extra;
        if (newcost > klim) return -1e9;
        if (i == m - 1 && j == n - 1) return score;
        if (dp[i][j][newcost] != -1) return dp[i][j][newcost];
        int r = solve(i, j + 1, newcost);
        int d = solve(i + 1, j, newcost);
        int res = score + max(d, r);
        dp[i][j][newcost] = res;
        return res;
    }
    int maxPathScore(vector<vector<int>>& gridInput, int k) {
        grid = gridInput;
        m = grid.size();
        n = grid[0].size();
        klim = k;
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(klim + 1, -1)));
        int ans = solve(0, 0, 0);
        return ans < 0 ? -1 : ans;
    }
};
