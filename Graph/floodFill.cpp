class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>> vis,int col) {
        vis[sr][sc]=1;
        
        int m=image.size();
        int n=image[0].size();
        if(sr+1>=0 && sr+1<m && sc<n && sc>=0 && vis[sr+1][sc]!=1 && image[sr][sc]==image[sr+1][sc]) {
            dfs(sr+1,sc,image,vis,col);
        }
        if(sr-1>=0 && sr-1<m && sc<n && sc>=0 && vis[sr-1][sc]!=1 && image[sr][sc]==image[sr-1][sc]) {
            dfs(sr-1,sc,image,vis,col);
        }
        if(sr>=0 && sr<m && sc-1<n && sc-1>=0 && vis[sr][sc-1]!=1 && image[sr][sc]==image[sr][sc-1]) {
            dfs(sr,sc-1,image,vis,col);
        }
        if(sr>=0 && sr<m && sc+1<n && sc+1>=0 && vis[sr][sc+1]!=1 && image[sr][sc]==image[sr][sc+1]) {
            dfs(sr,sc+1,image,vis,col);
        }
        image[sr][sc]=col;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        dfs(sr,sc,image,vis,color);
        return image;
    }
};
