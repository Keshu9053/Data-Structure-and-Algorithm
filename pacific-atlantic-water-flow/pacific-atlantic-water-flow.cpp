class Solution {
public:
    void bfs(vector<vector<int>>& vis, vector<vector<int>>& arr,queue<pair<int,int>>q) {
        int n = arr.size();
        int m = arr[0].size();

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int delrow[] = {1,0,-1,0};
            int delcol[] = {0,-1,0,1};
            for(int i = 0;i<4;++i) {
                int r = row + delrow[i];
                int c = col + delcol[i];
                if(r<n && r>=0 && c<m && c>=0 && vis[r][c] != 1 && arr[row][col] <= arr[r][c]){
                    vis[r][c] = 1;
                    q.push({r,c});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> atlantic(m, vector<int> (n, 0));
        vector<vector<int>> pacific(m, vector<int>(n,0));
        vector<vector<int>> ans;    
        queue<pair<int, int>> q_pacific;
        queue<pair<int, int>> q_atlantic;
        
        // for pacific ocean1
        for(int i=0;i<n;i++){
            pacific[0][i] = 1;
            q_pacific.push({0, i});
            atlantic[m-1][i] = 1;   
            q_atlantic.push({m-1, i});
        }

        for(int i=0;i<m;i++){
            pacific[i][0] = 1;
            q_pacific.push({i, 0});
            atlantic[i][n-1] = 1;
            q_atlantic.push({i, n-1});
        }
        
        bfs(atlantic,arr,q_atlantic);
        bfs(pacific,arr,q_pacific);        

        // for finding answer
    
        for(int i = 0 ; i<m ; ++i) {
            for(int j = 0 ; j<n ; ++j) {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) {
                   ans.push_back({i,j});                   
                }
            }
        }
        return ans;
    }
}; 