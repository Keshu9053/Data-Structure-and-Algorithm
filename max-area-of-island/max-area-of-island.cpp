class Solution {
public:
    int bfs(int i,int j, vector<vector<int>>& vis, vector<vector<int>>& grid ) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 1;
        vis[i][j] = 1;
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[] = {0,-1,0,1};
            int delcol[] = {1,0,-1,0};
            for(int i = 0;i<4;++i) {
                int r = row + delrow[i];
                int c = col + delcol[i];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 1 && vis[r][c] != 1) {
                    count++;
                    q.push({r,c});
                    vis[r][c] = 1;
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int max_area = 0;
        
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    max_area = max(max_area,bfs(i,j,vis,grid));
                }
            }
        }
        return max_area;
    }
};