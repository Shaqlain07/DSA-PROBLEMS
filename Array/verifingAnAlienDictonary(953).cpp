class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        //set the alien order in the ABCD order
        vector<int> v(26,0);
        for(int i=0;i<v.size();i++) {
            v[order[i]-'a']=i;
        }
        for(int i=0;i<words.size()-1;i++) {
            string w1=words[i];
            string w2=words[i+1];
            int len=min(w1.size(),w2.size());
            for(int j=0;j<len;j++) {
                if(v[w1[j]-'a']>v[w2[j]-'a']) {
                    return false;
                }
                else if(v[w1[j]-'a']<v[w2[j]-'a']) break;
                else if(j==len-1 && j!=w1.size()-1) return false;
            }
        }
            return true;
        }
    
};
