class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        queue<pair<pair<int,int>,int>> q;
        //put all 0s to queue
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j]==0) {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int deltaR[]={-1,0,1,0};
        int deltaC[]={0,1,0,-1};
        while(!q.empty()) {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int l=q.front().second;

            q.pop();
            
            res[r][c]=l;
            for(int i=0;i<4;i++) {
                int newR=r+deltaR[i];
                int newC=c+deltaC[i];

                if(newR>=0 && newR<m && newC>=0 && newC<n && !vis[newR][newC]) {
                q.push({{newR,newC},l+1});
                vis[newR][newC]=1;
            }
            }
            
        }
        return res;

    }
};
