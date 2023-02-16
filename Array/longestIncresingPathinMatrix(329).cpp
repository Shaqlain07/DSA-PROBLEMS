class Solution {
public:
    int helper[200][200];
    int maxPath,n,m;
    //fn return max path starting from that cell
    int solve(vector<vector<int>> &matrix,int i,int j,int prev) {
        //edge case where we can not move
        if(i<0 || j<0 || i>=n ||j>=m || matrix[i][j]<=prev) return 0;
        //check in helper if it is calculated earlier
        if(helper[i][j]) return helper[i][j];
        //calculate,save and return
        return helper[i][j]=1+max({solve(matrix,i+1,j,matrix[i][j]),
                                    solve(matrix,i-1,j,matrix[i][j]),
                                    solve(matrix,i,j+1,matrix[i][j]),
                                    solve(matrix,i,j-1,matrix[i][j])});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxPath=0,n=size(matrix),m=size(matrix[0]);
        //iterate on matrix
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                maxPath=max(maxPath,solve(matrix,i,j,-1));
            }
        }
        return maxPath;    
    }

};
