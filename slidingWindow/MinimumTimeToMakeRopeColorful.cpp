class Solution {
public:
    int minCost(string col, vector<int>& Time) {
        int st=0;
        int res=0;
        for(int en=0;en<col.length();en++) {
            if(col[st]!=col[en]) {
                int win=en-st;
                // find min time to remove win-1 ballon
                if(win>1) {
                    // find totol time of window
                    int tm=0;
                    for(int i=st;i<en;i++) {
                        tm+=Time[i];
                    }
                    int mn=INT_MAX;
                    for(int i=st;i<en;i++) {
                        int keep=tm-Time[i];
                        mn=min(mn,keep);
                    }
                    res+=mn;
                }
                st=en;
            }
        }
        int en=col.size();
        int win=en-st;
                // find min time to remove win-1 ballon
                if(win>1) {
                    // find totol time of window
                    int tm=0;
                    for(int i=st;i<en;i++) {
                        tm+=Time[i];
                    }
                    int mn=INT_MAX;
                    for(int i=st;i<en;i++) {
                        int keep=tm-Time[i];
                        mn=min(mn,keep);
                    }
                    res+=mn;
                }
                return res;
    }
};
