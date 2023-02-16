#define mod 1000000007
class Solution {
public:
    //global variable
    
    
    long long totalPath;
    int m,n;
    //fn return no increasing path starting from that cell
    int solve(vector<vector<int>> &grid,int i,int j,int prev,vector<vector<int>> &helper) {
        //edge case where there is no increasing path
        if(i<0 || j<0||i>=m||j>=n||grid[i][j]<=prev) return 0;
        //check it is saved in helper
        if(helper[i][j]!=0) return helper[i][j];
        int a=solve(grid,i+1,j,grid[i][j],helper);
        int b=solve(grid,i-1,j,grid[i][j],helper);
        int c=solve(grid,i,j+1,grid[i][j],helper);
        int d=solve(grid,i,j-1,grid[i][j],helper);
        return helper[i][j]=1+(a+b+c+d)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        totalPath=0;
         m=size(grid),n=size(grid[0]);
        vector<vector<int>> helper(m,vector<int>(n,0));//save no of path starting from that cell
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                totalPath+=solve(grid,i,j,-1,helper);
            }
        }
        return totalPath%mod;
    }
};
