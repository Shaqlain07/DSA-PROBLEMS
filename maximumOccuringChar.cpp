class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        unordered_map<char,int> mp;
        int mx=-1;//index of element having maximum occurance
        for(int i=0;i<str.length();i++) {
            if(mp.count(str[i])==0) {//not maped then map it
                mp[str[i]]=1;
            }
            else {
                mp[str[i]]++;//increment the mapped value
            }
            //checking for maximmum occurance
            if(i==0) {//first value
                mx=i;
            }
            else {
                if(mp[str[i]]>mp[str[mx]]) {
                    mx=i;//update
                }
                else if(mp[str[i]]==mp[str[mx]]) {
                    if(str[i] < str[mx]) {//lexicographical comaparison
                        mx=i;
                    }
                    else {
                        mx=mx;
                    }
                }
            }
        }
        return str[mx];
    }

};
