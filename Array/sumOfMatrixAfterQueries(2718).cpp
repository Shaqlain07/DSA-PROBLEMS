class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long total=0;
        int r=0;
        int c=0;
        unordered_map<int,int> mpr,mpc;
        for(int i=queries.size()-1;i>=0;i--) {
            if(queries[i][0]==1) {
                int idx=queries[i][1];
                if(mpc.find(idx)==mpc.end()) {
                    c++;
                    mpc[idx]++;
                    total+=(n-r)*queries[i][2];    
                }
                
            }
            else {
                int itr=queries[i][1];
                if(mpr.find(itr)==mpr.end()) {
                    r++;
                    mpr[itr]++;
                    total+=(n-c)*queries[i][2];
                }
            }
        }
        return total;
    }
};
