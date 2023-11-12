int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    //works only for positive and 0s
    int s=0;
    int e=0;
    long long sum=a[0];
    int len=0;

    while(e<a.size()) {
        //if our sum exceeds k
        //trim from s till <=k
        while(s<=k && sum>k) {
            sum-=a[s];
            s++;
        }
        //if our sum equals to k
        if(sum==k) {
            len=max(len,e-s+1);
        }
        e++;
        if(e<a.size()) sum+=a[e];
    }
    return len;
}
