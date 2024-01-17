class Solution {
public:
    int minSteps(string s, string t) {
        // mark the freq of both string in map
        unordered_map<char,int> mpS;
        unordered_map<char,int> mpT;

        for(int i=0;i<s.length();i++) {
            mpS[s[i]]++;
        }
        for(int i=0;i<t.length();i++) {
            mpT[t[i]]++;
        }
        // iterate on s and match with t
        int res=0;
        for(auto it=mpS.begin();it!=mpS.end();it++) {
            char ch=it->first;
            if(mpT.find(ch)!=mpT.end()) {
                if(mpT[ch]<=mpS[ch]) {
                    res+=mpS[ch]-mpT[ch];
                }
            }
            else {
                res+=mpS[ch];
            }
            
        }
        return res;
    }
};
