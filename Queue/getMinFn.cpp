class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty()) {
               return -1;
           }
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty()) {//edge case
               return -1;
           }
           int p=s.top();
           if(p > minEle) {//No need to update minEle
               s.pop();    
               return p;
           }
           else {//top is less than minEle,its a flag
                int temp=minEle;//it is top
                minEle=2*minEle-p;//update minEle..previous minEle while pushing
                s.pop();
                return temp;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()) {
               s.push(x);
               minEle=x;
           }
           else {
               if(x >= minEle) {
                   s.push(x);
               }
               else {//update min ele
                   s.push(2*x-minEle);//its a flag..and its value is stored in minEle
                   minEle=x;
               }
           }
       }
};
