class Solution {
public:
    string longestPalindrome(string s) {
        int len=0;
        string ans="";
        for(int i=0;i<s.length();i++) {
            //odd length
            int l=i;
            int r=i;
            while(l>=0 && r<s.length() && s[l]==s[r]) {
                if(r-l+1>len) {
                    ans=s.substr(l,r-l+1);
                    len=r-l+1;
                }
                l-=1;
                r+=1;
            }
            //even length
            l=i;
            r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]) {
                if(r-l+1>len) {
                    ans=s.substr(l,r-l+1);
                    len=r-l+1;
                }
                l-=1;
                r+=1;
            }
        }
        return ans;
    }
};
