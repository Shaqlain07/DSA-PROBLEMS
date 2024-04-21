class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // first we will find the longest common subsequence length
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1));
        for(int i=1;i<=str1.size();i++) {
            for(int j=1;j<=str2.size();j++) {
                if(str1[i-1]==str2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int len=dp[str1.size()][str2.size()];
        int i=str1.size();
        int j=str2.size();
        string ans="";
        
        while(i>0 && j>0) {
            if(str1[i-1]==str2[j-1]) {
                ans+=str1[i-1];
                i--;
                j--;
              
            }
            else if(dp[i-1][j]>dp[i][j-1]) {
                ans+=str1[i-1];
             
                i--;
            }
            else {
                ans+=str2[j-1];
             
                j--;
            }
        }
        while(i>0) {
            ans+=str1[i-1];
            i--;
            
        }
        while(j>0) {
            ans+=str2[j-1];
            j--;
          
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
