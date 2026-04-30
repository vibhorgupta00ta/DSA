#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    bool cycle(int r,int c,int p_r,int p_c,vector<vector<char>>&grid,vector<vector<bool>>&vis){
        if(vis[r][c]) return true;
        vis[r][c]=true;
        for(auto it:dir){
            int n_r=r+it[0];
            int n_c=c+it[1];
            
            if(n_r>=0 && n_r<n && n_c>=0 && n_c<m && grid[n_r][n_c]==grid[r][c]){
                if(n_r==p_r && n_c==p_c) continue;
                if(cycle(n_r,n_c,r,c,grid,vis)) return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && cycle(i,j,i,j,grid,vis)) return true;
            }
        }
        return false;
    }
};