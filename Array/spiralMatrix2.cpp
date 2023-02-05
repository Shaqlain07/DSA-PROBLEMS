class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //ans vecotr
        vector<vector<int>> ans(n, vector<int>(n,0));
        //boundary
        int rs=0;
        int re=n-1;
        int cs=0;
        int ce=n-1;
        //direction
        int dir=0;
        int cnt=1;
        int total=n*n;
        while(cnt<=total) {
            //left to right
            if(dir==0) {
                for(int i=cs;i<=ce;i++) {
                    ans[rs][i]=cnt;
                    cnt++;
                }
                rs+=1;
            }
            //top to bottom
            else if(dir==1) {
                for(int i=rs;i<=re;i++) {
                    ans[i][ce]=cnt;
                    cnt++;
                }
                ce-=1;
            }
            //right to left
            else if(dir==2) {
                for(int i=ce;i>=cs;i--) {
                    ans[re][i]=cnt;
                    cnt++;
                }
                re-=1;
            }
            //bottom to top
            else if(dir==3) {
                for(int i=re;i>=rs;i--) {
                    ans[i][cs]=cnt;
                    cnt++;
                }
                cs+=1;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }

};
