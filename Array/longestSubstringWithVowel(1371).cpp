class Solution {
public:
    int findTheLongestSubstring(string s) {
        //unordered_set<char> st={'a','e','i','o','u'};
        unordered_map<int,int> mp;//this will map the bit with index
        mp[0]=-1;//initial bit is set to 0 with index -1
        int cnt=0;//bit
        int ans=0;//stores the maximum length of substring

        for(int i=0;i<s.length();i++) {

            //check it is vowel and flip the bit
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                cnt=cnt^(1<<((int)(s[i]-'a')));
            }
            if(mp.find(cnt)!=mp.end()) {
                ans=max(ans,i-mp[cnt]);
            }
            else {
                mp[cnt]=i;
            }
        }
        return ans;


    }
};
