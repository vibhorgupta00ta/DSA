class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        const int INF=1e9;
        if(n==1 && m==1) return grid[0][0];
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(4,vector<int>(k+1,INF))));

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        using state = tuple<int,int,int,int,int>;
        priority_queue<state,vector<state>,greater<state>>pq;

        for(int dir=0;dir<4;dir++){
            int ni = dr[dir];
            int nj = dc[dir];
            if(ni<0 || nj<0 || ni>=n || nj>=m) continue;

            int cost = grid[0][0] + grid[ni][nj];
            dp[ni][nj][dir][0]=cost;

            pq.push({cost,ni,nj,dir,0});
        }

        while(!pq.empty()){
            auto[cost,i,j,dir,turns] = pq.top();
            pq.pop();
            if(i==n-1 && j==m-1) return cost;
            for(int ndir=0;ndir<4;ndir++){
                int ni= i + dr[ndir];
                int nj= j + dc[ndir];

                if(ni<0 || nj <0 || ni>=n || nj>=m) continue;
                int newturn = turns + (dir!=ndir);
                if(newturn > k) continue;

                int newcost = cost + grid[ni][nj];

                if(newcost < dp[ni][nj][ndir][newturn]){
                    dp[ni][nj][ndir][newturn] = newcost;
                    pq.push({newcost,ni,nj,ndir,newturn});
                }
            }
        }
        return -1;
    }
};