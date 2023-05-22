class Solution {
public:
    bool check(string s,int i,int currS,int totalS,int n) {
        //base case
        if(i==s.size()) {
            totalS+=currS;
            if(totalS==n) {
                return true;
            }
            return false;
        }
        
        //partition
        int tempTotal=totalS+currS;
        int tempCurr=s[i]-'0';
        bool a=check(s,i+1,tempCurr,tempTotal,n);
        //continuous
        currS=(currS*10)+(s[i]-'0');
        bool b=check(s,i+1,currS,totalS,n);
        return a||b;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++) {
            int sqt=i*i;
            string s=to_string(sqt);
            if(check(s,0,0,0,i)) {
                ans+=sqt;
            }
        }
        return ans;
    }
};
