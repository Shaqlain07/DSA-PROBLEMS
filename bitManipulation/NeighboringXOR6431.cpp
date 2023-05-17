class Solution {
public:
    bool solve(int i,vector<int> &original,vector<int> &derived) {
        if(i==derived.size()) {
            if((original[derived.size()-1]^original[0])==derived[derived.size()-1]) return true;
            return false;
        }
        if(i==0) {
            original[i]=0;
            bool a=solve(i+1,original,derived);
            original[i]=1;
            bool b=solve(i+1,original,derived);
            return a||b;
        }
        else {
            original[i]=original[i-1]^derived[i-1];
            return solve(i+1,original,derived);
        }
    }
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> original(n);
        return solve(0,original,derived);
    }
};
