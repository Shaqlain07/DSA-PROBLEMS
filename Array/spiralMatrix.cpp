class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ans;
        //boundary for matrix
        int rs=0;
        int re=m.size()-1;
        int cs=0;
        int ce=m[0].size()-1;
        //direction to print
        int dir=0;

        while(rs<=re && cs<=ce) {
            //move left to right..rs
            if(dir==0) {
                for(int i=cs;i<=ce;i++) {
                    ans.push_back(m[rs][i]);
                }
                rs+=1;
            }
            //top to bottom
            else if(dir==1) {
                for(int i=rs;i<=re;i++) {
                    ans.push_back(m[i][ce]);
                }
                ce-=1;
            }
            //right to left
            else if(dir==2) {
                for(int i=ce;i>=cs;i--) {
                    ans.push_back(m[re][i]);
                }
                re-=1;
            }
            //bottom to top
            else if(dir==3) {
                for(int i=re;i>=rs;i--) {
                    ans.push_back(m[i][cs]);
                }
                cs+=1;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};
