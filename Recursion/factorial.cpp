// code for factorial of a number
#include<iostream>
using namespace std;

void factorial(int n,int sol) {
    // base case
    if(n==1){
        cout<<sol;
        return;
    }
    sol=n*sol;
    factorial(n-1,sol); // recursive call
}

int main() {
    int n;
    cout<<"Enter the number:"<<endl;
    cin>>n;

    factorial(n,1);
    return 0;
}
