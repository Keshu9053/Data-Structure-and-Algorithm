
class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& vis
                ,vector<vector<char>>& mat,int delrow[], int delcol[]){
                    int n = mat.size();
                    int m = mat[0].size();
                    vis[r][c] = 1;
                    for(int k=0;k<4;++k){
                        int nr = delrow[k] + r;
                        int nc = delcol[k] + c;
                        if(nr>=0 && nr<n && nc>=0 && nc<m
                            && !vis[nr][nc] && mat[nr][nc]=='O')
                            dfs(nr,nc,vis,mat,delrow,delcol);
                    }
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int delrow[] = {1,0,-1,0};
        int delcol[] = {0,-1,0,1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        // traverse 1 and last row
        for(int i=0;i<m;++i){
            if(mat[0][i] == 'O' && !vis[0][i])
                dfs(0,i,vis,mat,delrow,delcol);

            if(mat[n-1][i] == 'O' && !vis[n-1][i]) 
                dfs(n-1,i,vis,mat,delrow,delcol);
        }

        for(int i=0;i<n;++i){
            if(mat[i][0] == 'O' && !vis[i][0])
                dfs(i,0,vis,mat,delrow,delcol);

            if(mat[i][m-1] == 'O' && !vis[i][m-1]) 
                dfs(i,m-1,vis,mat,delrow,delcol);
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
            }
        }
    }
};