class Solution {
public:
    int solve(vector<int>& bloomDay, int mid,int k) {
        int c=0;
        int b=0;
        for(int i=0;i<bloomDay.size();i++) {
            if(bloomDay[i]<=mid) {
                c++;
            }
            else {
                int temp=c/k;
                b+=temp;
                c=0;
            }
        }
        int temp=c/k;
        b+=temp;
        return b;
    }
	int minDays(vector<int>& bloomDay, int m, int k) {
		// Your code goes here
        int n=bloomDay.size();
        long long t=m*1ll *k*1ll;
        if(n<t) return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());

        while(l<r) {
            int mid=(r+l)/2;
            int b=solve(bloomDay,mid,k);
            if(b>=m) {
                r=mid;
            }
            else {
                l=mid+1;
            }
        }
        return l;
	}
};
