class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int vis[n][m];
        int countFresh = 0;

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else vis[i][j]=0;

                if(grid[i][j]==1) countFresh++;
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int cnt=0;
        int tm=0;
        // BFS Traversal
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm,t);
            // Traversing 4 directions
            for(int k=0;k<4;++k){
                int nrow = r+delrow[k];
                int ncol = c+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                    && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                        vis[nrow][ncol] =2;
                        cnt++;
                        q.push({{nrow,ncol},t + 1});
                    }
            }
        }
        if(cnt != countFresh) return -1;
        return tm;
    }
};