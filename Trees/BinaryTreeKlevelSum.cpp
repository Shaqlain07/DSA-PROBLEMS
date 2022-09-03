class Solution {
  public:
    int kLevelSum(int K, string S) {
        // code here
        int sum=0;
        int level=-1;
        for(int i=0;i<S.length();i++) {
            if(S[i]=='(') {
                level++;
            }
            else if(S[i]==')') {
                level--;
            }
            else { // we got in integer
                if(level==K) {
                    int num=0;
                    while(S[i]!=')' && S[i]!='(') { //until it has only integer
                        num=num*10+S[i]-'0';
                        i++;
                    }
                    i--; //for extra increment
                    sum+=num;
                }
            }
        }
        return sum;
    }
