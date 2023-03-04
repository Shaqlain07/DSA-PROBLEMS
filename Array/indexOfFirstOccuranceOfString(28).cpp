class Solution {
public:
    int strStr(string haystack, string needle) {
        int res=-1;
        int i=0;
        while(i<haystack.size()) {
            if(haystack[i]==needle[0]) {
                int j=1;
                int k=i+1;
                while(j<needle.size() && haystack[k]==needle[j]) {
                    k++;
                    j++;
                }
                if(j==needle.size()) {
                    res=i;
                    break;
                }
            }
            i++;
        }
        return res;
    }
};
