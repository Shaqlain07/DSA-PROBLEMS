vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 vector<long long> v;
                
                                                 for( int i=0;i<=N-K;i++) {
                                                      int flag=-1;
                                                      int j=i;
                                                      int count=0;
                                                     while(count<K) {
                                                         if(A[j]<0) {
                                                             v.push_back(A[j]);
                                                             flag=0;
                                                             break;
                                                         }
                                                         count++;
                                                         j++;
                                                     }
                                                     if(flag!=0) {
                                                         v.push_back(0);
                                                     }
                                                 }
                                                 return v;
                                                 
 }
