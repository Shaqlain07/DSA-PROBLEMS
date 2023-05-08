class Solution {
public:
    //Two-pointer
    bool isSubsequence(string s, string t) {
        int j=0;
        for(int i=0;i<t.size() && j<s.size();i++) {
            if(t[i]==s[j]) {
                j++;
            }
        }
        if(j==s.size()) {
            return true;
        }
        return false;
    }
};
