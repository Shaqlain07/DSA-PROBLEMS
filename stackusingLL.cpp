// stack using linkedlist
#include <iostream>
using namespace std;

template <typename T>
class Node // this class create  node for every element push
{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this->data=data;
        next=NULL;
    }

};
template <typename T>
class stack {
    Node<T> *head; //pointed to latest node
    int size; //iterator for no of node

    public:

    stack() { //constructor for initialising data member
        head=NULL;
        size=0;
    }
    int getsize() {
        return size;
    }
    bool isEmpty() {
        return size==0;
    }
    void push(T element) {
        Node<T> *newNode = new Node<T>(element);
        newNode-> next = head;
        head=newNode;
        size++;
    }
    T pop() {
        if (isEmpty())
        {
            return 0;
        }
        T ans=head->data; // data of latest node
        Node<T> *temp=head;
        head=head->next; // iterating furthur
        delete temp;
        size--;
        return ans;        
    }
    T top() {
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
};
int main() {
    stack<int> s1;

    s1.push(100);
    s1.push(101);
    s1.push(102);
    s1.push(103);
    s1.push(104);

    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;

    cout<<s1.getsize()<<endl;
    cout<<s1.isEmpty()<<endl;

    return 0;
}