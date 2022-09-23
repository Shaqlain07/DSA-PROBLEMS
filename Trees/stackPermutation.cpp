class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> a;
        int j=0;//iteration for B
        for(int i=0;i<N;i++) {
            a.push(A[i]);
            while(!a.empty() && a.top()==B[j]) {
                a.pop();
                j++;
            }
        }
        if(a.empty()) {
            return 1;
        }
        else {
            return 0;
        }
    }
};
