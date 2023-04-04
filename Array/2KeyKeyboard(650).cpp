class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        string curr="A";
        curr+="A";
        int cnt=2;
        string copy="A";
        while(curr.size()!=n) {
            int x=curr.size();
            if(n%x==0) {
                copy=curr;
                curr+=copy;
                cnt+=2;
            }
            else {
                curr+=copy;
                cnt+=1;
            }
        }
        return cnt;
    }
};
