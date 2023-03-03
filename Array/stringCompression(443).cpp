class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        int i=0;
        while(i<chars.size()) {
            s+=chars[i];
            int c=1;
            while(i<chars.size()-1 && chars[i]==chars[i+1]) {
                c++;
                i++;
            }
            if(c!=1) {
                s+=to_string(c);
            }
            i++;
        }
        chars.clear();
        while(!s.empty()) {
            chars.push_back(s[0]);
            s.erase(0,1);
        }
        return chars.size();
    }
};
