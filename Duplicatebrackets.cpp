// Find the duplicate brackets from the expression..assuming balanced parenthesis
#include<iostream>
#include<stack>
using namespace std;

bool duplicateexp(string s) {
    stack<char> s1;

    for(char ch:s ) {
        
        if(ch=')'){

            char first=s1.top();
            s1.pop();
            int elementinside=0; // element present in stack
            
            while(first!='(') {
                elementinside++;
                first=s1.top();
                s1.pop();
                
            }
            if(elementinside<=1){
                return true;
            }    
        }
        else{
            s1.push(ch);
        }
    }
    return false;
}
int main() {
    string exp= "(((a+(b))+(c+d)))";

    if(duplicateexp(exp)) {
        cout<<"Duplicate found!"<<endl;
    }
    else{
        cout<<"No duplicate found!"<<endl;
    }
    return 0;
}