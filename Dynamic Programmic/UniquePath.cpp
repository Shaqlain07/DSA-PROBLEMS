class Solution {
public:
    int helper(int m,int n,int a,int b,vector<vector<int>> &pathVal) {
        //base case
        if(a==m-1 && b==n-1) return 1;
        //visited earlier
        if(pathVal[a][b]!=-1) {
            return pathVal[a][b];
        }
        //calculate , save and return
        int ans=0;
        if(a<m-1) {
            ans+=helper(m,n,a+1,b,pathVal);
        }
        if(b<n-1) {
            ans+=helper(m,n,a,b+1,pathVal);
        }
        //save and return
        pathVal[a][b]=ans;
        return ans;
    }
    int uniquePaths(int m, int n) {
        //create 2-d array and initialise it as -1
        vector<vector<int>> pathVal={};
        
        for(int i=0;i<m;i++){
            vector<int> temp(n,-1);
            pathVal.push_back(temp);
        }
        return helper(m,n,0,0,pathVal);
    }
};
