// stack using array
#include<iostream>
using namespace std;

template <typename T>
class stackarray {
    T *data;
    int nextIndex;
    int capacity;

    public:
    stackarray (int totalsize){
        data=new T[totalsize]; //array dycalaring dynamically
        nextIndex=0;
        capacity=totalsize;
    }
    int size(){ // No of element present in stack
        return nextIndex;
    }
    bool isEmpty(){
        if(nextIndex==0){
            return true;
        }
        else{
            return false;
        }
    }
    void push(T element){
        if(nextIndex==capacity){
            cout<<"stack full"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    T pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};

int main(){
    stackarray<int> p1(4);

    p1.push(10);
    p1.push(20);
    p1.push(30);
    p1.push(40);
    p1.push(50);

    cout<<p1.top()<<endl;

    cout<<p1.pop()<<endl;
    cout<<p1.pop()<<endl;
    cout<<p1.pop()<<endl;

    cout<<p1.size()<<endl;
    cout<<p1.isEmpty()<<endl;

    return 0;
}