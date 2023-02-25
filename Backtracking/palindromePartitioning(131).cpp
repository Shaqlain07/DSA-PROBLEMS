class Solution {
public:
    bool isPalindrome(string s,int i,int j) {
        if(i==j) return true;
        while(i<j) {
            if(s[i]!=s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,vector<string> curr,vector<vector<string>> &res,int i) {
        //base case
        if(i>=s.size()) {
            res.push_back(curr);
            return;
        }
        for(int j=i;j<s.size();j++) {
            //check for palindrome
            if(isPalindrome(s,i,j)) {
                curr.push_back(s.substr(i,j-i+1));
                solve(s,curr,res,j+1);
                //now we need to pop back
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        solve(s,curr,res,0);
        return res;
    }
};
