class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        for(int i=0;i<queries.size();i++) {
            int a1=queries[i][0];
            int b1=queries[i][1];
            int edge=0;
            while(a1!=b1) {
                if(a1>b1) {
                    a1/=2;
                    edge++;
                }
                else {
                    b1/=2;
                    edge++;
                }
            }
            res[i]=edge+1;
        }
        return res;
    }
};
